#ifndef GENERAL_H
#define GENERAL_H

#include "lvgl.h"
#include "ui.h"
#include "driver/ledc.h"
#include "driver/i2c.h"
#include "includes/scd4x/scd4x.h"
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
#include "esp_http_client.h"
#include "esp_tls.h"
#include "esp_netif.h"
//#include <float.h> 
#include "lwip/err.h"
#include "lwip/sys.h"

#include "esp_event.h"
#include "esp_crt_bundle.h"
#include "esp_https_ota.h"

typedef struct {
    uint8_t event_count;
    uint32_t seconds;
    uint16_t days;
    bool is_day;
    uint32_t day_period_seconds;
} timer_queue_element_t;

extern timer_queue_element_t tenttime;


typedef struct {
    float temperature_c;
    float temperature_f;
    uint8_t humidity;
    double co2;
} climate_data_t;

extern climate_data_t climate;

#define I2C_MASTER_SDA              (12)
#define I2C_MASTER_SCL              (13)
#define I2C_MASTER_RX_BUF_DISABLE   (0)
#define I2C_MASTER_TX_BUF_DISABLE   (0)
#define I2C_MASTER_FREQ_HZ          (100000)
#define I2C_MASTER_TIMEOUT_MS       (1000)
#define I2C_MASTER_NUM              (1)
#define I2C_ACK_CHECK_DIS           (0x00)
#define I2C_ACK_CHECK_EN            (0x01)
#define I2C_ACK_VAL                 (0x00)
#define I2C_NACK_VAL                (0x01)	

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
void init_ledc(void);
void event_loop_init(void);
void wifi_init(void);
void wifi_scan(void);
void wifi_connect(void);
void wifi_off(void);
void update_time_left(bool count_day);
void make_it_day(bool count_day);
void make_it_night();
void draw_qr_codes();
void readSensors();
void setFanSpeed();
void init_i2c();
void setGrowLampBrightness();
long map(long x, long in_min, long in_max, long out_min, long out_max);

#endif
