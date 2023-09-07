#ifndef GUITASK_H
#define GUITASK_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"
#include "ui/ui.h"
#include "general.h"

#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED
#include "driver/i2c.h"
#if CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_GT911
#include "esp_lcd_touch_gt911.h"
#elif CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_TT21100
#include "esp_lcd_touch_tt21100.h"
#elif CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_FT5X06
#include "esp_lcd_touch_ft5x06.h"
#endif
#endif

void vGuiTask( void * pvParameters );
void vStartGuiTask( void );

#endif
