#include "httpTask.h"

static void http_timer_callback(void* arg);
static esp_timer_handle_t http_timer;

#define MAX_HTTP_RECV_BUFFER 512
#define MAX_HTTP_OUTPUT_BUFFER 2048

static const char* TAG = "HTTP_TASK";

static esp_err_t https_post_request(char url[], char post_data[]);

void create_http_timer(void)
{

    const esp_timer_create_args_t http_timer_args = {
            .callback = &http_timer_callback,
            /* name is optional, but may help identify the timer when debugging */
            .name = "periodicHttpTimer"
    };

    ESP_ERROR_CHECK(esp_timer_create(&http_timer_args, &http_timer));

}

void start_http_timer() {
    /* Start the timer */
    ESP_ERROR_CHECK(esp_timer_start_periodic(http_timer, 5000000)); //5 seconds
    ESP_LOGI(TAG, "Started HTTP timer");
}

void stop_http_timer() {
    ESP_ERROR_CHECK(esp_timer_stop(http_timer));
}
/*
char post_data[] = [
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.air_temperature",
    "interval": 60,
    "value": {{{air_temperature}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.air_humidity",
    "interval": 60,
    "value": {{{air_humidity}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.soil_capacitance",
    "interval": 60,
    "value": {{{soil_capacitance}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.soil_moisture",
    "interval": 60,
    "value": {{{soil_moisture}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.soil_temperature",
    "interval": 60,
    "value": {{{soil_temperature}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.grow_days",
    "interval": 60,
    "value": {{{grow_days}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.light_on",
    "interval": 60,
    "value": {{{light_on}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.light_period",
    "interval": 60,
    "value": {{{light_period}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.period_progress",
    "interval": 60,
    "value": {{{period_progress}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.fan_auto",
    "interval": 60,
    "value": {{{fan_auto}}},
    "time": {{{time}}}
},
{
    "name": "devices.{{{PARTICLE_DEVICE_ID}}}.fan_speed",
    "interval": 60,
    "value": {{{fan_speed}}},
    "time": {{{time}}}
}];
*/

static void http_timer_callback(void* arg)
{
    int64_t time_since_boot = esp_timer_get_time();
    ESP_LOGI(TAG, "Periodic timer called, time since boot: %lld us", time_since_boot);

    time_t now;
    char strftime_buf[64];
    struct tm timeinfo;

    time(&now);
    // Set timezone to China Standard Time
    setenv("TZ", "CST-8", 1);
    tzset();

    localtime_r(&now, &timeinfo);
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    ESP_LOGI(TAG, "The current date/time in Shanghai is: %s", strftime_buf);

    cJSON *air_temperature;

    air_temperature=cJSON_CreateObject();
    char air_temperature_str[200];
    sprintf(air_temperature_str,"devices.%s.air_temperature", my_tent.device_id);
    cJSON_AddItemToObject(air_temperature, "name", cJSON_CreateString(air_temperature_str));

    cJSON_AddNumberToObject(air_temperature,"interval",	60);
    cJSON_AddNumberToObject(air_temperature,"value", my_tent.temperature_c);
    cJSON_AddNumberToObject(air_temperature,"time", now);

    char *rendered=cJSON_Print(air_temperature);
    ESP_LOGI(TAG, "JSON: %s", rendered);


    //sprintf(post_data, "{\"email\":\"%s\"}", "my_system.sign_in_que_2");
    //ESP_LOGI(TAG, "Trying to post %s", post_data);
/*
    esp_err_t res = https_post_request("https://graphite-blocks-prod-us-central1.grafana.net/graphite/metrics", post_data);   

    if(res == ESP_OK) {
        ESP_LOGI(TAG, "Successfully posted %s", post_data);
    }
*/

}

static esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    static char *output_buffer;  // Buffer to store response of http request from event handler
    static int output_len;       // Stores number of bytes read
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
            break;
        case HTTP_EVENT_ON_DATA:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            // Clean the buffer in case of a new request
            if (output_len == 0 && evt->user_data) {
                // we are just starting to copy the output data into the use
                memset(evt->user_data, 0, MAX_HTTP_OUTPUT_BUFFER);
            }
            /*
             *  Check for chunked encoding is added as the URL for chunked encoding used in this example returns binary data.
             *  However, event handler can also be used in case chunked encoding is used.
             */
            if (!esp_http_client_is_chunked_response(evt->client)) {
                // If user_data buffer is configured, copy the response into the buffer
                int copy_len = 0;
                if (evt->user_data) {
                    // The last byte in evt->user_data is kept for the NULL character in case of out-of-bound access.
                    copy_len = MIN(evt->data_len, (MAX_HTTP_OUTPUT_BUFFER - output_len));
                    if (copy_len) {
                        memcpy(evt->user_data + output_len, evt->data, copy_len);
                    }
                } else {
                    int content_len = esp_http_client_get_content_length(evt->client);
                    if (output_buffer == NULL) {
                        // We initialize output_buffer with 0 because it is used by strlen() and similar functions therefore should be null terminated.
                        output_buffer = (char *) calloc(content_len + 1, sizeof(char));
                        output_len = 0;
                        if (output_buffer == NULL) {
                            ESP_LOGE(TAG, "Failed to allocate memory for output buffer");
                            return ESP_FAIL;
                        }
                    }
                    copy_len = MIN(evt->data_len, (content_len - output_len));
                    if (copy_len) {
                        memcpy(output_buffer + output_len, evt->data, copy_len);
                    }
                }
                output_len += copy_len;
            }

            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
            if (output_buffer != NULL) {
#if CONFIG_EXAMPLE_ENABLE_RESPONSE_BUFFER_DUMP
                ESP_LOG_BUFFER_HEX(TAG, output_buffer, output_len);
#endif
                free(output_buffer);
                output_buffer = NULL;
            }
            output_len = 0;
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            int mbedtls_err = 0;
            esp_err_t err = esp_tls_get_and_clear_last_error((esp_tls_error_handle_t)evt->data, &mbedtls_err, NULL);
            if (err != 0) {
                ESP_LOGI(TAG, "Last esp error code: 0x%x", err);
                ESP_LOGI(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
            }
            if (output_buffer != NULL) {
                free(output_buffer);
                output_buffer = NULL;
            }
            output_len = 0;
            break;
        case HTTP_EVENT_REDIRECT:
            ESP_LOGD(TAG, "HTTP_EVENT_REDIRECT");
            esp_http_client_set_header(evt->client, "From", "user@example.com");
            esp_http_client_set_header(evt->client, "Accept", "text/html");
            esp_http_client_set_redirection(evt->client);
            break;
    }
    return ESP_OK;
}

static esp_err_t https_post_request(char url[], char post_data[])
{
    
    esp_http_client_config_t config = {
        .url = url,
        .event_handler = _http_event_handler,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .is_async = true,
        .timeout_ms = 5000,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_err_t err;
    esp_http_client_set_method(client, HTTP_METHOD_POST);
    esp_http_client_set_post_field(client, post_data, strlen(post_data));
    esp_http_client_set_header(client, "Content-Type", "application/json");
    while (1) {
        err = esp_http_client_perform(client);
        if (err != ESP_ERR_HTTP_EAGAIN) {
            break;
        }
    }
    if (err == ESP_OK) {
        ESP_LOGI(TAG, "HTTPS Status = %d, content_length = %"PRId64,
                esp_http_client_get_status_code(client),
                esp_http_client_get_content_length(client));
    } else {
        ESP_LOGE(TAG, "Error perform http request %s", esp_err_to_name(err));
    }
    return err;
    esp_http_client_cleanup(client);

}