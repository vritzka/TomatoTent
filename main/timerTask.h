#include "lvgl.h"
#include "ui.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gptimer.h"
#include "esp_log.h"
#include "general.h"

extern gptimer_handle_t gptimer;
void vTimerTask( void * pvParameters );
void vStartTimerTask( void );
void vStopTimerTask( void );
