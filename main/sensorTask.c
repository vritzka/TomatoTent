#include "sensorTask.h"

static const char *TAG = "sensorTask.c";

gptimer_handle_t sensorTimerHandle = NULL;
static TaskHandle_t xSensorTaskHandle = NULL;
// static esp_err_t err;
SemaphoreHandle_t xSemaphore = NULL;

sht30_t sht30;

static bool IRAM_ATTR sensor_cb(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data)
{
    BaseType_t high_task_awoken = pdFALSE;

    xSemaphoreGiveFromISR(xSemaphore, &high_task_awoken);
    // return whether we need to yield at the end of ISR
    return (high_task_awoken == pdTRUE);
}

// Task to be created.
void vSensorTask(void *pvParameters)
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
        .alarm_count = 5000000, // period = 5s
        .flags.auto_reload_on_alarm = true,
    };
    ESP_ERROR_CHECK(gptimer_set_alarm_action(sensorTimerHandle, &alarm_config1));

    ESP_LOGI(TAG, "Initialising SHT30");
    sht30.i2c_port = I2C_NUM_1;
    sht30.addr = 0x44;
    if (sht30_init(&sht30) != ESP_OK)
    {
        ESP_LOGI(TAG, "Error initialising SHT30");
    }

    vTaskDelay(500 / portTICK_PERIOD_MS);

    for (;;)
    {
        if (xSemaphoreTake(xSemaphore, pdMS_TO_TICKS(6000)) == pdTRUE)
        {
            printf("SHT30: %5.2f C %5.2f %%\n",
                   sht30_get_temperature(&sht30, true),
                   sht30_get_humidity(&sht30, false));

            my_tent.temperature_c = sht30_get_temperature(&sht30, true);
            my_tent.temperature_c = 0;
            my_tent.humidity = sht30_get_humidity(&sht30, false);

            update_displayed_values();
            setFanSpeed();
        }
        else
        {
            // ESP_LOGW(TAG, "Missed 1 count event or Timer stopped");
        }
    }
}

// Function that creates a task.
// How to allocate task memory from SPI https://esp32.com/viewtopic.php?t=20660
void vCreateSensorTask(void)
{
    static uint8_t ucParameterToPass;
    xTaskCreatePinnedToCore(vSensorTask, "SENSORTASK", 4096, &ucParameterToPass, 10, &xSensorTaskHandle, 1);
    configASSERT(xSensorTaskHandle);
}

extern void vDeleteSensorTask(void)
{
    if (xSensorTaskHandle != NULL)
    {
        vTaskDelete(xSensorTaskHandle);
    }
}
