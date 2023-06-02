// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_HomeScreen_screen_init(void)
{
ui_HomeScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_HomeScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_HomeScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_HomeScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_sun = lv_img_create(ui_HomeScreen);
lv_img_set_src(ui_sun, &ui_img_791711567);
lv_obj_set_width( ui_sun, LV_SIZE_CONTENT);  /// 128
lv_obj_set_height( ui_sun, LV_SIZE_CONTENT);   /// 128
lv_obj_set_x( ui_sun, -208 );
lv_obj_set_y( ui_sun, -137 );
lv_obj_set_align( ui_sun, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_sun, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_sun, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_angle(ui_sun,60);

ui_TemperaturePanel = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_TemperaturePanel, 195);
lv_obj_set_height( ui_TemperaturePanel, 80);
lv_obj_set_x( ui_TemperaturePanel, -117 );
lv_obj_set_y( ui_TemperaturePanel, -16 );
lv_obj_set_align( ui_TemperaturePanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_TemperaturePanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_TemperaturePanel, lv_color_hex(0xE8E8E8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TemperaturePanel, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_TemperaturePanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TemperaturePanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_opa(ui_TemperaturePanel, 50, LV_PART_MAIN| LV_STATE_PRESSED);

ui_Label5 = lv_label_create(ui_TemperaturePanel);
lv_obj_set_width( ui_Label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label5, 14 );
lv_obj_set_y( ui_Label5, 0 );
lv_obj_set_align( ui_Label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label5,"68");
lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_44, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label1 = lv_label_create(ui_TemperaturePanel);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, 69 );
lv_obj_set_y( ui_Label1, -10 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"°F");
lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image5 = lv_img_create(ui_TemperaturePanel);
lv_img_set_src(ui_Image5, &ui_img_1484485426);
lv_obj_set_width( ui_Image5, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image5, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image5, -53 );
lv_obj_set_y( ui_Image5, 1 );
lv_obj_set_align( ui_Image5, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image5, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel1 = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_Panel1, 195);
lv_obj_set_height( ui_Panel1, 80);
lv_obj_set_x( ui_Panel1, -117 );
lv_obj_set_y( ui_Panel1, 94 );
lv_obj_set_align( ui_Panel1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xE8E8E8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel1, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label4 = lv_label_create(ui_Panel1);
lv_obj_set_width( ui_Label4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4, 16 );
lv_obj_set_y( ui_Label4, -1 );
lv_obj_set_align( ui_Label4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label4,"33");
lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_44, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label6 = lv_label_create(ui_Panel1);
lv_obj_set_width( ui_Label6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label6, 69 );
lv_obj_set_y( ui_Label6, -14 );
lv_obj_set_align( ui_Label6, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label6,"%");
lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image3 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image3, &ui_img_humidity_png);
lv_obj_set_width( ui_Image3, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image3, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image3, -57 );
lv_obj_set_y( ui_Image3, 0 );
lv_obj_set_align( ui_Image3, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image3, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel5 = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_Panel5, 195);
lv_obj_set_height( ui_Panel5, 80);
lv_obj_set_x( ui_Panel5, 111 );
lv_obj_set_y( ui_Panel5, 94 );
lv_obj_set_align( ui_Panel5, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel5, lv_color_hex(0xE8E8E8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel5, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label7 = lv_label_create(ui_Panel5);
lv_obj_set_width( ui_Label7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label7, 10 );
lv_obj_set_y( ui_Label7, -1 );
lv_obj_set_align( ui_Label7, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label7,"1.6");
lv_obj_set_style_text_font(ui_Label7, &lv_font_montserrat_44, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label8 = lv_label_create(ui_Panel5);
lv_obj_set_width( ui_Label8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label8, 69 );
lv_obj_set_y( ui_Label8, -10 );
lv_obj_set_align( ui_Label8, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label8,"kp");
lv_obj_set_style_text_font(ui_Label8, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image2 = lv_img_create(ui_Panel5);
lv_img_set_src(ui_Image2, &ui_img_dew_png);
lv_obj_set_width( ui_Image2, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image2, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image2, -59 );
lv_obj_set_y( ui_Image2, 1 );
lv_obj_set_align( ui_Image2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel4 = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_Panel4, 195);
lv_obj_set_height( ui_Panel4, 80);
lv_obj_set_x( ui_Panel4, 111 );
lv_obj_set_y( ui_Panel4, -16 );
lv_obj_set_align( ui_Panel4, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0xE8E8E8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel4, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_opa(ui_Panel4, 50, LV_PART_MAIN| LV_STATE_PRESSED);

ui_Label9 = lv_label_create(ui_Panel4);
lv_obj_set_width( ui_Label9, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label9, 12 );
lv_obj_set_y( ui_Label9, -1 );
lv_obj_set_align( ui_Label9, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label9,"20");
lv_obj_set_style_text_font(ui_Label9, &lv_font_montserrat_44, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label13 = lv_label_create(ui_Panel4);
lv_obj_set_width( ui_Label13, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label13, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label13, 67 );
lv_obj_set_y( ui_Label13, -10 );
lv_obj_set_align( ui_Label13, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label13,"%");
lv_obj_set_style_text_font(ui_Label13, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fan = lv_img_create(ui_Panel4);
lv_img_set_src(ui_fan, &ui_img_1142205948);
lv_obj_set_width( ui_fan, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_fan, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_fan, -59 );
lv_obj_set_y( ui_fan, 1 );
lv_obj_set_align( ui_fan, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_fan, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_fan, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel11 = lv_obj_create(ui_HomeScreen);
lv_obj_set_width( ui_Panel11, 134);
lv_obj_set_height( ui_Panel11, 75);
lv_obj_set_x( ui_Panel11, -61 );
lv_obj_set_y( ui_Panel11, -111 );
lv_obj_set_align( ui_Panel11, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel11, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel11, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel11, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel11, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel11, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_opa(ui_Panel11, 20, LV_PART_MAIN| LV_STATE_PRESSED);

ui_DayCounterLabel = lv_label_create(ui_Panel11);
lv_obj_set_width( ui_DayCounterLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_DayCounterLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_DayCounterLabel, -20 );
lv_obj_set_y( ui_DayCounterLabel, -16 );
lv_obj_set_align( ui_DayCounterLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_DayCounterLabel,"Day 21");
lv_obj_add_flag( ui_DayCounterLabel, LV_OBJ_FLAG_EVENT_BUBBLE );   /// Flags
lv_obj_clear_flag( ui_DayCounterLabel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags
lv_obj_set_style_text_font(ui_DayCounterLabel, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label10 = lv_label_create(ui_Panel11);
lv_obj_set_width( ui_Label10, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label10, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label10, -4 );
lv_obj_set_y( ui_Label10, 14 );
lv_obj_set_align( ui_Label10, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label10,"- 1 hr  12 min");
lv_obj_add_flag( ui_Label10, LV_OBJ_FLAG_EVENT_BUBBLE );   /// Flags
lv_obj_clear_flag( ui_Label10, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags
lv_obj_set_style_text_font(ui_Label10, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ArrowUp1 = lv_img_create(ui_HomeScreen);
lv_img_set_src(ui_ArrowUp1, &ui_img_upload_png);
lv_obj_set_width( ui_ArrowUp1, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_ArrowUp1, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_ArrowUp1, -230 );
lv_obj_set_y( ui_ArrowUp1, 38 );
lv_obj_set_align( ui_ArrowUp1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ArrowUp1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_ArrowUp1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_angle(ui_ArrowUp1,2700);
lv_img_set_zoom(ui_ArrowUp1,200);
lv_obj_set_style_img_recolor(ui_ArrowUp1, lv_color_hex(0x145B0A), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_ArrowUp1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImgButton3 = lv_imgbtn_create(ui_HomeScreen);
lv_imgbtn_set_src(ui_ImgButton3, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_wifi_png, NULL);
lv_obj_set_width( ui_ImgButton3, 24);
lv_obj_set_height( ui_ImgButton3, 24);
lv_obj_set_x( ui_ImgButton3, 203 );
lv_obj_set_y( ui_ImgButton3, -126 );
lv_obj_set_align( ui_ImgButton3, LV_ALIGN_CENTER );

lv_obj_add_event_cb(ui_TemperaturePanel, ui_event_TemperaturePanel, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Panel1, ui_event_Panel1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Panel4, ui_event_Panel4, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Panel11, ui_event_Panel11, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ImgButton3, ui_event_ImgButton3, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_HomeScreen, ui_event_HomeScreen, LV_EVENT_ALL, NULL);

}
