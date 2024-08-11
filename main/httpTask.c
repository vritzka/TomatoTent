#include "httpTask.h"

static void http_timer_callback(void* arg);
static esp_timer_handle_t http_timer;

#define MAX_HTTP_RECV_BUFFER 512
#define MAX_HTTP_OUTPUT_BUFFER 2048

static const char* TAG = "HTTP_TASK";

static esp_err_t https_post_request(char post_data[]);
static esp_err_t _http_event_handler(esp_http_client_event_t *evt);
static esp_http_client_handle_t client;
static esp_err_t err;

static void init_client() {
    esp_http_client_config_t config = {
        .host = "graphite-blocks-prod-us-central1.grafana.net",
        .path = "/graphite/metrics",
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .event_handler = _http_event_handler,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .is_async = true,
        .username = "10495",
        .password = "eyJrIjoiZWUzZDMxNDMzZmFiZWUwY2U2YWMxMDdjYmFjYmIzNDNmODRlODgwNiIsIm4iOiJtZXRyaWNzIHB1c2giLCJpZCI6MzUwMDg5fQ",
        .timeout_ms = 5000,
        .auth_type = HTTP_AUTH_TYPE_BASIC,
    };

    client = esp_http_client_init(&config);
    
    esp_http_client_set_method(client, HTTP_METHOD_POST);
    esp_http_client_set_header(client, "Content-Type", "application/json");
}

void create_http_timer(void)
{

    const esp_timer_create_args_t http_timer_args = {
            .callback = &http_timer_callback,
            /* name is optional, but may help identify the timer when debugging */
            .name = "periodicHttpTimer"
    };

    ESP_ERROR_CHECK(esp_timer_create(&http_timer_args, &http_timer));

    init_client();

}

void start_http_timer() {
    /* Start the timer */
    ESP_ERROR_CHECK(esp_timer_start_periodic(http_timer, 30000000)); //5 seconds
    ESP_LOGI(TAG, "Started HTTP timer");
}

void stop_http_timer() {
    ESP_ERROR_CHECK(esp_timer_stop(http_timer));
}


static void http_timer_callback(void* arg)
{
    if(my_tent.wifi_connected == 0)
        return;
    time_t now;
    time(&now);

    char buf[64];
    cJSON *root,*air_temperature,*air_humidity,*grow_days,*light_on,*light_period,*period_progress,*fan_auto,*fan_speed,*co2;

    root=cJSON_CreateArray();

    air_temperature=cJSON_CreateObject();
    sprintf(buf,"devices.%s.air_temperature", my_tent.device_id);
    cJSON_AddItemToObject(air_temperature, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(air_temperature,"interval",	60);
    sprintf(buf,"%.2f", my_tent.temperature_c);
    cJSON_AddNumberToObject(air_temperature,"value", strtod(buf, NULL));
    cJSON_AddNumberToObject(air_temperature,"time", now);
    root->child=air_temperature;

    air_humidity=cJSON_CreateObject();
    sprintf(buf,"devices.%s.air_humidity", my_tent.device_id);
    cJSON_AddItemToObject(air_humidity, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(air_humidity,"interval",	60);
    cJSON_AddNumberToObject(air_humidity,"value", my_tent.humidity);
    cJSON_AddNumberToObject(air_humidity,"time", now);
    air_temperature->next=air_humidity; 

    co2=cJSON_CreateObject();
    sprintf(buf,"devices.%s.co2", my_tent.device_id);
    cJSON_AddItemToObject(co2, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(co2,"interval",	60);
    cJSON_AddNumberToObject(co2,"value", my_tent.co2);
    cJSON_AddNumberToObject(co2,"time", now);
    air_humidity->next=co2;    

    grow_days=cJSON_CreateObject();
    sprintf(buf,"devices.%s.grow_days", my_tent.device_id);
    cJSON_AddItemToObject(grow_days, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(grow_days,"interval",	60);
    cJSON_AddNumberToObject(grow_days,"value", my_tent.days);
    cJSON_AddNumberToObject(grow_days,"time", now);
    co2->next=grow_days;        

    light_on=cJSON_CreateObject();
    sprintf(buf,"devices.%s.light_on", my_tent.device_id);
    cJSON_AddItemToObject(light_on, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(light_on,"interval", 60);
    sprintf(buf,"%.2f", (float)my_tent.led_brightness_slider_value/100);
    cJSON_AddNumberToObject(light_on,"value", strtod(buf, NULL));
    cJSON_AddNumberToObject(light_on,"time", now);
    grow_days->next=light_on; 

    light_period=cJSON_CreateObject();
    sprintf(buf,"devices.%s.light_period", my_tent.device_id);
    cJSON_AddItemToObject(light_period, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(light_period,"interval", 60);
    cJSON_AddNumberToObject(light_period,"value", my_tent.light_duration*60.0);
    cJSON_AddNumberToObject(light_period,"time", now);
    light_on->next=light_period; 

    period_progress=cJSON_CreateObject();
    sprintf(buf,"devices.%s.period_progress", my_tent.device_id);
    cJSON_AddItemToObject(period_progress, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(period_progress,"interval", 60);
    cJSON_AddNumberToObject(period_progress,"value", my_tent.period_progress/60);
    cJSON_AddNumberToObject(period_progress,"time", now);
    light_period->next=period_progress; 

    fan_auto=cJSON_CreateObject();
    sprintf(buf,"devices.%s.fan_auto", my_tent.device_id);
    cJSON_AddItemToObject(fan_auto, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(fan_auto,"interval", 60);
    my_tent.climate_mode ? cJSON_AddNumberToObject(fan_auto,"value", 0) : cJSON_AddNumberToObject(fan_auto,"value", 1);
    cJSON_AddNumberToObject(fan_auto,"time", now);
    period_progress->next=fan_auto; 

    fan_speed=cJSON_CreateObject();
    sprintf(buf,"devices.%s.fan_speed", my_tent.device_id);
    cJSON_AddItemToObject(fan_speed, "name", cJSON_CreateString(buf));
    cJSON_AddNumberToObject(fan_speed,"interval", 60);
    cJSON_AddNumberToObject(fan_speed,"value", my_tent.fanspeed);
    cJSON_AddNumberToObject(fan_speed,"time", now);
    fan_auto->next=fan_speed; 

    char *rendered=cJSON_Print(root);
    ESP_LOGI(TAG, "JSON: %s", rendered);

    https_post_request(rendered);

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
                ESP_LOG_BUFFER_HEX(TAG, output_buffer, output_len);
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

static esp_err_t https_post_request(char post_data[])
{
     esp_http_client_set_post_field(client, post_data, strlen(post_data));

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
   // esp_http_client_cleanup(client);

}