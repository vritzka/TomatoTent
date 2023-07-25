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

#define UART_STACK_SIZE             (4096)
#define TEMPERATURE_OFFSET          (4.0)
#define SENSOR_ALTITUDE             (25.0)

extern gptimer_handle_t sensorTimerHandle;
void vSensorTask( void * pvParameters );
void vCreateSensorTask( void );
void vDeleteSensorTask( void );
