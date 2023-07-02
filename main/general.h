#ifndef GENERAL_H
#define GENERAL_H

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
#include "esp_err.h"
#include "freertos/task.h"
#include "esp_mac.h"

#include "lwip/err.h"
#include "lwip/sys.h"

typedef struct {
    uint8_t event_count;
    uint32_t seconds;
    uint16_t days;
    bool is_day;
    uint32_t day_period_seconds;
} timer_queue_element_t;

extern timer_queue_element_t tenttime;
	

#define LEDC_MODE               LEDC_LOW_SPEED_MODE
//backlight
#define LEDC_BACKLIGHT_TIMER              LEDC_TIMER_0
#define LEDC_BACKLIGHT_OUTPUT_IO          (45) // Define the output GPIO for Backlight
#define LEDC_BACKLIGHT_CHANNEL            LEDC_CHANNEL_0
#define LEDC_BACKLIGHT_DUTY_RES           LEDC_TIMER_7_BIT // Set duty resolution to 13 bits
#define LEDC_BACKLIGHT_FREQUENCY          (10000) // Frequency in Hertz. Set frequency at 5 kHz

//fan pwm
#define LEDC_FAN_TIMER              LEDC_TIMER_1
#define LEDC_FAN_OUTPUT_IO          (10) // Define the output GPIO for Backlight
#define LEDC_FAN_CHANNEL            LEDC_CHANNEL_1
#define LEDC_FAN_DUTY_RES           LEDC_TIMER_7_BIT // Set duty resolution to 10 bits
#define LEDC_FAN_FREQUENCY          (5000) // Frequency in Hertz.

//LED DIMMER pwm
#define LEDC_DIMMER_TIMER              LEDC_TIMER_2
#define LEDC_DIMMER_OUTPUT_IO          (11) // Define the output GPIO for Backlight
#define LEDC_DIMMER_CHANNEL            LEDC_CHANNEL_2
#define LEDC_DIMMER_DUTY_RES           LEDC_TIMER_7_BIT // Set duty resolution to 10 bits
#define LEDC_DIMMER_FREQUENCY          (5000) // Frequency in Hertz.

//gptimer_handle_t gptimer;

void update_temp_units(uint16_t temp_unit);
void ledc_init(void);
void event_loop_init(void);
void wifi_init(void);
void wifi_scan(void);
void wifi_connect(void);
void wifi_off(void);
void update_time_left();

#endif
