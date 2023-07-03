// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void play_intro(lv_event_t * e);
void init_tomatotent(lv_event_t * e);
void start_grow(lv_event_t * e);
void save_light_duration_screen(lv_event_t * e);
void light_duration_slider(lv_event_t * e);
void now_slider(lv_event_t * e);
void save_led_brightness_screen(lv_event_t * e);
void LEDBrightnessSlider(lv_event_t * e);
void decrease_day_counter(lv_event_t * e);
void finish_grow(lv_event_t * e);
void increase_day_counter(lv_event_t * e);
void save_fan_settings_screen(lv_event_t * e);
void fanspeed_slider(lv_event_t * e);
void humidity_dropdown(lv_event_t * e);
void temperature_dropdown(lv_event_t * e);
void climate_mode_switch(lv_event_t * e);
void save_wifi_screen(lv_event_t * e);
void WifiKeyboardReady(lv_event_t * e);
void wifi_switch(lv_event_t * e);
void save_general_settings_screen(lv_event_t * e);
void screen_brightness_slider(lv_event_t * e);
void temp_unit_switch(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
