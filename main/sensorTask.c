#include "sensorTask.h"

static const char *TAG = "sensorTask.c";

gptimer_handle_t sensorTimerHandle = NULL;
static TaskHandle_t xSensorTaskHandle = NULL;
SemaphoreHandle_t xSemaphore = NULL;


static bool IRAM_ATTR sensor_cb(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data)
{
    BaseType_t high_task_awoken = pdFALSE;

    xSemaphoreGiveFromISR( xSemaphore, &high_task_awoken );
    // return whether we need to yield at the end of ISR
    return (high_task_awoken == pdTRUE);
}


// Task to be created.
void vSensorTask( void * pvParameters )
{
	    
	xSemaphore = xSemaphoreCreateBinary();    
	    
    gptimer_config_t timer_config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .resolution_hz = 1000000, // 1MHz, 1 tick=1us
    };
    ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &sensorTimerHandle));
    
    gptimer_event_callbacks_t cbs = {
        .on_alarm = sensor_cb,
    };
    ESP_ERROR_CHECK(gptimer_register_event_callbacks(sensorTimerHandle, &cbs, NULL));
    
    ESP_LOGI(TAG, "Enable Sensor timer");
    ESP_ERROR_CHECK(gptimer_enable(sensorTimerHandle));
    
    gptimer_alarm_config_t alarm_config1 = {
        .reload_count = 0,
        .alarm_count = 6000000, // period = 6s
        .flags.auto_reload_on_alarm = true,
    };
    ESP_ERROR_CHECK(gptimer_set_alarm_action(sensorTimerHandle, &alarm_config1));
	
	vTaskDelay(500 / portTICK_PERIOD_MS);
	
	
	
	for( ;; )
	{
		if( xSemaphoreTake( xSemaphore, pdMS_TO_TICKS(6000) ) == pdTRUE ) {
			ESP_LOGI(TAG, "Sensor 0x%04hx", my_tent.thermometer_short_addr);
		
            esp_zb_zcl_read_attr_cmd_t cmd_req;
            cmd_req.zcl_basic_cmd.dst_addr_u.addr_short = my_tent.thermometer_short_addr;
            cmd_req.zcl_basic_cmd.dst_endpoint = 1;
            cmd_req.zcl_basic_cmd.src_endpoint = THERMOMETER_ENDPOINT;
            cmd_req.address_mode = ESP_ZB_APS_ADDR_MODE_16_GROUP_ENDP_NOT_PRESENT;
            cmd_req.clusterID = ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT;
            uint16_t attributes[] = {ESP_ZB_ZCL_ATTR_TEMP_MEASUREMENT_VALUE_ID};
            cmd_req.attr_number = sizeof(attributes) / sizeof(uint16_t);;
            cmd_req.attr_field = attributes;
                                                                     
            esp_zb_zcl_read_attr_cmd_req( &cmd_req);   
            
            
            /*
            esp_zb_zcl_report_attr_cmd_t cmd_req;
            cmd_req.zcl_basic_cmd.dst_addr_u.addr_short = my_tent.thermometer_short_addr;
            cmd_req.zcl_basic_cmd.dst_endpoint = 1;
            cmd_req.zcl_basic_cmd.src_endpoint = THERMOMETER_ENDPOINT;
            cmd_req.address_mode = ESP_ZB_APS_ADDR_MODE_16_ENDP_PRESENT;
            cmd_req.clusterID = ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT;
            cmd_req.cluster_role = ESP_ZB_ZCL_CLUSTER_SERVER_ROLE;
            cmd_req.attributeID = ESP_ZB_ZCL_ATTR_TEMP_MEASUREMENT_VALUE_ID;
            esp_err_t err = esp_zb_zcl_report_attr_cmd_req(&cmd_req); 
            if (err != ESP_OK)
				printf("Error (%s) scl report\n", esp_err_to_name(err));                                                       
             */                                                         
			
			update_displayed_values();
			setFanSpeed();
			
		} else {
			ESP_LOGW(TAG, "Missed 1 count event or Timer stopped");
		}
			
	}
}

// Function that creates a task.
//How to allocate task memory from SPI https://esp32.com/viewtopic.php?t=20660
void vCreateSensorTask( void )
{
  static uint8_t ucParameterToPass;
  xTaskCreatePinnedToCore( vSensorTask, "SENSORTASK", 4096, &ucParameterToPass, 10, &xSensorTaskHandle, 1 );
  configASSERT( xSensorTaskHandle );
}


extern void vDeleteSensorTask( void )
{
  if( xSensorTaskHandle != NULL )
  {
     vTaskDelete( xSensorTaskHandle );
  }

}



