// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_FanSettingsScreen_screen_init(void)
{
ui_FanSettingsScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_FanSettingsScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_FanSettingsScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_FanSettingsScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label14 = lv_label_create(ui_FanSettingsScreen);
lv_obj_set_width( ui_Label14, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label14, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label14, -63 );
lv_obj_set_y( ui_Label14, -110 );
lv_obj_set_align( ui_Label14, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label14,"Fan Speed");
lv_obj_set_style_text_font(ui_Label14, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image12 = lv_img_create(ui_FanSettingsScreen);
lv_img_set_src(ui_Image12, &ui_img_1142205948);
lv_obj_set_width( ui_Image12, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image12, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image12, -185 );
lv_obj_set_y( ui_Image12, -108 );
lv_obj_set_align( ui_Image12, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image12, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image12, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel13 = lv_obj_create(ui_FanSettingsScreen);
lv_obj_set_width( ui_Panel13, 456);
lv_obj_set_height( ui_Panel13, 100);
lv_obj_set_x( ui_Panel13, 1 );
lv_obj_set_y( ui_Panel13, 52 );
lv_obj_set_align( ui_Panel13, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel13, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel13, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel13, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fanSpeedSlider = lv_slider_create(ui_Panel13);
lv_slider_set_mode(ui_fanSpeedSlider, LV_SLIDER_MODE_RANGE);
lv_slider_set_value( ui_fanSpeedSlider, 20, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_fanSpeedSlider)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_fanSpeedSlider, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_fanSpeedSlider, 400);
lv_obj_set_height( ui_fanSpeedSlider, 30);
lv_obj_set_x( ui_fanSpeedSlider, 1 );
lv_obj_set_y( ui_fanSpeedSlider, 14 );
lv_obj_set_align( ui_fanSpeedSlider, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_fanSpeedSlider, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags

ui_ImgButton5 = lv_imgbtn_create(ui_FanSettingsScreen);
lv_imgbtn_set_src(ui_ImgButton5, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_1668913270, NULL);
lv_obj_set_width( ui_ImgButton5, 32);
lv_obj_set_height( ui_ImgButton5, 32);
lv_obj_set_x( ui_ImgButton5, 203 );
lv_obj_set_y( ui_ImgButton5, -126 );
lv_obj_set_align( ui_ImgButton5, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ImgButton5, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_set_style_img_recolor(ui_ImgButton5, lv_color_hex(0xC3C3C3), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_ImgButton5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_FanSpeedMinLabel = lv_label_create(ui_FanSettingsScreen);
lv_obj_set_width( ui_FanSpeedMinLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_FanSpeedMinLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_FanSpeedMinLabel, -263 );
lv_obj_set_y( ui_FanSpeedMinLabel, -40 );
lv_obj_set_align( ui_FanSpeedMinLabel, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_FanSpeedMinLabel,"100%");
lv_obj_set_style_text_font(ui_FanSpeedMinLabel, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_FanSpeedMaxLabel = lv_label_create(ui_FanSettingsScreen);
lv_obj_set_width( ui_FanSpeedMaxLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_FanSpeedMaxLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_FanSpeedMaxLabel, 270 );
lv_obj_set_y( ui_FanSpeedMaxLabel, -40 );
lv_obj_set_align( ui_FanSpeedMaxLabel, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_FanSpeedMaxLabel,"100%");
lv_obj_set_style_text_font(ui_FanSpeedMaxLabel, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label25 = lv_label_create(ui_FanSettingsScreen);
lv_obj_set_width( ui_Label25, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label25, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label25, 0 );
lv_obj_set_y( ui_Label25, -39 );
lv_obj_set_align( ui_Label25, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label25,"-");
lv_obj_set_style_text_font(ui_Label25, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_fanSpeedSlider, ui_event_fanSpeedSlider, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ImgButton5, ui_event_ImgButton5, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_FanSettingsScreen, ui_event_FanSettingsScreen, LV_EVENT_ALL, NULL);

}
