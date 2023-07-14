#include "lvgl.h"
#include "ui.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gptimer.h"
#include "esp_log.h"
#include "general.h"
#include "includes/scd4x/scd4x.h"

extern gptimer_handle_t sensorTimerHandle;
void vSensorTask( void * pvParameters );
void vCreateSensorTask( void );
void vDeleteSensorTask( void );
