// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_SensorSettingsScreen_screen_init(void)
{
ui_SensorSettingsScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SensorSettingsScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SensorSettingsScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SensorSettingsScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label15 = lv_label_create(ui_SensorSettingsScreen);
lv_obj_set_width( ui_Label15, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label15, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label15, -112 );
lv_obj_set_y( ui_Label15, -127 );
lv_obj_set_align( ui_Label15, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label15,"Air Devices");
lv_obj_set_style_text_font(ui_Label15, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SensorSettingsInfoLabel = lv_label_create(ui_SensorSettingsScreen);
lv_obj_set_width( ui_SensorSettingsInfoLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SensorSettingsInfoLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SensorSettingsInfoLabel, 0 );
lv_obj_set_y( ui_SensorSettingsInfoLabel, 129 );
lv_obj_set_align( ui_SensorSettingsInfoLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_SensorSettingsInfoLabel,"");
lv_obj_set_style_text_align(ui_SensorSettingsInfoLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_PowerOutletDevicePanel = lv_obj_create(ui_SensorSettingsScreen);
lv_obj_set_height( ui_PowerOutletDevicePanel, 50);
lv_obj_set_width( ui_PowerOutletDevicePanel, lv_pct(90));
lv_obj_set_x( ui_PowerOutletDevicePanel, -2 );
lv_obj_set_y( ui_PowerOutletDevicePanel, -62 );
lv_obj_set_align( ui_PowerOutletDevicePanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_PowerOutletDevicePanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PowerOutletDevicePanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PowerOutletDevicePanel, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_PowerOutletDevicePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_PowerOutletDevicePanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image24 = lv_img_create(ui_PowerOutletDevicePanel);
lv_img_set_src(ui_Image24, &ui_img_1319116584);
lv_obj_set_width( ui_Image24, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image24, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image24, -180 );
lv_obj_set_y( ui_Image24, 0 );
lv_obj_set_align( ui_Image24, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image24, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image24, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Image24, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Image24, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button2 = lv_btn_create(ui_PowerOutletDevicePanel);
lv_obj_set_width( ui_Button2, 100);
lv_obj_set_height( ui_Button2, 40);
lv_obj_set_x( ui_Button2, -44 );
lv_obj_set_y( ui_Button2, 0 );
lv_obj_set_align( ui_Button2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Button2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0x0C17FF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label34 = lv_label_create(ui_Button2);
lv_obj_set_width( ui_Label34, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label34, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label34, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label34,"Unbind");
lv_obj_set_style_text_font(ui_Label34, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ToggleButton = lv_btn_create(ui_PowerOutletDevicePanel);
lv_obj_set_width( ui_ToggleButton, 100);
lv_obj_set_height( ui_ToggleButton, 40);
lv_obj_set_x( ui_ToggleButton, 133 );
lv_obj_set_y( ui_ToggleButton, 0 );
lv_obj_set_align( ui_ToggleButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ToggleButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_ToggleButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_ToggleButton, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ToggleButton, lv_color_hex(0x009F38), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ToggleButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label33 = lv_label_create(ui_ToggleButton);
lv_obj_set_width( ui_Label33, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label33, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label33, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label33,"Toggle");
lv_obj_set_style_text_font(ui_Label33, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button3 = lv_btn_create(ui_PowerOutletDevicePanel);
lv_obj_set_width( ui_Button3, 100);
lv_obj_set_height( ui_Button3, 40);
lv_obj_set_x( ui_Button3, -44 );
lv_obj_set_y( ui_Button3, 0 );
lv_obj_set_align( ui_Button3, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Button3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0xF20CFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label35 = lv_label_create(ui_Button3);
lv_obj_set_width( ui_Label35, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label35, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label35, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label35,"Bind");
lv_obj_set_style_text_font(ui_Label35, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ThermometerDevicePanel = lv_obj_create(ui_SensorSettingsScreen);
lv_obj_set_height( ui_ThermometerDevicePanel, 50);
lv_obj_set_width( ui_ThermometerDevicePanel, lv_pct(90));
lv_obj_set_x( ui_ThermometerDevicePanel, 0 );
lv_obj_set_y( ui_ThermometerDevicePanel, 1 );
lv_obj_set_align( ui_ThermometerDevicePanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_ThermometerDevicePanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ThermometerDevicePanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ThermometerDevicePanel, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_ThermometerDevicePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_ThermometerDevicePanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image25 = lv_img_create(ui_ThermometerDevicePanel);
lv_img_set_src(ui_Image25, &ui_img_1130838376);
lv_obj_set_width( ui_Image25, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image25, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image25, -179 );
lv_obj_set_y( ui_Image25, 0 );
lv_obj_set_align( ui_Image25, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image25, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image25, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_img_recolor(ui_Image25, lv_color_hex(0xFFFFFF), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_Image25, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Co2SensorDevicePanel = lv_obj_create(ui_SensorSettingsScreen);
lv_obj_set_height( ui_Co2SensorDevicePanel, 50);
lv_obj_set_width( ui_Co2SensorDevicePanel, lv_pct(90));
lv_obj_set_x( ui_Co2SensorDevicePanel, 0 );
lv_obj_set_y( ui_Co2SensorDevicePanel, 65 );
lv_obj_set_align( ui_Co2SensorDevicePanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Co2SensorDevicePanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Co2SensorDevicePanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Co2SensorDevicePanel, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Co2SensorDevicePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Co2SensorDevicePanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image26 = lv_img_create(ui_Co2SensorDevicePanel);
lv_img_set_src(ui_Image26, &ui_img_co2_png);
lv_obj_set_width( ui_Image26, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image26, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image26, -178 );
lv_obj_set_y( ui_Image26, -2 );
lv_obj_set_align( ui_Image26, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image26, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image26, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image26,160);

lv_obj_add_event_cb(ui_ToggleButton, ui_event_ToggleButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_SensorSettingsScreen, ui_event_SensorSettingsScreen, LV_EVENT_ALL, NULL);

}
