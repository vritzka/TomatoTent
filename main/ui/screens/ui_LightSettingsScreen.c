// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_LightSettingsScreen_screen_init(void)
{
ui_LightSettingsScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_LightSettingsScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_LightSettingsScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LightSettingsScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel8 = lv_obj_create(ui_LightSettingsScreen);
lv_obj_set_width( ui_Panel8, 450);
lv_obj_set_height( ui_Panel8, 89);
lv_obj_set_x( ui_Panel8, -4 );
lv_obj_set_y( ui_Panel8, -99 );
lv_obj_set_align( ui_Panel8, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel8, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LightDurationSlider = lv_slider_create(ui_Panel8);
lv_slider_set_range(ui_LightDurationSlider, 0,48);
lv_slider_set_value( ui_LightDurationSlider, 20, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_LightDurationSlider)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_LightDurationSlider, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_LightDurationSlider, 400);
lv_obj_set_height( ui_LightDurationSlider, 30);
lv_obj_set_x( ui_LightDurationSlider, -1 );
lv_obj_set_y( ui_LightDurationSlider, 17 );
lv_obj_set_align( ui_LightDurationSlider, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_LightDurationSlider, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_LightDurationSlider, lv_color_hex(0x17006B), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LightDurationSlider, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_LightDurationSlider, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_LightDurationSlider, lv_color_hex(0xF0EB00), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LightDurationSlider, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_LightDurationSlider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LightDurationSlider, 200, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_LightDurationSlider, &ui_img_303216376, LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_img_opa(ui_LightDurationSlider, 255, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_Label14 = lv_label_create(ui_Panel8);
lv_obj_set_width( ui_Label14, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label14, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label14, -153 );
lv_obj_set_y( ui_Label14, -26 );
lv_obj_set_align( ui_Label14, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label14,"Light: 12 hrs");
lv_obj_set_style_text_font(ui_Label14, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label12 = lv_label_create(ui_Panel8);
lv_obj_set_width( ui_Label12, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label12, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label12, 147 );
lv_obj_set_y( ui_Label12, -26 );
lv_obj_set_align( ui_Label12, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label12,"Dark: 11 hrs");
lv_obj_set_style_text_font(ui_Label12, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel9 = lv_obj_create(ui_LightSettingsScreen);
lv_obj_set_width( ui_Panel9, 450);
lv_obj_set_height( ui_Panel9, 89);
lv_obj_set_x( ui_Panel9, -1 );
lv_obj_set_y( ui_Panel9, 73 );
lv_obj_set_align( ui_Panel9, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel9, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel9, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel9, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Slider1 = lv_slider_create(ui_Panel9);
lv_slider_set_value( ui_Slider1, 20, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_Slider1)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_Slider1, 10, LV_ANIM_OFF);
lv_obj_set_width( ui_Slider1, 400);
lv_obj_set_height( ui_Slider1, 30);
lv_obj_set_x( ui_Slider1, -1 );
lv_obj_set_y( ui_Slider1, 17 );
lv_obj_set_align( ui_Slider1, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_Slider1, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0xE8FF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Slider1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0xE8FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Slider1, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Slider1, 200, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Slider1, &ui_img_303216376, LV_PART_KNOB | LV_STATE_DEFAULT );

ui_Label16 = lv_label_create(ui_Panel9);
lv_obj_set_width( ui_Label16, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label16, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label16, -42 );
lv_obj_set_y( ui_Label16, -26 );
lv_obj_set_align( ui_Label16, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label16,"Grow Lamp Brightness:");
lv_obj_set_style_text_font(ui_Label16, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label17 = lv_label_create(ui_Panel9);
lv_obj_set_width( ui_Label17, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label17, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label17, 87 );
lv_obj_set_y( ui_Label17, -26 );
lv_obj_set_align( ui_Label17, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label17,"80%");
lv_obj_set_style_text_font(ui_Label17, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_LightDurationSlider, ui_event_LightDurationSlider, LV_EVENT_ALL, NULL);

}