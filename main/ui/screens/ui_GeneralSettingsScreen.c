// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_GeneralSettingsScreen_screen_init(void)
{
ui_GeneralSettingsScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_GeneralSettingsScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GeneralSettingsScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GeneralSettingsScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label23 = lv_label_create(ui_GeneralSettingsScreen);
lv_obj_set_width( ui_Label23, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label23, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label23, 6 );
lv_obj_set_y( ui_Label23, -106 );
lv_obj_set_align( ui_Label23, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label23,"General Settings");
lv_obj_set_style_text_font(ui_Label23, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel12 = lv_obj_create(ui_GeneralSettingsScreen);
lv_obj_set_width( ui_Panel12, 456);
lv_obj_set_height( ui_Panel12, 100);
lv_obj_set_x( ui_Panel12, -1 );
lv_obj_set_y( ui_Panel12, 88 );
lv_obj_set_align( ui_Panel12, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel12, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel12, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel12, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel12, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label24 = lv_label_create(ui_Panel12);
lv_obj_set_width( ui_Label24, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label24, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label24, -138 );
lv_obj_set_y( ui_Label24, -28 );
lv_obj_set_align( ui_Label24, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label24,"Display Brightness:");
lv_obj_set_style_text_font(ui_Label24, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Slider3 = lv_slider_create(ui_Panel12);
lv_obj_set_width( ui_Slider3, 400);
lv_obj_set_height( ui_Slider3, 30);
lv_obj_set_x( ui_Slider3, 0 );
lv_obj_set_y( ui_Slider3, 18 );
lv_obj_set_align( ui_Slider3, LV_ALIGN_CENTER );

ui_Label25 = lv_label_create(ui_Panel12);
lv_obj_set_width( ui_Label25, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label25, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label25, -30 );
lv_obj_set_y( ui_Label25, -28 );
lv_obj_set_align( ui_Label25, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label25,"25%");

ui_Image17 = lv_img_create(ui_GeneralSettingsScreen);
lv_img_set_src(ui_Image17, &ui_img_upload_png);
lv_obj_set_width( ui_Image17, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_Image17, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_Image17, 1 );
lv_obj_set_y( ui_Image17, -145 );
lv_obj_set_align( ui_Image17, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image17, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image17, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_img_recolor(ui_Image17, lv_color_hex(0x145B0A), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_Image17, 200, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel18 = lv_obj_create(ui_GeneralSettingsScreen);
lv_obj_set_width( ui_Panel18, 188);
lv_obj_set_height( ui_Panel18, 54);
lv_obj_set_x( ui_Panel18, -133 );
lv_obj_set_y( ui_Panel18, -2 );
lv_obj_set_align( ui_Panel18, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel18, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel18, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel18, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel18, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Switch4 = lv_switch_create(ui_Panel18);
lv_obj_set_width( ui_Switch4, 50);
lv_obj_set_height( ui_Switch4, 25);
lv_obj_set_x( ui_Switch4, -58 );
lv_obj_set_y( ui_Switch4, 1 );
lv_obj_set_align( ui_Switch4, LV_ALIGN_CENTER );

ui_Label26 = lv_label_create(ui_Panel18);
lv_obj_set_width( ui_Label26, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label26, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label26, 27 );
lv_obj_set_y( ui_Label26, 0 );
lv_obj_set_align( ui_Label26, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label26,"QR Code on\nHomeScreen");
lv_obj_set_style_text_font(ui_Label26, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel17 = lv_obj_create(ui_GeneralSettingsScreen);
lv_obj_set_width( ui_Panel17, 188);
lv_obj_set_height( ui_Panel17, 54);
lv_obj_set_x( ui_Panel17, 85 );
lv_obj_set_y( ui_Panel17, -2 );
lv_obj_set_align( ui_Panel17, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel17, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel17, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel17, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel17, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Switch3 = lv_switch_create(ui_Panel17);
lv_obj_set_width( ui_Switch3, 50);
lv_obj_set_height( ui_Switch3, 25);
lv_obj_set_align( ui_Switch3, LV_ALIGN_CENTER );

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

ui_Image20 = lv_img_create(ui_GeneralSettingsScreen);
lv_img_set_src(ui_Image20, &ui_img_tomato_png);
lv_obj_set_width( ui_Image20, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image20, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image20, -185 );
lv_obj_set_y( ui_Image20, -108 );
lv_obj_set_align( ui_Image20, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image20, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image20, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_GeneralSettingsScreen, ui_event_GeneralSettingsScreen, LV_EVENT_ALL, NULL);

}
