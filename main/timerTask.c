#include "timerTask.h"

static const char *TAG = "timerTask.c";

TaskHandle_t xTimerTaskHandle = NULL;


gptimer_handle_t gptimer = NULL;

static bool IRAM_ATTR example_timer_on_alarm_cb_v1(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data)
{
    BaseType_t high_task_awoken = pdFALSE;
    QueueHandle_t queue = (QueueHandle_t)user_data;

    // Retrieve count value and send to queue
    tenttime.event_count = edata->count_value;
    
    if(tenttime.seconds == 59) {
		tenttime.seconds = 0;
		tenttime.minutes = tenttime.minutes+1;
	} else {
		tenttime.seconds = tenttime.seconds+1;
	}
    
    xQueueSendFromISR(queue, &tenttime, &high_task_awoken);
    // return whether we need to yield at the end of ISR
    return (high_task_awoken == pdTRUE);
}

// Task to be created.
void vTimerTask( void * pvParameters )
{
	
	QueueHandle_t queue = xQueueCreate(10, sizeof(timer_queue_element_t));
    if (!queue) {
        ESP_LOGE(TAG, "Creating queue failed");
        return;
    }
	    
    gptimer_config_t timer_config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .resolution_hz = 1000000, // 1MHz, 1 tick=1us
    };
    ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer));
    
    gptimer_event_callbacks_t cbs = {
        .on_alarm = example_timer_on_alarm_cb_v1,
    };
    ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer, &cbs, queue));
    
    ESP_LOGI(TAG, "Enable timer");
    ESP_ERROR_CHECK(gptimer_enable(gptimer));
    
    ESP_LOGI(TAG, "Start timer");
    gptimer_alarm_config_t alarm_config1 = {
        .reload_count = 0,
        .alarm_count = 1000000, // period = 1s
        .flags.auto_reload_on_alarm = true,
    };
    ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer, &alarm_config1));
        
    ESP_ERROR_CHECK(gptimer_start(gptimer));
    	
	
	
  for( ;; )
  {
        if (xQueueReceive(queue, &tenttime, pdMS_TO_TICKS(2000))) {
            ESP_LOGI(TAG, "Seconds, count=%d", tenttime.seconds);
            ESP_LOGI(TAG, "Minutes, count=%d", tenttime.minutes);
            update_time_left();
        } else {
            ESP_LOGW(TAG, "Missed one count event");
        }
			
  }
}

// Function that creates a task.
void vStartTimerTask( void )
{
static uint8_t ucParameterToPass;

  xTaskCreatePinnedToCore( vTimerTask, "TIMERTASK", 4096, &ucParameterToPass, 10, &xTimerTaskHandle, 0 );
  configASSERT( xTimerTaskHandle );

  // Use the handle to delete the task.
  /*
  if( xGuiTaskHandle != NULL )
  {
     vTaskDelete( xTimerTaskHandle );
  }
  * */
}

