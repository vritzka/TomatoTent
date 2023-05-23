// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_SettingsScreen_screen_init(void)
{
ui_SettingsScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SettingsScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SettingsScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SettingsScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel6 = lv_obj_create(ui_SettingsScreen);
lv_obj_set_width( ui_Panel6, 408);
lv_obj_set_height( ui_Panel6, 77);
lv_obj_set_x( ui_Panel6, 1 );
lv_obj_set_y( ui_Panel6, 75 );
lv_obj_set_align( ui_Panel6, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel6, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Slider4 = lv_slider_create(ui_Panel6);
lv_slider_set_range(ui_Slider4, 10,100);
lv_slider_set_value( ui_Slider4, 50, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_Slider4)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_Slider4, 10, LV_ANIM_OFF);
lv_obj_set_width( ui_Slider4, 300);
lv_obj_set_height( ui_Slider4, 10);
lv_obj_set_x( ui_Slider4, 7 );
lv_obj_set_y( ui_Slider4, -4 );
lv_obj_set_align( ui_Slider4, LV_ALIGN_CENTER );

ui_LCDBrightness = lv_label_create(ui_Panel6);
lv_obj_set_width( ui_LCDBrightness, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LCDBrightness, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LCDBrightness, -16 );
lv_obj_set_y( ui_LCDBrightness, 14 );
lv_obj_set_align( ui_LCDBrightness, LV_ALIGN_BOTTOM_MID );
lv_label_set_text(ui_LCDBrightness,"");

lv_obj_add_event_cb(ui_Slider4, ui_event_Slider4, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_SettingsScreen, ui_event_SettingsScreen, LV_EVENT_ALL, NULL);

}