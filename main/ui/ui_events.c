// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "lvgl.h"
#include "ui_events.h"
#include "ui.h"
#include <math.h>  
#include "esp_log.h"
#include <stdio.h>
#include "esp_system.h"
#include "esp_err.h"
#include "nvs.h"
#include "general.h"
#include "timerTask.h"


static const char *TAG = "ui_events.c";
nvs_handle_t storage_handle;
esp_err_t err;

//static char str[12];
//init values
static uint16_t light_duration_slider_value;
static float_t light_duration;
static float_t dark_duration;
static uint16_t now_slider_value;
static uint16_t led_brightness_slider_value;
static uint16_t dimmer_brightness_duty;
static uint16_t screen_brightness_slider_value = 80;
static uint16_t screen_brightness_duty;
static uint16_t temp_unit; //1 = C
static uint16_t wifi;
static uint16_t fanspeed_slider_left_value = 30;
static uint16_t fanspeed_slider_value = 60;
static uint8_t climate_mode = 0; //0 = auto
static uint16_t target_humidity_sel_index;
static uint16_t target_temperature_sel_index;
static uint16_t target_humidity;
static uint16_t target_temperature;

//SplashScreen

#ifndef PI
#define PI  (3.14159f)
#endif

typedef struct {
    lv_obj_t *scr;
    int count_val;
} my_timer_context_t;

my_timer_context_t my_tim_ctx;
lv_obj_t *arc[3];
lv_obj_t *img_text = NULL;
lv_color_t arc_color[] = {
    LV_COLOR_MAKE(0, 116, 0),
    LV_COLOR_MAKE(0, 162, 0),
    LV_COLOR_MAKE(0, 228, 0),
};

// LVGL image declare
LV_IMG_DECLARE(ui_img_tomato_png)
LV_IMG_DECLARE(tomatotent_text)

void anim_timer_cb(lv_timer_t *timer)
{
    my_timer_context_t *timer_ctx = (my_timer_context_t *) timer->user_data;
    int count = timer_ctx->count_val;
    lv_obj_t *scr = timer_ctx->scr;

    // Play arc animation
    if (count < 90) {
        lv_coord_t arc_start = count > 0 ? (1 - cosf(count / 180.0f * PI)) * 270 : 0;
        lv_coord_t arc_len = (sinf(count / 180.0f * PI) + 1) * 135;

        for (size_t i = 0; i < sizeof(arc) / sizeof(arc[0]); i++) {
            lv_arc_set_bg_angles(arc[i], arc_start, arc_len);
            lv_arc_set_rotation(arc[i], (count + 120 * (i + 1)) % 360);
        }
    }

    // Delete arcs when animation finished
    if (count == 90) {
        for (size_t i = 0; i < sizeof(arc) / sizeof(arc[0]); i++) {
            lv_obj_del(arc[i]);
        }

        // Create new image and make it transparent
        img_text = lv_img_create(scr);
        lv_img_set_src(img_text, &tomatotent_text);
        lv_obj_set_style_img_opa(img_text, 0, 0);
    }

    // Move images when arc animation finished
    if ((count >= 100) && (count <= 180)) {
        lv_coord_t offset = (sinf((count - 140) * 2.25f / 90.0f) + 1) * 20.0f;
        lv_obj_align(img_text, LV_ALIGN_CENTER, 0, -2.8 * offset);
        lv_obj_set_style_img_opa(img_text, offset / 40.0f * 255, 0);
    }

    // Delete timer when all animation finished
    if ((count += 5) == 220) {
        lv_timer_del(timer);
        
    } else {
        timer_ctx->count_val = count;
    }
}

void start_animation(lv_obj_t *scr)
{

    // Create arcs
    for (size_t i = 0; i < sizeof(arc) / sizeof(arc[0]); i++) {
        arc[i] = lv_arc_create(scr);

        // Set arc caption
        lv_obj_set_size(arc[i], 220 - 30 * i, 220 - 30 * i);
        lv_arc_set_bg_angles(arc[i], 120 * i, 10 + 120 * i);
        lv_arc_set_value(arc[i], 0);

        // Set arc style
        lv_obj_remove_style(arc[i], NULL, LV_PART_KNOB);
        lv_obj_set_style_arc_width(arc[i], 10, 0);
        lv_obj_set_style_arc_color(arc[i], arc_color[i], 0);

        // Make arc center
        lv_obj_center(arc[i]);
    }

    if (img_text) {
        lv_obj_del(img_text);
        img_text = NULL;
    }

    // Create timer for animation
    my_tim_ctx.count_val = -200;
    my_tim_ctx.scr = scr;
    lv_timer_create(anim_timer_cb, 20, &my_tim_ctx);

}

/////////////////////////////////////
///////// INIT TomatoTent ///////////
/////////////////////////////////////

void init_tomatotent(lv_event_t * e)
{	
	err = nvs_open("storage", NVS_READONLY, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else { 
		
		// light duration screen
        err = nvs_get_u16(storage_handle, "light_slider", &light_duration_slider_value);
        lv_slider_set_value(ui_LightDurationSlider, light_duration_slider_value, LV_ANIM_OFF);
		
		light_duration = (float_t)light_duration_slider_value / 2;
		tenttime.day_period_seconds = light_duration * 60 * 60;
		err = nvs_get_u32(storage_handle, "seconds", &tenttime.seconds);
		
		if(tenttime.seconds < tenttime.day_period_seconds) {
			tenttime.is_day = true;
		} else {
			tenttime.is_day = false;
		}
		
		dark_duration = 24 - light_duration;
	
		lv_label_set_text_fmt(ui_LightDurationLightLabel, "%.1f HRS", light_duration );
		lv_label_set_text_fmt(ui_LightDurationDarkLabel, "%.1f HRS", dark_duration ); 
				
		lv_slider_set_value(ui_NowSlider, (tenttime.seconds/30/60), LV_ANIM_OFF);
		
		// led brightness screen
		err = nvs_get_u16(storage_handle, "led_brightness", &led_brightness_slider_value);
        lv_slider_set_value(ui_LEDBrightnessSlider, led_brightness_slider_value, LV_ANIM_OFF);
		lv_label_set_text_fmt(ui_LEDBrightnessLabel, "%d %%", led_brightness_slider_value);

		//day counter screen
		err = nvs_get_u16(storage_handle, "days", &tenttime.days); 
		lv_label_set_text_fmt(ui_DayCounterLabel, "%hu", tenttime.days);
		lv_label_set_text_fmt(ui_DayCounterMainLabel, "%hu", tenttime.days);
		
		//general settings screen
		err = nvs_get_u16(storage_handle, "screen_brightns", &screen_brightness_slider_value); 
		lv_label_set_text_fmt(ui_ScreenBrightnessLabel, "%d%%", screen_brightness_slider_value);
		lv_slider_set_value(ui_ScreenBrightnessSlider, screen_brightness_slider_value, LV_ANIM_OFF);
		screen_brightness_duty = (128-1)*((float)screen_brightness_slider_value / 100);
		ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_BACKLIGHT_CHANNEL, screen_brightness_duty));
		ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_BACKLIGHT_CHANNEL));	
		
		err = nvs_get_u16(storage_handle, "temp_unit", &temp_unit);
		update_temp_units(temp_unit);
		
		//wifi screen
		size_t required_size;
		nvs_get_str(storage_handle, "ssid", NULL, &required_size);
		char* ssid = malloc(required_size);
		nvs_get_str(storage_handle, "ssid", ssid, &required_size);
		
		nvs_get_str(storage_handle, "pw", NULL, &required_size);
		char* pw = malloc(required_size);
		err = nvs_get_str(storage_handle, "pw", pw, &required_size);
		if (err == ESP_OK)		
			lv_textarea_set_text(ui_WifiPassword, pw);
			
		nvs_get_u16(storage_handle, "wifi", &wifi);
		if(wifi == 1) {
			lv_obj_add_state(ui_WifiSwitch, LV_STATE_CHECKED);
			wifi_init();
			wifi_scan();
		} else {
			lv_label_set_text(ui_WifiStatusLabel, "off");
		}
		
		// Fan Settings Screen
		err = nvs_get_u16(storage_handle, "fanspeed_min", &fanspeed_slider_left_value);
		err = nvs_get_u16(storage_handle, "fanspeed_max", &fanspeed_slider_value);
		
		lv_label_set_text_fmt(ui_FanSpeedMinLabel, "%d %%", fanspeed_slider_left_value);
		lv_label_set_text_fmt(ui_FanSpeedMaxLabel, "%d %%", fanspeed_slider_value);
		lv_slider_set_value(ui_fanSpeedSlider, fanspeed_slider_value, LV_ANIM_OFF);
		lv_slider_set_left_value(ui_fanSpeedSlider, fanspeed_slider_left_value, LV_ANIM_OFF);
		
		
		// Climate Screen
		err = nvs_get_u8(storage_handle, "climate_mode", &climate_mode);
		err = nvs_get_u16(storage_handle, "sel_hum_index", &target_humidity_sel_index);
		err = nvs_get_u16(storage_handle, "sel_temp_index", &target_temperature_sel_index);
		
		//ESP_LOGI(TAG, "%d", target_humidity);
		lv_dropdown_set_selected(ui_HumidityDropdown, target_humidity_sel_index);
		lv_dropdown_set_selected(ui_TemperatureDropdown, target_temperature_sel_index);
		
		if( climate_mode == 1 ) { //manual climate
			lv_obj_add_state(ui_ClimateModeSwitch, LV_STATE_CHECKED); 
		} else { //auto climate
			lv_obj_add_flag(ui_TemperatureSwitchPanel, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(ui_HumiditySwitchPanel, LV_OBJ_FLAG_HIDDEN);
		}		
		
        //is there an active grow?
		if(tenttime.seconds > 0 || tenttime.days > 0) {
			ESP_LOGI(TAG, "Continuing existing Grow");
			update_time_left(false);
			vStartTimerTask();
			lv_scr_load(ui_HomeScreen);
			fanspin_Animation(ui_Fan, 1000);
			fanspin_Animation(ui_Fan2, 1000);
		 } else {
		  start_animation(ui_SplashScreen);
		  startGrowButtonAppear_Animation(ui_StartNewGrowButton, 2000);
		  dryHarvestButtonAppear_Animation(ui_DryAHarvestButton, 2400);
		  moveTomato_Animation(ui_tomato, 2000);			 
		 }
		 		
        nvs_close(storage_handle);
        
	}
	
}


/////////////////////////////////////
/////// LightDurationScreen /////////
/////////////////////////////////////

void light_duration_slider(lv_event_t * e) {
	
	//lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t * target = lv_event_get_target(e);
	light_duration_slider_value = lv_slider_get_value(target);
	
	light_duration = (float_t)light_duration_slider_value / 2;
	tenttime.day_period_seconds = light_duration * 60 * 60;
	
	dark_duration = 24 - light_duration;

	//ESP_LOGI(TAG, "%.1f", light_duration);
	
	lv_label_set_text_fmt(ui_LightDurationLightLabel, "%.1f HRS", light_duration );
	lv_label_set_text_fmt(ui_LightDurationDarkLabel, "%.1f HRS", dark_duration );

}

void now_slider(lv_event_t * e) {
	
	lv_obj_t * target = lv_event_get_target(e);
	now_slider_value = lv_slider_get_value(target);
	if(now_slider_value == 48)
		return;
	
	tenttime.seconds = now_slider_value*30*60;
	update_time_left(false);

}

void save_light_duration_screen(lv_event_t * e)
{
    err = nvs_open("storage", NVS_READWRITE, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
		
		err = nvs_set_u16(storage_handle, "light_slider", light_duration_slider_value);
        //printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
		err = nvs_set_u32(storage_handle, "seconds", tenttime.seconds);
		err = nvs_commit(storage_handle);
        nvs_close(storage_handle);
	}
}

/////////////////////////////////////
/////// LED Brightness Screen ///////
/////////////////////////////////////

void LEDBrightnessSlider(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	led_brightness_slider_value = lv_slider_get_value(target);
	
	//ESP_LOGI(TAG, "%d", led_brightness_slider_value);
	
	lv_label_set_text_fmt(ui_LEDBrightnessLabel, "%d %%", led_brightness_slider_value );
	
	dimmer_brightness_duty = (128-1)*((float)led_brightness_slider_value / 100);
		
	ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_DIMMER_CHANNEL, dimmer_brightness_duty));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_DIMMER_CHANNEL));	
}

void save_led_brightness_screen(lv_event_t * e)
{
    err = nvs_open("storage", NVS_READWRITE, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
		
		err = nvs_set_u16(storage_handle, "led_brightness", led_brightness_slider_value);
        //printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
		
		err = nvs_commit(storage_handle);
        //printf((err != ESP_OK) ? "Failed!\n" : "Done\n");

        // Close
        nvs_close(storage_handle);	
	}	
	
}

/////////////////////////////////////
/////// Day Counter Screen //////////
/////////////////////////////////////

void increase_day_counter(lv_event_t * e)
{
	tenttime.days += 1;
	lv_label_set_text_fmt(ui_DayCounterLabel, "%hu", tenttime.days);
	lv_label_set_text_fmt(ui_DayCounterMainLabel, "%hu", tenttime.days);
	
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	err = nvs_set_u16(storage_handle, "days", tenttime.days);
	err = nvs_commit(storage_handle);
	nvs_close(storage_handle);
}

void decrease_day_counter(lv_event_t * e)
{
	if(tenttime.days == 1)
		return;
	
	tenttime.days -= 1;
	lv_label_set_text_fmt(ui_DayCounterLabel, "%hu", tenttime.days);
	lv_label_set_text_fmt(ui_DayCounterMainLabel, "%hu", tenttime.days);

	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	err = nvs_set_u16(storage_handle, "days", tenttime.days);
	err = nvs_commit(storage_handle);
	nvs_close(storage_handle);
}


/////////////////////////////////////
///// General Settings Screen ///////
/////////////////////////////////////


void screen_brightness_slider(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	screen_brightness_slider_value = lv_slider_get_value(target);
	
	lv_label_set_text_fmt(ui_ScreenBrightnessLabel, "%hu%%", screen_brightness_slider_value);
		
	screen_brightness_duty = (128-1)*((float)screen_brightness_slider_value / 100);
		
	ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_BACKLIGHT_CHANNEL, screen_brightness_duty));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_BACKLIGHT_CHANNEL));	
}


void temp_unit_switch(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	
	if( lv_obj_has_state(target, LV_STATE_CHECKED) ) {   
		//on = F = 1
		temp_unit = 1;
	} else { 
		//off = C = 0	
		temp_unit = 0;
	}
	
	update_temp_units(temp_unit);
	
}

void save_general_settings_screen(lv_event_t * e)
{
    err = nvs_open("storage", NVS_READWRITE, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
		
		err = nvs_set_u16(storage_handle, "screen_brightns", screen_brightness_slider_value);
        err = nvs_set_u16(storage_handle, "temp_unit", temp_unit);
        //code to set everything to F or C

        // Close
        err = nvs_commit(storage_handle);
        nvs_close(storage_handle);	
	}	
	
}

//////////////////////////////////////
////////// WIFI Screen ///////////////
//////////////////////////////////////

void wifi_switch(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	
	if( lv_obj_has_state(target, LV_STATE_CHECKED) ) {   
		wifi_init();
		wifi_scan();
	} else { 
		//off = 0	
		wifi_off();
		lv_label_set_text(ui_WifiStatusLabel, "off");
	}

}

void WifiKeyboardReady(lv_event_t * e)
{
	//lv_event_code_t event_code = lv_event_get_code(e);
	//ESP_LOGI(TAG, "%d", event_code);
	wifi_connect();
}

void save_wifi_screen(lv_event_t * e) 
{
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	const char *pw = lv_textarea_get_text(ui_WifiPassword);
    nvs_set_str(storage_handle, "pw", pw);
    
    if( lv_obj_has_state(ui_WifiSwitch, LV_STATE_CHECKED) ) {
		err = nvs_set_u16(storage_handle, "wifi", 1);
		char ssid[128];
		lv_dropdown_get_selected_str(ui_WifiDropdown, ssid, sizeof(ssid));
		nvs_set_str(storage_handle, "ssid", ssid);
	} else {
		err = nvs_set_u16(storage_handle, "wifi", 0);
	}
    err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
}

//////////////////////////////////////
/////// Fan Speed Screen /////////////
//////////////////////////////////////

void fanspeed_slider(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	
	fanspeed_slider_left_value = lv_slider_get_left_value(target);
	fanspeed_slider_value = lv_slider_get_value(target);
	
	
	lv_label_set_text_fmt(ui_FanSpeedMinLabel, "%hu %%", fanspeed_slider_left_value);
	lv_label_set_text_fmt(ui_FanSpeedMaxLabel, "%hu %%", fanspeed_slider_value);
}

void save_fan_settings_screen(lv_event_t * e)
{
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	err = nvs_set_u16(storage_handle, "fanspeed_min", fanspeed_slider_left_value);
	err = nvs_set_u16(storage_handle, "fanspeed_max", fanspeed_slider_value);
	
	err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
}

//////////////////////////////////////
///////// Climate screen /////////////
//////////////////////////////////////


void climate_mode_switch(lv_event_t * e)
{
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	
	lv_obj_t * target = lv_event_get_target(e);
	
	if( lv_obj_has_state(target, LV_STATE_CHECKED) ) { //manual climate
		climate_mode = 1;
		lv_obj_clear_flag(ui_TemperatureSwitchPanel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_HumiditySwitchPanel, LV_OBJ_FLAG_HIDDEN);
	} else { //auto climate
		climate_mode = 0;
		lv_obj_add_flag(ui_TemperatureSwitchPanel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_HumiditySwitchPanel, LV_OBJ_FLAG_HIDDEN);
	}
	
	err = nvs_set_u8(storage_handle, "climate_mode", climate_mode);
	err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
	
}

void humidity_dropdown(lv_event_t * e)
{
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	lv_obj_t * target = lv_event_get_target(e);
	
	target_humidity_sel_index = lv_dropdown_get_selected(target);
	
	err = nvs_set_u16(storage_handle, "sel_hum_index", target_humidity_sel_index );
	
	err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
}

void temperature_dropdown(lv_event_t * e)
{
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	lv_obj_t * target = lv_event_get_target(e);
	
	target_temperature_sel_index = lv_dropdown_get_selected(target);
	
	err = nvs_set_u16(storage_handle, "sel_temp_index", target_temperature_sel_index );
	
	err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
}

//////////////////////////////////////
/////////  Start Screen  /////////////
//////////////////////////////////////

void start_grow(lv_event_t * e)
{

	_ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_FADE_ON, 1000, 0);
	vStartTimerTask();
	make_it_day(true);
	fanspin_Animation(ui_Fan, 1000);
	fanspin_Animation(ui_Fan2, 1000);
	
}

void finish_grow(lv_event_t * e)
{
	lv_anim_del_all();
	vStopTimerTask();
	
	tenttime.event_count = 0;
    tenttime.seconds = 0;
    tenttime.days = 0;
    tenttime.is_day = true;
    //tenttime.day_period_seconds;
}
