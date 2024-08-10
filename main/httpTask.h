#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/param.h>
#include "general.h"
#include "esp_timer.h"
#include "esp_log.h"
#include "esp_http_client.h"
#include "esp_crt_bundle.h"
#include "esp_tls.h"
#include "esp_sleep.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "cJSON.h"


void create_http_timer(void);
void start_http_timer(void);
void stop_http_timer(void);
void vStartHTTPTask(void);