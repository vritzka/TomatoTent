// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_LightDurationScreen_screen_init(void)
{
ui_LightDurationScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_LightDurationScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_LightDurationScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LightDurationScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_LightDurationScreen, lv_color_hex(0x0A002D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_main_stop(ui_LightDurationScreen, 110, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_stop(ui_LightDurationScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_dir(ui_LightDurationScreen, LV_GRAD_DIR_HOR, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel8 = lv_obj_create(ui_LightDurationScreen);
lv_obj_set_width( ui_Panel8, 480);
lv_obj_set_height( ui_Panel8, 147);
lv_obj_set_x( ui_Panel8, 0 );
lv_obj_set_y( ui_Panel8, 86 );
lv_obj_set_align( ui_Panel8, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel8, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_border_width(ui_Panel8, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_LightDurationSlider = lv_slider_create(ui_Panel8);
lv_slider_set_range(ui_LightDurationSlider, 0,48);
lv_slider_set_value( ui_LightDurationSlider, 20, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_LightDurationSlider)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_LightDurationSlider, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_LightDurationSlider, 400);
lv_obj_set_height( ui_LightDurationSlider, 30);
lv_obj_set_x( ui_LightDurationSlider, 0 );
lv_obj_set_y( ui_LightDurationSlider, -24 );
lv_obj_set_align( ui_LightDurationSlider, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_LightDurationSlider, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags
lv_obj_set_style_radius(ui_LightDurationSlider, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_LightDurationSlider, lv_color_hex(0x17006B), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LightDurationSlider, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_LightDurationSlider, lv_color_hex(0xECECEC), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_LightDurationSlider, 100, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_LightDurationSlider, 1, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_LightDurationSlider, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_LightDurationSlider, lv_color_hex(0xF6CF06), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LightDurationSlider, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_LightDurationSlider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LightDurationSlider, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_LightDurationSlider, &ui_img_303216376, LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_img_opa(ui_LightDurationSlider, 255, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_NowSlider = lv_slider_create(ui_Panel8);
lv_slider_set_value( ui_NowSlider, 20, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_NowSlider)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_NowSlider, 10, LV_ANIM_OFF);
lv_obj_set_width( ui_NowSlider, 400);
lv_obj_set_height( ui_NowSlider, 30);
lv_obj_set_x( ui_NowSlider, 0 );
lv_obj_set_y( ui_NowSlider, 43 );
lv_obj_set_align( ui_NowSlider, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_NowSlider, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags
lv_obj_set_style_bg_color(ui_NowSlider, lv_color_hex(0xE8FF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_NowSlider, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_NowSlider, lv_color_hex(0xE8FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_NowSlider, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_NowSlider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_NowSlider, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_NowSlider, &ui_img_now_arrow_2_png, LV_PART_KNOB | LV_STATE_DEFAULT );

ui_Image8 = lv_img_create(ui_LightDurationScreen);
lv_img_set_src(ui_Image8, &ui_img_791711567);
lv_obj_set_width( ui_Image8, LV_SIZE_CONTENT);  /// 128
lv_obj_set_height( ui_Image8, LV_SIZE_CONTENT);   /// 128
lv_obj_set_x( ui_Image8, -176 );
lv_obj_set_y( ui_Image8, -94 );
lv_obj_set_align( ui_Image8, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image8, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image8, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image9 = lv_img_create(ui_LightDurationScreen);
lv_img_set_src(ui_Image9, &ui_img_432815713);
lv_obj_set_width( ui_Image9, LV_SIZE_CONTENT);  /// 128
lv_obj_set_height( ui_Image9, LV_SIZE_CONTENT);   /// 128
lv_obj_set_x( ui_Image9, 172 );
lv_obj_set_y( ui_Image9, -92 );
lv_obj_set_align( ui_Image9, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image9, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image9, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_ArrowDown = lv_img_create(ui_LightDurationScreen);
lv_img_set_src(ui_ArrowDown, &ui_img_upload_png);
lv_obj_set_width( ui_ArrowDown, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_ArrowDown, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_ArrowDown, 219 );
lv_obj_set_y( ui_ArrowDown, 0 );
lv_obj_set_align( ui_ArrowDown, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ArrowDown, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_ArrowDown, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_angle(ui_ArrowDown,900);
lv_obj_set_style_img_recolor(ui_ArrowDown, lv_color_hex(0x145B0A), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_ArrowDown, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ArrowUp = lv_img_create(ui_LightDurationScreen);
lv_img_set_src(ui_ArrowUp, &ui_img_upload_png);
lv_obj_set_width( ui_ArrowUp, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_ArrowUp, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_ArrowUp, -223 );
lv_obj_set_y( ui_ArrowUp, 0 );
lv_obj_set_align( ui_ArrowUp, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ArrowUp, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_ArrowUp, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_angle(ui_ArrowUp,2700);
lv_obj_set_style_img_recolor(ui_ArrowUp, lv_color_hex(0x145B0A), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_ArrowUp, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LightDurationLightLabel = lv_label_create(ui_LightDurationScreen);
lv_obj_set_width( ui_LightDurationLightLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LightDurationLightLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LightDurationLightLabel, -74 );
lv_obj_set_y( ui_LightDurationLightLabel, -71 );
lv_obj_set_align( ui_LightDurationLightLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_LightDurationLightLabel,"12 hrs");
lv_obj_set_style_text_font(ui_LightDurationLightLabel, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LightDurationDarkLabel = lv_label_create(ui_LightDurationScreen);
lv_obj_set_width( ui_LightDurationDarkLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LightDurationDarkLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LightDurationDarkLabel, 68 );
lv_obj_set_y( ui_LightDurationDarkLabel, -69 );
lv_obj_set_align( ui_LightDurationDarkLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_LightDurationDarkLabel,"12 hrs");
lv_obj_set_style_text_font(ui_LightDurationDarkLabel, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_LightDurationSlider, ui_event_LightDurationSlider, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_LightDurationScreen, ui_event_LightDurationScreen, LV_EVENT_ALL, NULL);

}
