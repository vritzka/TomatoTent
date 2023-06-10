#include "lvgl.h"
#include "ui.h"
#include "driver/ledc.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_system.h"
	

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO          (45) // Define the output GPIO
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT // Set duty resolution to 13 bits
#define LEDC_FREQUENCY          (5000) // Frequency in Hertz. Set frequency at 5 kHz


void ledc_init(void);
void event_loop_init(void);
void wifi_on(void);
void wifi_scan(void);
void wifi_off(void);
void wifi_scan_done_handler(void* handler_args, esp_event_base_t base, int32_t id, void* event_data);

