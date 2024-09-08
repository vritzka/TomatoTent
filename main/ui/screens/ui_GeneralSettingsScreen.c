// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_GeneralSettingsScreen_screen_init(void)
{
ui_GeneralSettingsScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_GeneralSettingsScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GeneralSettingsScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GeneralSettingsScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image20 = lv_img_create(ui_GeneralSettingsScreen);
lv_img_set_src(ui_Image20, &ui_img_tomato_png);
lv_obj_set_width( ui_Image20, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image20, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image20, -326 );
lv_obj_set_y( ui_Image20, -202 );
lv_obj_set_align( ui_Image20, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image20, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image20, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label23 = lv_label_create(ui_GeneralSettingsScreen);
lv_obj_set_width( ui_Label23, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label23, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label23, -325 );
lv_obj_set_y( ui_Label23, -141 );
lv_obj_set_align( ui_Label23, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label23,"Settings");
lv_obj_set_style_text_font(ui_Label23, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel12 = lv_obj_create(ui_GeneralSettingsScreen);
lv_obj_set_width( ui_Panel12, 94);
lv_obj_set_height( ui_Panel12, 456);
lv_obj_set_x( ui_Panel12, -174 );
lv_obj_set_y( ui_Panel12, -3 );
lv_obj_set_align( ui_Panel12, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel12, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel12, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel12, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel12, 40, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel12, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label24 = lv_label_create(ui_Panel12);
lv_obj_set_width( ui_Label24, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label24, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label24, 0 );
lv_obj_set_y( ui_Label24, -187 );
lv_obj_set_align( ui_Label24, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label24,"Display");
lv_obj_set_style_text_align(ui_Label24, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label24, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ScreenBrightnessSlider = lv_slider_create(ui_Panel12);
lv_slider_set_range(ui_ScreenBrightnessSlider, 1,100);
lv_slider_set_value( ui_ScreenBrightnessSlider, 80, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_ScreenBrightnessSlider)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_ScreenBrightnessSlider, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_ScreenBrightnessSlider, 20);
lv_obj_set_height( ui_ScreenBrightnessSlider, 320);
lv_obj_set_x( ui_ScreenBrightnessSlider, 0 );
lv_obj_set_y( ui_ScreenBrightnessSlider, 25 );
lv_obj_set_align( ui_ScreenBrightnessSlider, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ScreenBrightnessSlider, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ScreenBrightnessSlider, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ScreenBrightnessSlider, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_ScreenBrightnessSlider, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ScreenBrightnessSlider, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_ScreenBrightnessSlider, 3, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ScreenBrightnessSlider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ScreenBrightnessSlider, 255, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_SoftwareUpdatePanel = lv_obj_create(ui_GeneralSettingsScreen);
lv_obj_set_width( ui_SoftwareUpdatePanel, 270);
lv_obj_set_height( ui_SoftwareUpdatePanel, 140);
lv_obj_set_x( ui_SoftwareUpdatePanel, 44 );
lv_obj_set_y( ui_SoftwareUpdatePanel, -159 );
lv_obj_set_align( ui_SoftwareUpdatePanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SoftwareUpdatePanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_SoftwareUpdatePanel, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_SoftwareUpdatePanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SoftwareUpdatePanel, 40, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_SoftwareUpdatePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_SoftwareUpdatePanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CurrentVersionLabel = lv_label_create(ui_SoftwareUpdatePanel);
lv_obj_set_width( ui_CurrentVersionLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_CurrentVersionLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_CurrentVersionLabel, 0 );
lv_obj_set_y( ui_CurrentVersionLabel, -50 );
lv_obj_set_align( ui_CurrentVersionLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_CurrentVersionLabel,"Software v");
lv_obj_set_style_text_align(ui_CurrentVersionLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_CurrentVersionLabel, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_UpgradeStatusBar = lv_bar_create(ui_SoftwareUpdatePanel);
lv_obj_set_width( ui_UpgradeStatusBar, 220);
lv_obj_set_height( ui_UpgradeStatusBar, 15);
lv_obj_set_x( ui_UpgradeStatusBar, 0 );
lv_obj_set_y( ui_UpgradeStatusBar, 42 );
lv_obj_set_align( ui_UpgradeStatusBar, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_UpgradeStatusBar, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_UpgradeStatusBar, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_UpgradeStatusBar, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_UpgradeStatusBar, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
ui_object_set_themeable_style_property(ui_UpgradeStatusBar, LV_PART_INDICATOR| LV_STATE_DEFAULT, LV_STYLE_BG_COLOR, _ui_theme_color_gray1);
ui_object_set_themeable_style_property(ui_UpgradeStatusBar, LV_PART_INDICATOR| LV_STATE_DEFAULT, LV_STYLE_BG_OPA, _ui_theme_alpha_gray1);

ui_FirmwareUpgradeButton = lv_btn_create(ui_SoftwareUpdatePanel);
lv_obj_set_width( ui_FirmwareUpgradeButton, 100);
lv_obj_set_height( ui_FirmwareUpgradeButton, 30);
lv_obj_set_x( ui_FirmwareUpgradeButton, 0 );
lv_obj_set_y( ui_FirmwareUpgradeButton, -6 );
lv_obj_set_align( ui_FirmwareUpgradeButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_FirmwareUpgradeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_FirmwareUpgradeButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_FirmwareUpgradeButton, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
ui_object_set_themeable_style_property(ui_FirmwareUpgradeButton, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BG_COLOR, _ui_theme_color_gray1);
ui_object_set_themeable_style_property(ui_FirmwareUpgradeButton, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BG_OPA, _ui_theme_alpha_gray1);

ui_Label21 = lv_label_create(ui_FirmwareUpgradeButton);
lv_obj_set_width( ui_Label21, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label21, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label21, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label21,"Upgrade");

ui_Panel1 = lv_obj_create(ui_GeneralSettingsScreen);
lv_obj_set_width( ui_Panel1, 194);
lv_obj_set_height( ui_Panel1, 267);
lv_obj_set_x( ui_Panel1, -12 );
lv_obj_set_y( ui_Panel1, -12 );
lv_obj_set_align( ui_Panel1, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_clear_flag( ui_Panel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel1, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel1, 40, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Panel1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_DimmerPolarityContainer = lv_obj_create(ui_Panel1);
lv_obj_remove_style_all(ui_DimmerPolarityContainer);
lv_obj_set_width( ui_DimmerPolarityContainer, 56);
lv_obj_set_height( ui_DimmerPolarityContainer, 236);
lv_obj_set_x( ui_DimmerPolarityContainer, 57 );
lv_obj_set_y( ui_DimmerPolarityContainer, 0 );
lv_obj_set_align( ui_DimmerPolarityContainer, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_DimmerPolarityContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_PolaritySwitch1 = lv_switch_create(ui_DimmerPolarityContainer);
lv_obj_set_width( ui_PolaritySwitch1, 50);
lv_obj_set_height( ui_PolaritySwitch1, 25);
lv_obj_set_x( ui_PolaritySwitch1, 3 );
lv_obj_set_y( ui_PolaritySwitch1, -100 );
lv_obj_set_align( ui_PolaritySwitch1, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_PolaritySwitch1, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_PolaritySwitch1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PolaritySwitch1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_PolaritySwitch1, 3, LV_PART_INDICATOR| LV_STATE_DEFAULT);
ui_object_set_themeable_style_property(ui_PolaritySwitch1, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_COLOR, _ui_theme_color_Green1);
ui_object_set_themeable_style_property(ui_PolaritySwitch1, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_OPA, _ui_theme_alpha_Green1);

lv_obj_set_style_radius(ui_PolaritySwitch1, 3, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_PolaritySwitch2 = lv_switch_create(ui_DimmerPolarityContainer);
lv_obj_set_width( ui_PolaritySwitch2, 50);
lv_obj_set_height( ui_PolaritySwitch2, 25);
lv_obj_set_x( ui_PolaritySwitch2, 3 );
lv_obj_set_y( ui_PolaritySwitch2, -60 );
lv_obj_set_align( ui_PolaritySwitch2, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_PolaritySwitch2, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_PolaritySwitch2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PolaritySwitch2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
ui_object_set_themeable_style_property(ui_PolaritySwitch2, LV_PART_MAIN| LV_STATE_CHECKED, LV_STYLE_BG_COLOR, _ui_theme_color_Green1);
ui_object_set_themeable_style_property(ui_PolaritySwitch2, LV_PART_MAIN| LV_STATE_CHECKED, LV_STYLE_BG_OPA, _ui_theme_alpha_Green1);

lv_obj_set_style_radius(ui_PolaritySwitch2, 3, LV_PART_INDICATOR| LV_STATE_DEFAULT);
ui_object_set_themeable_style_property(ui_PolaritySwitch2, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_COLOR, _ui_theme_color_Green1);
ui_object_set_themeable_style_property(ui_PolaritySwitch2, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_OPA, _ui_theme_alpha_Green1);

lv_obj_set_style_radius(ui_PolaritySwitch2, 3, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_PolaritySwitch3 = lv_switch_create(ui_DimmerPolarityContainer);
lv_obj_set_width( ui_PolaritySwitch3, 50);
lv_obj_set_height( ui_PolaritySwitch3, 25);
lv_obj_set_x( ui_PolaritySwitch3, 3 );
lv_obj_set_y( ui_PolaritySwitch3, -20 );
lv_obj_set_align( ui_PolaritySwitch3, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_PolaritySwitch3, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_PolaritySwitch3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PolaritySwitch3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_PolaritySwitch3, 3, LV_PART_INDICATOR| LV_STATE_DEFAULT);
ui_object_set_themeable_style_property(ui_PolaritySwitch3, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_COLOR, _ui_theme_color_Green1);
ui_object_set_themeable_style_property(ui_PolaritySwitch3, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_OPA, _ui_theme_alpha_Green1);

lv_obj_set_style_radius(ui_PolaritySwitch3, 3, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_PolaritySwitch4 = lv_switch_create(ui_DimmerPolarityContainer);
lv_obj_set_width( ui_PolaritySwitch4, 50);
lv_obj_set_height( ui_PolaritySwitch4, 25);
lv_obj_set_x( ui_PolaritySwitch4, 3 );
lv_obj_set_y( ui_PolaritySwitch4, 20 );
lv_obj_set_align( ui_PolaritySwitch4, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_PolaritySwitch4, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_PolaritySwitch4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PolaritySwitch4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_PolaritySwitch4, 3, LV_PART_INDICATOR| LV_STATE_DEFAULT);
ui_object_set_themeable_style_property(ui_PolaritySwitch4, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_COLOR, _ui_theme_color_Green1);
ui_object_set_themeable_style_property(ui_PolaritySwitch4, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_OPA, _ui_theme_alpha_Green1);

lv_obj_set_style_radius(ui_PolaritySwitch4, 3, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_PolaritySwitch5 = lv_switch_create(ui_DimmerPolarityContainer);
lv_obj_set_width( ui_PolaritySwitch5, 50);
lv_obj_set_height( ui_PolaritySwitch5, 25);
lv_obj_set_x( ui_PolaritySwitch5, 3 );
lv_obj_set_y( ui_PolaritySwitch5, 60 );
lv_obj_set_align( ui_PolaritySwitch5, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_PolaritySwitch5, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_PolaritySwitch5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PolaritySwitch5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_PolaritySwitch5, 3, LV_PART_INDICATOR| LV_STATE_DEFAULT);
ui_object_set_themeable_style_property(ui_PolaritySwitch5, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_COLOR, _ui_theme_color_Green1);
ui_object_set_themeable_style_property(ui_PolaritySwitch5, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_OPA, _ui_theme_alpha_Green1);

lv_obj_set_style_radius(ui_PolaritySwitch5, 3, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_PolaritySwitch6 = lv_switch_create(ui_DimmerPolarityContainer);
lv_obj_set_width( ui_PolaritySwitch6, 50);
lv_obj_set_height( ui_PolaritySwitch6, 25);
lv_obj_set_x( ui_PolaritySwitch6, 3 );
lv_obj_set_y( ui_PolaritySwitch6, 100 );
lv_obj_set_align( ui_PolaritySwitch6, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_PolaritySwitch6, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_PolaritySwitch6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PolaritySwitch6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_PolaritySwitch6, 3, LV_PART_INDICATOR| LV_STATE_DEFAULT);
ui_object_set_themeable_style_property(ui_PolaritySwitch6, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_COLOR, _ui_theme_color_Green1);
ui_object_set_themeable_style_property(ui_PolaritySwitch6, LV_PART_INDICATOR| LV_STATE_CHECKED, LV_STYLE_BG_OPA, _ui_theme_alpha_Green1);

lv_obj_set_style_radius(ui_PolaritySwitch6, 3, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_Image17 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image17, &ui_img_1668210446);
lv_obj_set_width( ui_Image17, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image17, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image17, -32 );
lv_obj_set_y( ui_Image17, 0 );
lv_obj_set_align( ui_Image17, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image17, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image17, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_angle(ui_Image17,900);
ui_object_set_themeable_style_property(ui_Image17, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_IMG_RECOLOR, _ui_theme_color_gray1);
ui_object_set_themeable_style_property(ui_Image17, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_IMG_RECOLOR_OPA, _ui_theme_alpha_gray1);

ui_Container2 = lv_obj_create(ui_GeneralSettingsScreen);
lv_obj_remove_style_all(ui_Container2);
lv_obj_set_width( ui_Container2, 143);
lv_obj_set_height( ui_Container2, 267);
lv_obj_set_x( ui_Container2, 156 );
lv_obj_set_y( ui_Container2, 85 );
lv_obj_set_align( ui_Container2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Container2, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Container2, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Container2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Container2, 20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Roller1 = lv_roller_create(ui_Container2);
lv_roller_set_options( ui_Roller1, "1000\n2000\n4000\n6000\n8000\n10000\n15000\n20000\n25000\n", LV_ROLLER_MODE_NORMAL );
lv_obj_set_width( ui_Roller1, 100);
lv_obj_set_height( ui_Roller1, 200);
lv_obj_set_x( ui_Roller1, 4 );
lv_obj_set_y( ui_Roller1, 24 );
lv_obj_set_align( ui_Roller1, LV_ALIGN_CENTER );

ui_Label12 = lv_label_create(ui_Container2);
lv_obj_set_width( ui_Label12, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label12, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label12, 1 );
lv_obj_set_y( ui_Label12, -104 );
lv_obj_set_align( ui_Label12, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label12,"Fan Signal\nFrequency HZ");
lv_obj_set_style_text_letter_space(ui_Label12, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Label12, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Label12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label12, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Container1 = lv_obj_create(ui_GeneralSettingsScreen);
lv_obj_remove_style_all(ui_Container1);
lv_obj_set_width( ui_Container1, 130);
lv_obj_set_height( ui_Container1, 59);
lv_obj_set_x( ui_Container1, -323 );
lv_obj_set_y( ui_Container1, 194 );
lv_obj_set_align( ui_Container1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Container1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Container1, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Container1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Container1, 40, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ResetButton = lv_btn_create(ui_Container1);
lv_obj_set_width( ui_ResetButton, 80);
lv_obj_set_height( ui_ResetButton, 30);
lv_obj_set_x( ui_ResetButton, 0 );
lv_obj_set_y( ui_ResetButton, 1 );
lv_obj_set_align( ui_ResetButton, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_ResetButton, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ResetButton, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ResetButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4 = lv_label_create(ui_ResetButton);
lv_obj_set_width( ui_Label4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label4,"Restart");

lv_obj_add_event_cb(ui_ScreenBrightnessSlider, ui_event_ScreenBrightnessSlider, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_FirmwareUpgradeButton, ui_event_FirmwareUpgradeButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PolaritySwitch1, ui_event_PolaritySwitch1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PolaritySwitch2, ui_event_PolaritySwitch2, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PolaritySwitch3, ui_event_PolaritySwitch3, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PolaritySwitch4, ui_event_PolaritySwitch4, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PolaritySwitch5, ui_event_PolaritySwitch5, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_PolaritySwitch6, ui_event_PolaritySwitch6, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ResetButton, ui_event_ResetButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_GeneralSettingsScreen, ui_event_GeneralSettingsScreen, LV_EVENT_ALL, NULL);

}
