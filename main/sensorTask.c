#include "sensorTask.h"

#define UART_STACK_SIZE             (4096)
#define TEMPERATURE_OFFSET          (4.0)
#define SENSOR_ALTITUDE             (0)

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

char scale = SCALE_CELCIUS;
float temperature = 0.0;
float humidity = 0.0;
float co2_level = 0.0;

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
    
    ESP_LOGI(TAG, "Enable timer");
    ESP_ERROR_CHECK(gptimer_enable(sensorTimerHandle));
    

    gptimer_alarm_config_t alarm_config1 = {
        .reload_count = 0,
        .alarm_count = 5000000, // period = 5s
        .flags.auto_reload_on_alarm = true,
    };
    ESP_ERROR_CHECK(gptimer_set_alarm_action(sensorTimerHandle, &alarm_config1));
    	
	ESP_ERROR_CHECK(gptimer_start(sensorTimerHandle));
	
	ESP_LOGI(TAG, "SCD40 Sensor serial number 0x%012llX", scd4x_get_serial_number());
	vTaskDelay(500 / portTICK_PERIOD_MS);
    float temperature_offset = scd4x_get_temperature_offset();
    vTaskDelay(500 / portTICK_PERIOD_MS);
    uint16_t sensor_altitude = scd4x_get_sensor_altitude();
    
    if(temperature_offset != SCD41_READ_ERROR && sensor_altitude != SCD41_READ_ERROR) {

        if(temperature_offset != TEMPERATURE_OFFSET) {
            ESP_LOGW(TAG, "Temperature offset calibration from %.1f °%c to %.1f °%c", temperature_offset, scale, TEMPERATURE_OFFSET, scale);

            vTaskDelay(500 / portTICK_PERIOD_MS);
            ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_set_temperature_offset(TEMPERATURE_OFFSET));

            vTaskDelay(500 / portTICK_PERIOD_MS);
            ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_persist_settings());

            vTaskDelay(500 / portTICK_PERIOD_MS);
            temperature_offset = scd4x_get_temperature_offset();
        }

        if(sensor_altitude != SENSOR_ALTITUDE) {
            ESP_LOGW(TAG, "Sensor altitude calibration from %d m to %d m", sensor_altitude, SENSOR_ALTITUDE);

            vTaskDelay(500 / portTICK_PERIOD_MS);
            ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_set_sensor_altitude(SENSOR_ALTITUDE));

            vTaskDelay(500 / portTICK_PERIOD_MS);
            ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_persist_settings());

            vTaskDelay(500 / portTICK_PERIOD_MS);
            sensor_altitude = scd4x_get_sensor_altitude();
        }
        ESP_LOGI(TAG, "Temperature offset %.1f °%c - Sensor altitude %d %s", temperature_offset, scale, sensor_altitude, scale == SCALE_CELCIUS ? "m" : "ft");
    } else {
        ESP_LOGE(TAG, "Sensor offset/altitude read error!");
    }

    vTaskDelay(500 / portTICK_PERIOD_MS);
          
	scd4x_start_periodic_measurement();
	
	scd4x_sensors_values_t sensors_values = {
		.co2 = 0x00,
		.temperature = 0x00,
		.humidity = 0x00
    };
	
	for( ;; )
	{
		if( xSemaphoreTake( xSemaphore, pdMS_TO_TICKS(6000) ) == pdTRUE ) {
			ESP_LOGI(TAG, "Sensor");
			
			if(scd4x_read_measurement(&sensors_values) != ESP_OK) {
				ESP_LOGE(TAG, "Sensors read measurement error!");
				//continue;
			}
			/*
			my_tent.temperature_c = sensors_values.temperature;
			my_tent.temperature_f = FAHRENHEIT(sensors_values.temperature);
			my_tent.humidity = sensors_values.humidity;
			my_tent.co2 = sensors_values.co2;
			*/
			my_tent.temperature_c = 22;
			my_tent.temperature_f = FAHRENHEIT(my_tent.temperature_c);
			my_tent.humidity = 56;
			my_tent.co2 = 400;			
			
			ESP_LOGI(TAG, "CO₂ %d ppm - Temperature %2.1f - Humidity %d%%", my_tent.co2, my_tent.temperature_c, my_tent.humidity);
			//update_displayed_values();
			setFanSpeed();
			
		} else {
			ESP_LOGW(TAG, "Missed 1 count event or Timer stopped");
		}
			
	}
}

// Function that creates a task.
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



