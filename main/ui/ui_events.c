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
#include "sensorTask.h"
#include "otaTask.h"


static const char *TAG = "ui_events.c";
nvs_handle_t storage_handle;
esp_err_t err;


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
   
   //init values
   my_tent.screen_brightness_slider_value = 80;
   my_tent.light_duration_slider_value = 36;
   my_tent.led_brightness_slider_value = 80;
   my_tent.elevation = 0;
   my_tent.temperature_offset = 4;
   
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!!!\n", esp_err_to_name(err));
    } else { 
		
		spinboxes_init();
		draw_qr_codes();
		chart_init();
		
		// light duration screen
        err = nvs_get_u16(storage_handle, "light_slider", &my_tent.light_duration_slider_value);
        lv_slider_set_value(ui_LightDurationSlider, my_tent.light_duration_slider_value, LV_ANIM_OFF);
		
		my_tent.light_duration = (float_t)my_tent.light_duration_slider_value / 2;
		my_tent.day_period_seconds = my_tent.light_duration * 60 * 60;
		err = nvs_get_u32(storage_handle, "seconds", &my_tent.seconds);
		
		if(my_tent.seconds < my_tent.day_period_seconds) {
			my_tent.is_day = true;
		} else {
			my_tent.is_day = false;
			make_it_night();
		}
		
		my_tent.dark_duration = 24 - my_tent.light_duration;
	
		lv_label_set_text_fmt(ui_LightDurationLightLabel, "%.1f HRS", my_tent.light_duration );
		lv_label_set_text_fmt(ui_LightDurationDarkLabel, "%.1f HRS", my_tent.dark_duration ); 
				
		lv_slider_set_value(ui_NowSlider, (my_tent.seconds/30/60), LV_ANIM_OFF);
		
		// led brightness screen
		err = nvs_get_u16(storage_handle, "led_brightness", &my_tent.led_brightness_slider_value);
        lv_slider_set_value(ui_LEDBrightnessSlider, my_tent.led_brightness_slider_value, LV_ANIM_OFF);
		lv_label_set_text_fmt(ui_LEDBrightnessLabel, "%d %%", my_tent.led_brightness_slider_value);

		//day counter screen
		err = nvs_get_u16(storage_handle, "days", &my_tent.days); 
		lv_label_set_text_fmt(ui_DayCounterLabel, "%hu", my_tent.days);
		lv_label_set_text_fmt(ui_DayCounterMainLabel, "%hu", my_tent.days);
		
		//general settings screen
		err = nvs_get_u16(storage_handle, "screen_brightns", &my_tent.screen_brightness_slider_value); 
		lv_label_set_text_fmt(ui_ScreenBrightnessLabel, "%d%%", my_tent.screen_brightness_slider_value);
		lv_slider_set_value(ui_ScreenBrightnessSlider, my_tent.screen_brightness_slider_value, LV_ANIM_OFF);
		my_tent.screen_brightness_duty = (128-1)*((float)my_tent.screen_brightness_slider_value / 100);
		ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_BACKLIGHT_CHANNEL, my_tent.screen_brightness_duty));
		ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_BACKLIGHT_CHANNEL));	
		
		err = nvs_get_u16(storage_handle, "elevation", &my_tent.elevation);
		//printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
		lv_spinbox_set_value(ui_ElevationSpinbox, my_tent.elevation);
        
        err = nvs_get_u8(storage_handle, "temp_offset", &my_tent.temperature_offset);
        //printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
		lv_spinbox_set_value(ui_TemperatureOffsetSpinbox, my_tent.temperature_offset);
		
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
			
		nvs_get_u16(storage_handle, "wifi", &my_tent.wifi);
		if(my_tent.wifi == 1) {
			lv_obj_add_state(ui_WifiSwitch, LV_STATE_CHECKED);
			wifi_init();
		} else {
			lv_label_set_text(ui_WifiStatusLabel, "off");
		}
		
		// Fan Settings Screen
		err = nvs_get_u16(storage_handle, "fanspeed_min", &my_tent.fanspeed_slider_left_value);
		err = nvs_get_u16(storage_handle, "fanspeed_max", &my_tent.fanspeed_slider_value);
		
		lv_label_set_text_fmt(ui_FanSpeedMinLabel, "%d %%", my_tent.fanspeed_slider_left_value);
		lv_label_set_text_fmt(ui_FanSpeedMaxLabel, "%d %%", my_tent.fanspeed_slider_value);
		lv_slider_set_value(ui_fanSpeedSlider, my_tent.fanspeed_slider_value, LV_ANIM_OFF);
		lv_slider_set_left_value(ui_fanSpeedSlider, my_tent.fanspeed_slider_left_value, LV_ANIM_OFF);
		
		
		// Climate Screen
		err = nvs_get_u16(storage_handle, "temp_unit", &my_tent.temp_unit);
		update_temp_units(my_tent.temp_unit);
		err = nvs_get_u8(storage_handle, "climate_mode", &my_tent.climate_mode);
		err = nvs_get_u16(storage_handle, "sel_hum_index", &my_tent.target_humidity_sel_index);
		err = nvs_get_u16(storage_handle, "sel_temp_index", &my_tent.target_temperature_sel_index);
		
		lv_dropdown_set_selected(ui_HumidityDropdown, my_tent.target_humidity_sel_index);
		lv_dropdown_set_selected(ui_TemperatureDropdown, my_tent.target_temperature_sel_index);
		
		if( my_tent.climate_mode == 1 ) { //manual climate
			lv_obj_add_state(ui_ClimateModeSwitch, LV_STATE_CHECKED); 
		} else { //auto climate
			lv_obj_add_flag(ui_TemperatureSwitchPanel, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(ui_HumiditySwitchPanel, LV_OBJ_FLAG_HIDDEN);
		}
		
		set_target_climate();
		
		// Software Upgrade Screen
		const esp_partition_t *running = esp_ota_get_running_partition();
		esp_app_desc_t running_app_info;
		esp_ota_get_partition_description(running, &running_app_info);
		lv_label_set_text_fmt(ui_CurrentVersionLabel, "current version: %s", running_app_info.version);	
		
		//SensorSettingsScreen
			
        //is there an active grow?
		if(my_tent.seconds > 0 || my_tent.days > 0) {
			ESP_LOGI(TAG, "Continuing existing Grow");
			update_time_left(false);
			ESP_ERROR_CHECK(gptimer_start(gptimer));
			ESP_ERROR_CHECK(gptimer_start(sensorTimerHandle));
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
	my_tent.light_duration_slider_value = lv_slider_get_value(target);
	
	my_tent.light_duration = (float_t)my_tent.light_duration_slider_value / 2;
	my_tent.day_period_seconds = my_tent.light_duration * 60 * 60;
	
	my_tent.dark_duration = 24 - my_tent.light_duration;

	//ESP_LOGI(TAG, "%.1f", light_duration);
	
	lv_label_set_text_fmt(ui_LightDurationLightLabel, "%.1f HRS", my_tent.light_duration );
	lv_label_set_text_fmt(ui_LightDurationDarkLabel, "%.1f HRS", my_tent.dark_duration );

}

void now_slider(lv_event_t * e) {
	
	lv_obj_t * target = lv_event_get_target(e);
	my_tent.now_slider_value = lv_slider_get_value(target);
	if(my_tent.now_slider_value == 48)
		return;
	
	my_tent.seconds = my_tent.now_slider_value*30*60;
	update_time_left(false);

}

void save_light_duration_screen(lv_event_t * e)
{
    err = nvs_open("storage", NVS_READWRITE, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
		
		err = nvs_set_u16(storage_handle, "light_slider", my_tent.light_duration_slider_value);
        //printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
		err = nvs_set_u32(storage_handle, "seconds", my_tent.seconds);
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
	my_tent.led_brightness_slider_value = lv_slider_get_value(target);
	
	//ESP_LOGI(TAG, "%d", led_brightness_slider_value);
	
	lv_label_set_text_fmt(ui_LEDBrightnessLabel, "%d %%", my_tent.led_brightness_slider_value );
	
	setGrowLampBrightness();
}

void save_led_brightness_screen(lv_event_t * e)
{
    err = nvs_open("storage", NVS_READWRITE, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
		
		err = nvs_set_u16(storage_handle, "led_brightness", my_tent.led_brightness_slider_value);
        //printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
		
		err = nvs_commit(storage_handle);
        //printf((err != ESP_OK) ? "Failed!\n" : "Done\n");

        // Close
        nvs_close(storage_handle);	
	}	
	
}

void grow_lamp_dim(lv_event_t * e)
{
	if(!my_tent.is_day)
		return;
		
	if(my_tent.grow_lamp_dimmed != 1) {
		my_tent.grow_lamp_dimmed = true;
		ShowDimmerIndication_Animation(ui_DimmerIconPanel, 0);
		ShowDimmerIndication2_Animation(ui_DimmerIconPanel2, 0);
		ESP_ERROR_CHECK(gptimer_set_raw_count(grow_lamp_dimmer_timer_handle,0));
		ESP_ERROR_CHECK(gptimer_start(grow_lamp_dimmer_timer_handle));
		ESP_LOGI(TAG, "Dimmed");
	}

}

void grow_lamp_un_dim(lv_event_t * e)
{
	if(!my_tent.grow_lamp_dimmed)
		return;
		
	my_tent.grow_lamp_dimmed = false;
	HideDimmerIndication_Animation(ui_DimmerIconPanel, 0);
	HideDimmerIndication2_Animation(ui_DimmerIconPanel2, 0);
	lv_arc_set_value(ui_DimmerArc, 900);
	lv_bar_set_value(ui_DimmerBar2, 900, LV_ANIM_OFF);
	ESP_ERROR_CHECK(gptimer_stop(grow_lamp_dimmer_timer_handle));
	ESP_LOGI(TAG, "Un-Dimmed");		
	setGrowLampBrightness();
}

/////////////////////////////////////
/////// Day Counter Screen //////////
/////////////////////////////////////

void increase_day_counter(lv_event_t * e)
{
	my_tent.days += 1;
	lv_label_set_text_fmt(ui_DayCounterLabel, "%hu", my_tent.days);
	lv_label_set_text_fmt(ui_DayCounterMainLabel, "%hu", my_tent.days);
	
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	err = nvs_set_u16(storage_handle, "days", my_tent.days);
	err = nvs_commit(storage_handle);
	nvs_close(storage_handle);
}

void decrease_day_counter(lv_event_t * e)
{
	if(my_tent.days == 1)
		return;
	
	my_tent.days -= 1;
	lv_label_set_text_fmt(ui_DayCounterLabel, "%hu", my_tent.days);
	lv_label_set_text_fmt(ui_DayCounterMainLabel, "%hu", my_tent.days);

	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	err = nvs_set_u16(storage_handle, "days", my_tent.days);
	err = nvs_commit(storage_handle);
	nvs_close(storage_handle);
}


/////////////////////////////////////
///// General Settings Screen ///////
/////////////////////////////////////


void screen_brightness_slider(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	my_tent.screen_brightness_slider_value = lv_slider_get_value(target);
	
	lv_label_set_text_fmt(ui_ScreenBrightnessLabel, "%hu%%", my_tent.screen_brightness_slider_value);
		
	my_tent.screen_brightness_duty = (128-1)*((float)my_tent.screen_brightness_slider_value / 100);
		
	ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_BACKLIGHT_CHANNEL, my_tent.screen_brightness_duty));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_BACKLIGHT_CHANNEL));	
}


void temp_unit_switch(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	
	if( lv_obj_has_state(target, LV_STATE_CHECKED) ) {   
		//on = F = 1
		my_tent.temp_unit = 1;
	} else { 
		//off = C = 0	
		my_tent.temp_unit = 0;
	}
	
	update_temp_units(my_tent.temp_unit);
	set_target_climate();
	
	err = nvs_set_u16(storage_handle, "temp_unit", my_tent.temp_unit);
	err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
}

void save_general_settings_screen(lv_event_t * e)
{
    err = nvs_open("storage", NVS_READWRITE, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
		
		err = nvs_set_u16(storage_handle, "screen_brightns", my_tent.screen_brightness_slider_value);     
        err = nvs_set_u16(storage_handle, "elevation", my_tent.elevation);
        err = nvs_set_u8(storage_handle, "temp_offset", my_tent.temperature_offset);
		
        // Close
        err = nvs_commit(storage_handle);
        nvs_close(storage_handle);	
	}	
	
}

void update_sensor_calibration(lv_event_t * e) {
		lv_label_set_text(ui_SensorSettingsInfoLabel, "");	
		gptimer_stop(sensorTimerHandle);
	    scd4x_stop_periodic_measurement();
        vTaskDelay(500 / portTICK_PERIOD_MS);
        ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_set_temperature_offset((float)my_tent.temperature_offset));
        vTaskDelay(500 / portTICK_PERIOD_MS);
		ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_set_sensor_altitude((float)my_tent.elevation));
		vTaskDelay(500 / portTICK_PERIOD_MS);
		ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_persist_settings());
		vTaskDelay(500 / portTICK_PERIOD_MS);
		ESP_ERROR_CHECK_WITHOUT_ABORT(scd4x_reinit());
		vTaskDelay(500 / portTICK_PERIOD_MS);
		scd4x_start_periodic_measurement();
		lv_label_set_text(ui_SensorSettingsInfoLabel, "Success\nSensor will take 2-3 minutes to gradually reflect new settings.");
		gptimer_set_raw_count(sensorTimerHandle, 0);
		gptimer_start(sensorTimerHandle);
		
}

//////////////////////////////////////
////////// WIFI Screen ///////////////
//////////////////////////////////////

void wifi_switch(lv_event_t * e)
{
	lv_obj_t * target = lv_event_get_target(e);
	
	if( lv_obj_has_state(target, LV_STATE_CHECKED) ) {   
		wifi_init();
		my_tent.wifi = 1;
	} else { 
		//off = 0	
		wifi_off();
		my_tent.wifi = 0;
		lv_label_set_text(ui_WifiStatusLabel, "off");
	}

}

void wifi_scan_button(lv_event_t * e)
{
	wifi_scan();
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
	
	my_tent.fanspeed_slider_left_value = lv_slider_get_left_value(target);
	my_tent.fanspeed_slider_value = lv_slider_get_value(target);
	
	
	lv_label_set_text_fmt(ui_FanSpeedMinLabel, "%hu %%", my_tent.fanspeed_slider_left_value);
	lv_label_set_text_fmt(ui_FanSpeedMaxLabel, "%hu %%", my_tent.fanspeed_slider_value);
}

void save_fan_settings_screen(lv_event_t * e)
{
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	err = nvs_set_u16(storage_handle, "fanspeed_min", my_tent.fanspeed_slider_left_value);
	err = nvs_set_u16(storage_handle, "fanspeed_max", my_tent.fanspeed_slider_value);
	
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
		my_tent.climate_mode = 1;
		lv_obj_clear_flag(ui_TemperatureSwitchPanel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_HumiditySwitchPanel, LV_OBJ_FLAG_HIDDEN);
	} else { //auto climate
		my_tent.climate_mode = 0;
		lv_obj_add_flag(ui_TemperatureSwitchPanel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_HumiditySwitchPanel, LV_OBJ_FLAG_HIDDEN);
	}
	
	err = nvs_set_u8(storage_handle, "climate_mode", my_tent.climate_mode);
	err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
	
}

void humidity_dropdown(lv_event_t * e)
{
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	lv_obj_t * target = lv_event_get_target(e);
	
	set_target_climate();
	
	my_tent.target_humidity_sel_index = lv_dropdown_get_selected(target);
	
	err = nvs_set_u16(storage_handle, "sel_hum_index", my_tent.target_humidity_sel_index );
	
	err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
}

void temperature_dropdown(lv_event_t * e)
{
	err = nvs_open("storage", NVS_READWRITE, &storage_handle);
	lv_obj_t * target = lv_event_get_target(e);
	
	set_target_climate();
	
	my_tent.target_temperature_sel_index = lv_dropdown_get_selected(target);
	
	err = nvs_set_u16(storage_handle, "sel_temp_index", my_tent.target_temperature_sel_index );
	
	err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
}

//////////////////////////////////////
/////////  Start Screen  /////////////
//////////////////////////////////////

void start_grow(lv_event_t * e)
{

	_ui_screen_change( &ui_HomeScreen, LV_SCR_LOAD_ANIM_FADE_ON, 1000, 0, &ui_HomeScreen_screen_init);
	
	ESP_ERROR_CHECK(gptimer_start(gptimer));
	ESP_ERROR_CHECK(gptimer_start(sensorTimerHandle));
	make_it_day(true);
	fanspin_Animation(ui_Fan, 1000);
	fanspin_Animation(ui_Fan2, 1000);
	
}

static void stop_grow_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_current_target(e);
    int id = lv_msgbox_get_active_btn(obj);
    ESP_LOGI(TAG, "Button %d clicked", id);
    if(id != 0)
		return;
	
	lv_msgbox_close(obj);	
	lv_anim_del_all();
	ESP_ERROR_CHECK(gptimer_stop(gptimer));
	ESP_ERROR_CHECK(gptimer_stop(sensorTimerHandle));
    
    err = nvs_open("storage", NVS_READWRITE, &storage_handle);
    err = nvs_set_u32(storage_handle, "seconds", 0);
    err = nvs_set_u16(storage_handle, "days", 0);
	err = nvs_commit(storage_handle);
    nvs_close(storage_handle);
    lv_obj_set_pos(ui_tomato, 0,0);
    lv_obj_set_pos(ui_StartNewGrowButton, -430,-9);
    lv_obj_set_pos(ui_DryAHarvestButton, 435,96);
    lv_scr_load(ui_SplashScreen);  
    
    
    
    		start_animation(ui_SplashScreen);
			  startGrowButtonAppear_Animation(ui_StartNewGrowButton, 2000);
			  dryHarvestButtonAppear_Animation(ui_DryAHarvestButton, 2400);
			  moveTomato_Animation(ui_tomato, 2000);  
    
}

void stop_grow(lv_event_t * e)
{
	static const char * btns[] = {"Finish it!", "No, go back.", ""};

    lv_obj_t * mbox1 = lv_msgbox_create(NULL, "Finished?", "This will end the current grow/dry.", btns, true);
    lv_obj_add_event_cb(mbox1, stop_grow_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_center(mbox1);
	
}

void software_upgrade_button(lv_event_t * e)
{
	   ESP_LOGI(TAG, "Here");
	   vStartOtaTask();
}


void hide_temperature_series(lv_event_t * e)
{
	lv_chart_hide_series(ui_Chart, chart_series_temperature, true);
}

void show_temperature_series(lv_event_t * e)
{
	 lv_chart_hide_series(ui_Chart, chart_series_temperature, false);
}

void hide_humidity_series(lv_event_t * e)
{
	 lv_chart_hide_series(ui_Chart, chart_series_humidity, true);
}

void show_humidity_series(lv_event_t * e)
{
	 lv_chart_hide_series(ui_Chart, chart_series_humidity, false);
}

void hide_co2_series(lv_event_t * e)
{
	 lv_chart_hide_series(ui_Chart, chart_series_co2, true);
	 lv_chart_set_axis_tick(ui_Chart, LV_CHART_AXIS_SECONDARY_Y, 0, 1, 8, 1, false, 20);
}

void show_co2_series(lv_event_t * e)
{
	 lv_chart_hide_series(ui_Chart, chart_series_co2, false);
	 lv_chart_set_axis_tick(ui_Chart, LV_CHART_AXIS_SECONDARY_Y, 0, 1, 8, 1, true, 20);
}

void hide_fanspeed_series(lv_event_t * e)
{
	 lv_chart_hide_series(ui_Chart, chart_series_fanspeed, true);
}

void show_fanspeed_series(lv_event_t * e)
{
	 lv_chart_hide_series(ui_Chart, chart_series_fanspeed, false);
}



void ui_event_homeScreen_custom(lv_event_t * e)
{
	lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

	if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP  ) {
	lv_indev_wait_release(lv_indev_get_act());
		if(my_tent.grow_lamp_dimmed) {
			grow_lamp_un_dim(e);
		} else {
			_ui_screen_change( &ui_GeneralSettingsScreen, LV_SCR_LOAD_ANIM_MOVE_TOP, 300, 0, &ui_GeneralSettingsScreen_screen_init);
		}
		  
	}

}
