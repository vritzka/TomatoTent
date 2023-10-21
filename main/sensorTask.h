#include "lvgl.h"
#include "ui.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gptimer.h"
#include "esp_log.h"
#include "general.h"
#include "esp_zigbee_core.h"
#include "esp_zigbee_gateway.h"
#include "ha/esp_zigbee_ha_standard.h"
#include "esp_err.h"


extern gptimer_handle_t sensorTimerHandle;
void vSensorTask( void * pvParameters );
void vCreateSensorTask( void );
void vDeleteSensorTask( void );
