#include "httpTask.h"

static void http_timer_callback(void* arg);
static esp_timer_handle_t http_timer;

static const char* TAG = "example";

void create_http_timer(void)
{

    const esp_timer_create_args_t http_timer_args = {
            .callback = &http_timer_callback,
            /* name is optional, but may help identify the timer when debugging */
            .name = "periodicHttpTimer"
    };

    ESP_ERROR_CHECK(esp_timer_create(&http_timer_args, &http_timer));
    /* The timer has been created but is not running yet */

    /* Print debugging information about timers to console every 2 seconds */
    for (int i = 0; i < 5; ++i) {
        ESP_ERROR_CHECK(esp_timer_dump(stdout));
    }

}

void start_http_timer() {
    /* Start the timer */
    ESP_ERROR_CHECK(esp_timer_start_periodic(http_timer, 20000000)); //20 seconds
    ESP_LOGI(TAG, "Started HTTP timer, time since boot: %lld us", esp_timer_get_time());
}

void stop_http_timer() {
    ESP_ERROR_CHECK(esp_timer_stop(http_timer));
}

static void http_timer_callback(void* arg)
{
    int64_t time_since_boot = esp_timer_get_time();
    ESP_LOGI(TAG, "Periodic timer called, time since boot: %lld us", time_since_boot);
}