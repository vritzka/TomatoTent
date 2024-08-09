#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_spiffs.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"
#include "ui/ui.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"

#include "guiTask.h"
#include "timerTask.h"
#include "otaTask.h"
#include "sensorTask.h"
#include "httpTask.h"
#include "general.h"
#include "esp_zigbee_gateway.h"


static const char *TAG = "main.c";

void heap_caps_alloc_failed_hook(size_t requested_size, uint32_t caps, const char *function_name)
{
  printf("%s was called but failed to allocate %d bytes with 0x%lX capabilities. \n",function_name, requested_size, caps);
}

void app_main(void)
{
	heap_caps_register_failed_alloc_callback(heap_caps_alloc_failed_hook);
	
	 // Initialize NVS
    esp_err_t err = nvs_flash_init();
    ESP_LOGI(TAG,"Opened NVS");
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition was truncated and needs to be erased
        // Retry nvs_flash_init
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
   ESP_ERROR_CHECK( err );
   
   init_i2c();
   event_loop_init();
   init_ledc();
   vStartGuiTask();
   vStartTimerTask();
   vCreateSensorTask();
   create_http_timer();
   //vCreateZigbeeTask();
}
