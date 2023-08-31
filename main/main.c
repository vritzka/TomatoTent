#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
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
#include "general.h"

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
   
   event_loop_init();
   init_ledc();
   init_i2c();
   vStartGuiTask();
   vStartTimerTask();
   vCreateSensorTask();
   

 #if defined(CONFIG_BOOTLOADER_APP_ROLLBACK_ENABLE)
    /**
     * We are treating successful WiFi connection as a checkpoint to cancel rollback
     * process and mark newly updated firmware image as active. For production cases,
     * please tune the checkpoint behavior per end application requirement.
     */
    const esp_partition_t *running = esp_ota_get_running_partition();
    esp_ota_img_states_t ota_state;
    if (esp_ota_get_state_partition(running, &ota_state) == ESP_OK) {
        if (ota_state == ESP_OTA_IMG_PENDING_VERIFY) {
            if (esp_ota_mark_app_valid_cancel_rollback() == ESP_OK) {
                ESP_LOGI(TAG, "App is valid, rollback cancelled successfully");
            } else {
                ESP_LOGE(TAG, "Failed to cancel rollback");
            }
        }
    }
#endif

}
