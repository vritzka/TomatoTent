// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: TT

#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void init_tomatotent(lv_event_t * e);
void start_grow(lv_event_t * e);
void start_dry(lv_event_t * e);
void ui_event_homeScreen_custom(lv_event_t * e);
void grow_lamp_dim(lv_event_t * e);
void save_light_duration_screen(lv_event_t * e);
void light_duration_slider(lv_event_t * e);
void now_slider(lv_event_t * e);
void LEDBrightnessSlider(lv_event_t * e);
void stop_grow(lv_event_t * e);
void decrease_day_counter(lv_event_t * e);
void increase_day_counter(lv_event_t * e);
void grow_lamp_un_dim(lv_event_t * e);
void show_temperature_series(lv_event_t * e);
void hide_temperature_series(lv_event_t * e);
void show_humidity_series(lv_event_t * e);
void hide_humidity_series(lv_event_t * e);
void show_co2_series(lv_event_t * e);
void hide_co2_series(lv_event_t * e);
void show_fanspeed_series(lv_event_t * e);
void hide_fanspeed_series(lv_event_t * e);
void humidity_dropdown(lv_event_t * e);
void temperature_dropdown(lv_event_t * e);
void climate_mode_switch(lv_event_t * e);
void fanspeed_slider(lv_event_t * e);
void save_wifi_screen(lv_event_t * e);
void WifiKeyboardReady(lv_event_t * e);
void wifi_switch(lv_event_t * e);
void wifi_scan_button(lv_event_t * e);
void save_general_settings_screen(lv_event_t * e);
void screen_brightness_slider(lv_event_t * e);
void software_upgrade_button(lv_event_t * e);
void updateDimmerPolarity(lv_event_t * e);
void temp_unit_switch(lv_event_t * e);
void restart_device(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
