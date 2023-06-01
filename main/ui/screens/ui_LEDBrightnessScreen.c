// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_LEDBrightnessScreen_screen_init(void)
{
ui_LEDBrightnessScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_LEDBrightnessScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_LEDBrightnessScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LEDBrightnessScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LCDBrightnessLabel = lv_label_create(ui_LEDBrightnessScreen);
lv_obj_set_width( ui_LCDBrightnessLabel, LV_SIZE_CONTENT);  /// 0
lv_obj_set_height( ui_LCDBrightnessLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LCDBrightnessLabel, 125 );
lv_obj_set_y( ui_LCDBrightnessLabel, -93 );
lv_obj_set_align( ui_LCDBrightnessLabel, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_LCDBrightnessLabel,"50%");
lv_obj_set_style_text_font(ui_LCDBrightnessLabel, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_arrowdown1 = lv_img_create(ui_LEDBrightnessScreen);
lv_img_set_src(ui_arrowdown1, &ui_img_upload_png);
lv_obj_set_width( ui_arrowdown1, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_arrowdown1, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_arrowdown1, 221 );
lv_obj_set_y( ui_arrowdown1, 0 );
lv_obj_set_align( ui_arrowdown1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_arrowdown1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_arrowdown1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_angle(ui_arrowdown1,900);
lv_obj_set_style_img_recolor(ui_arrowdown1, lv_color_hex(0x145B0A), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_arrowdown1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label12 = lv_label_create(ui_LEDBrightnessScreen);
lv_obj_set_width( ui_Label12, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label12, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label12, -82 );
lv_obj_set_y( ui_Label12, -16 );
lv_obj_set_align( ui_Label12, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label12,"LED Brightness");
lv_obj_set_style_text_font(ui_Label12, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image4 = lv_img_create(ui_LEDBrightnessScreen);
lv_img_set_src(ui_Image4, &ui_img_1756057095);
lv_obj_set_width( ui_Image4, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image4, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image4, -162 );
lv_obj_set_y( ui_Image4, -86 );
lv_obj_set_align( ui_Image4, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image4, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel6 = lv_obj_create(ui_LEDBrightnessScreen);
lv_obj_set_width( ui_Panel6, 480);
lv_obj_set_height( ui_Panel6, 131);
lv_obj_set_x( ui_Panel6, 0 );
lv_obj_set_y( ui_Panel6, 94 );
lv_obj_set_align( ui_Panel6, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel6, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel6, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel6, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Slider4 = lv_slider_create(ui_Panel6);
lv_slider_set_range(ui_Slider4, 10,100);
lv_slider_set_value( ui_Slider4, 50, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_Slider4)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_Slider4, 10, LV_ANIM_OFF);
lv_obj_set_width( ui_Slider4, 400);
lv_obj_set_height( ui_Slider4, 30);
lv_obj_set_x( ui_Slider4, 0 );
lv_obj_set_y( ui_Slider4, -16 );
lv_obj_set_align( ui_Slider4, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Slider4, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags
lv_obj_set_style_radius(ui_Slider4, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Slider4, lv_color_hex(0xFFFE2B), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Slider4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Slider4, lv_color_hex(0xFFFE2B), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Slider4, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Slider4, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Slider4, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_Slider4, &ui_img_320680866, LV_PART_KNOB | LV_STATE_DEFAULT );

ui_arrowdown2 = lv_img_create(ui_LEDBrightnessScreen);
lv_img_set_src(ui_arrowdown2, &ui_img_upload_png);
lv_obj_set_width( ui_arrowdown2, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_arrowdown2, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_arrowdown2, -223 );
lv_obj_set_y( ui_arrowdown2, 0 );
lv_obj_set_align( ui_arrowdown2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_arrowdown2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_arrowdown2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_angle(ui_arrowdown2,2700);
lv_obj_set_style_img_recolor(ui_arrowdown2, lv_color_hex(0x145B0A), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_arrowdown2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_Slider4, ui_event_Slider4, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_LEDBrightnessScreen, ui_event_LEDBrightnessScreen, LV_EVENT_ALL, NULL);

}
