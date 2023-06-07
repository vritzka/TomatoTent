// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_WifiSettingsScreen_screen_init(void)
{
ui_WifiSettingsScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_WifiSettingsScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_WifiSettingsScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_WifiSettingsScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Keyboard2 = lv_keyboard_create(ui_WifiSettingsScreen);
lv_keyboard_set_mode(ui_Keyboard2,LV_KEYBOARD_MODE_USER_1);
lv_obj_set_width( ui_Keyboard2, 480);
lv_obj_set_height( ui_Keyboard2, 130);
lv_obj_set_x( ui_Keyboard2, 0 );
lv_obj_set_y( ui_Keyboard2, 95 );
lv_obj_set_align( ui_Keyboard2, LV_ALIGN_CENTER );

ui_WifiPasword = lv_textarea_create(ui_WifiSettingsScreen);
lv_obj_set_width( ui_WifiPasword, 218);
lv_obj_set_height( ui_WifiPasword, 43);
lv_obj_set_x( ui_WifiPasword, -111 );
lv_obj_set_y( ui_WifiPasword, -14 );
lv_obj_set_align( ui_WifiPasword, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_WifiPasword,"WiFi Password");

ui_WifiDropdown = lv_dropdown_create(ui_WifiSettingsScreen);
lv_obj_set_width( ui_WifiDropdown, 150);
lv_obj_set_height( ui_WifiDropdown, 43);
lv_obj_set_x( ui_WifiDropdown, 104 );
lv_obj_set_y( ui_WifiDropdown, -14 );
lv_obj_set_align( ui_WifiDropdown, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_WifiDropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags

ui_Image13 = lv_img_create(ui_WifiSettingsScreen);
lv_img_set_src(ui_Image13, &ui_img_953604683);
lv_obj_set_width( ui_Image13, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image13, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image13, -185 );
lv_obj_set_y( ui_Image13, -108 );
lv_obj_set_align( ui_Image13, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image13, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image13, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_WifiSwitch = lv_switch_create(ui_WifiSettingsScreen);
lv_obj_set_width( ui_WifiSwitch, 50);
lv_obj_set_height( ui_WifiSwitch, 25);
lv_obj_set_x( ui_WifiSwitch, -92 );
lv_obj_set_y( ui_WifiSwitch, -113 );
lv_obj_set_align( ui_WifiSwitch, LV_ALIGN_CENTER );
lv_obj_set_style_bg_color(ui_WifiSwitch, lv_color_hex(0x7E7E7E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_WifiSwitch, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label21 = lv_label_create(ui_WifiSettingsScreen);
lv_obj_set_width( ui_Label21, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label21, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label21, 21 );
lv_obj_set_y( ui_Label21, 90 );
lv_label_set_text(ui_Label21,"connected");

ui_ImgButton4 = lv_imgbtn_create(ui_WifiSettingsScreen);
lv_imgbtn_set_src(ui_ImgButton4, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_refresh_png, NULL);
lv_imgbtn_set_src(ui_ImgButton4, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_refresh_png, NULL);
lv_obj_set_height( ui_ImgButton4, 35);
lv_obj_set_width( ui_ImgButton4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_x( ui_ImgButton4, 210 );
lv_obj_set_y( ui_ImgButton4, -14 );
lv_obj_set_align( ui_ImgButton4, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_ImgButton4, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ImgButton4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ImgButton4, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ImgButton4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_opa(ui_ImgButton4, 50, LV_PART_MAIN| LV_STATE_PRESSED);

ui_ImgButton7 = lv_imgbtn_create(ui_WifiSettingsScreen);
lv_imgbtn_set_src(ui_ImgButton7, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_1668913270, NULL);
lv_obj_set_width( ui_ImgButton7, 32);
lv_obj_set_height( ui_ImgButton7, 32);
lv_obj_set_x( ui_ImgButton7, 203 );
lv_obj_set_y( ui_ImgButton7, -126 );
lv_obj_set_align( ui_ImgButton7, LV_ALIGN_CENTER );
lv_obj_set_style_img_recolor(ui_ImgButton7, lv_color_hex(0xC3C3C3), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_ImgButton7, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_keyboard_set_textarea(ui_Keyboard2,ui_WifiPasword);
lv_obj_add_event_cb(ui_WifiSwitch, ui_event_WifiSwitch, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ImgButton7, ui_event_ImgButton7, LV_EVENT_ALL, NULL);

}
