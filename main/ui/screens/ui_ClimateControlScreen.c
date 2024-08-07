// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_ClimateControlScreen_screen_init(void)
{
ui_ClimateControlScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ClimateControlScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ClimateControlScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ClimateControlScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image14 = lv_img_create(ui_ClimateControlScreen);
lv_img_set_src(ui_Image14, &ui_img_261459337);
lv_obj_set_width( ui_Image14, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image14, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image14, -347 );
lv_obj_set_y( ui_Image14, -203 );
lv_obj_set_align( ui_Image14, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image14, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image14, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_ClimateSettingsScreen = lv_label_create(ui_ClimateControlScreen);
lv_obj_set_width( ui_ClimateSettingsScreen, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ClimateSettingsScreen, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ClimateSettingsScreen, -254 );
lv_obj_set_y( ui_ClimateSettingsScreen, -202 );
lv_obj_set_align( ui_ClimateSettingsScreen, LV_ALIGN_CENTER );
lv_label_set_text(ui_ClimateSettingsScreen,"Climate");
lv_obj_set_style_text_font(ui_ClimateSettingsScreen, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ClimateValuesPanel = lv_obj_create(ui_ClimateControlScreen);
lv_obj_set_width( ui_ClimateValuesPanel, 220);
lv_obj_set_height( ui_ClimateValuesPanel, 285);
lv_obj_set_align( ui_ClimateValuesPanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ClimateValuesPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ClimateValuesPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ClimateValuesPanel, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_ClimateValuesPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_HumidityDropdown = lv_dropdown_create(ui_ClimateValuesPanel);
lv_dropdown_set_options( ui_HumidityDropdown, "10%\n20%\n25%\n30%\n35%\n40%\n45%\n50%\n55%\n60%\n65%\n70%\n75%\n80%\n85%\n90%\n95%" );
lv_obj_set_width( ui_HumidityDropdown, 100);
lv_obj_set_height( ui_HumidityDropdown, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_HumidityDropdown, -5 );
lv_obj_set_y( ui_HumidityDropdown, -43 );
lv_obj_set_align( ui_HumidityDropdown, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_HumidityDropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_set_style_text_align(ui_HumidityDropdown, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_HumidityDropdown, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_text_color(ui_HumidityDropdown, lv_color_hex(0x555CFA), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_HumidityDropdown, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);


ui_Label18 = lv_label_create(ui_ClimateValuesPanel);
lv_obj_set_width( ui_Label18, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label18, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label18, 1 );
lv_obj_set_y( ui_Label18, -96 );
lv_obj_set_align( ui_Label18, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label18,"Target Humidity");
lv_obj_set_style_text_font(ui_Label18, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TemperatureDropdown = lv_dropdown_create(ui_ClimateValuesPanel);
lv_dropdown_set_options( ui_TemperatureDropdown, "" );
lv_obj_set_width( ui_TemperatureDropdown, 100);
lv_obj_set_height( ui_TemperatureDropdown, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TemperatureDropdown, -4 );
lv_obj_set_y( ui_TemperatureDropdown, 76 );
lv_obj_set_align( ui_TemperatureDropdown, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_TemperatureDropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_set_style_text_font(ui_TemperatureDropdown, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_text_color(ui_TemperatureDropdown, lv_color_hex(0xB29D15), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TemperatureDropdown, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);


ui_Label17 = lv_label_create(ui_ClimateValuesPanel);
lv_obj_set_width( ui_Label17, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label17, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label17, 2 );
lv_obj_set_y( ui_Label17, 26 );
lv_obj_set_align( ui_Label17, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label17,"Target Temperature");
lv_obj_set_style_text_font(ui_Label17, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel2 = lv_obj_create(ui_ClimateControlScreen);
lv_obj_set_width( ui_Panel2, 193);
lv_obj_set_height( ui_Panel2, 54);
lv_obj_set_x( ui_Panel2, -284 );
lv_obj_set_y( ui_Panel2, 33 );
lv_obj_set_align( ui_Panel2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ClimateModeSwitch = lv_switch_create(ui_Panel2);
lv_obj_set_width( ui_ClimateModeSwitch, 50);
lv_obj_set_height( ui_ClimateModeSwitch, 25);
lv_obj_set_x( ui_ClimateModeSwitch, -5 );
lv_obj_set_y( ui_ClimateModeSwitch, 0 );
lv_obj_set_align( ui_ClimateModeSwitch, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ClimateModeSwitch, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags


ui_Label19 = lv_label_create(ui_Panel2);
lv_obj_set_width( ui_Label19, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label19, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label19, -67 );
lv_obj_set_y( ui_Label19, 1 );
lv_obj_set_align( ui_Label19, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label19,"Auto");
lv_obj_set_style_text_font(ui_Label19, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label20 = lv_label_create(ui_Panel2);
lv_obj_set_width( ui_Label20, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label20, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label20, 59 );
lv_obj_set_y( ui_Label20, 1 );
lv_obj_set_align( ui_Label20, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label20,"Manual");
lv_obj_set_style_text_font(ui_Label20, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel17 = lv_obj_create(ui_ClimateControlScreen);
lv_obj_set_width( ui_Panel17, 160);
lv_obj_set_height( ui_Panel17, 54);
lv_obj_set_x( ui_Panel17, -301 );
lv_obj_set_y( ui_Panel17, -55 );
lv_obj_set_align( ui_Panel17, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel17, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel17, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel17, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel17, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TempUnitSwitch = lv_switch_create(ui_Panel17);
lv_obj_set_width( ui_TempUnitSwitch, 50);
lv_obj_set_height( ui_TempUnitSwitch, 25);
lv_obj_set_align( ui_TempUnitSwitch, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_TempUnitSwitch, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags

lv_obj_set_style_bg_color(ui_TempUnitSwitch, lv_color_hex(0x140396), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TempUnitSwitch, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TempUnitSwitch, lv_color_hex(0x140396), LV_PART_INDICATOR | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_TempUnitSwitch, 255, LV_PART_INDICATOR| LV_STATE_CHECKED);

ui_Label27 = lv_label_create(ui_Panel17);
lv_obj_set_width( ui_Label27, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label27, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label27, 47 );
lv_obj_set_y( ui_Label27, 0 );
lv_obj_set_align( ui_Label27, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label27,"°F");
lv_obj_set_style_text_font(ui_Label27, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label16 = lv_label_create(ui_Panel17);
lv_obj_set_width( ui_Label16, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label16, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label16, -50 );
lv_obj_set_y( ui_Label16, 0 );
lv_obj_set_align( ui_Label16, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label16,"°C");
lv_obj_set_style_text_font(ui_Label16, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel13 = lv_obj_create(ui_ClimateControlScreen);
lv_obj_set_width( ui_Panel13, 177);
lv_obj_set_height( ui_Panel13, 456);
lv_obj_set_x( ui_Panel13, 273 );
lv_obj_set_y( ui_Panel13, 0 );
lv_obj_set_align( ui_Panel13, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel13, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel13, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel13, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fanSpeedSlider = lv_slider_create(ui_Panel13);
lv_slider_set_range(ui_fanSpeedSlider, 5,100);
lv_slider_set_mode(ui_fanSpeedSlider, LV_SLIDER_MODE_RANGE);
lv_slider_set_value( ui_fanSpeedSlider, 20, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_fanSpeedSlider)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_fanSpeedSlider, 5, LV_ANIM_OFF);
lv_obj_set_width( ui_fanSpeedSlider, 20);
lv_obj_set_height( ui_fanSpeedSlider, 400);
lv_obj_set_x( ui_fanSpeedSlider, 37 );
lv_obj_set_y( ui_fanSpeedSlider, -3 );
lv_obj_set_align( ui_fanSpeedSlider, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_fanSpeedSlider, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags


ui_Fan3 = lv_img_create(ui_Panel13);
lv_img_set_src(ui_Fan3, &ui_img_1142205948);
lv_obj_set_width( ui_Fan3, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Fan3, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Fan3, -31 );
lv_obj_set_y( ui_Fan3, 0 );
lv_obj_set_align( ui_Fan3, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Fan3, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Fan3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_FanSpeedMinLabel = lv_label_create(ui_Panel13);
lv_obj_set_width( ui_FanSpeedMinLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_FanSpeedMinLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_FanSpeedMinLabel, -31 );
lv_obj_set_y( ui_FanSpeedMinLabel, 60 );
lv_obj_set_align( ui_FanSpeedMinLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_FanSpeedMinLabel,"100%");
lv_obj_set_style_text_align(ui_FanSpeedMinLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_FanSpeedMinLabel, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_FanSpeedMaxLabel = lv_label_create(ui_Panel13);
lv_obj_set_width( ui_FanSpeedMaxLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_FanSpeedMaxLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_FanSpeedMaxLabel, -31 );
lv_obj_set_y( ui_FanSpeedMaxLabel, -60 );
lv_obj_set_align( ui_FanSpeedMaxLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_FanSpeedMaxLabel,"100%");
lv_obj_set_style_text_align(ui_FanSpeedMaxLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_FanSpeedMaxLabel, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_FanSpeedLabel3 = lv_label_create(ui_Panel13);
lv_obj_set_width( ui_FanSpeedLabel3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_FanSpeedLabel3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_FanSpeedLabel3, -52 );
lv_obj_set_y( ui_FanSpeedLabel3, -204 );
lv_obj_set_align( ui_FanSpeedLabel3, LV_ALIGN_CENTER );
lv_label_set_text(ui_FanSpeedLabel3,"-%");
lv_obj_set_style_text_align(ui_FanSpeedLabel3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_HumidityDropdown, ui_event_HumidityDropdown, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TemperatureDropdown, ui_event_TemperatureDropdown, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ClimateModeSwitch, ui_event_ClimateModeSwitch, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TempUnitSwitch, ui_event_TempUnitSwitch, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_fanSpeedSlider, ui_event_fanSpeedSlider, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ClimateControlScreen, ui_event_ClimateControlScreen, LV_EVENT_ALL, NULL);

}
