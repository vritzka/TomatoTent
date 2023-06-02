// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_GraphScreen_screen_init(void)
{
ui_GraphScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_GraphScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GraphScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GraphScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Chart2 = lv_chart_create(ui_GraphScreen);
lv_obj_set_width( ui_Chart2, 404);
lv_obj_set_height( ui_Chart2, 239);
lv_obj_set_x( ui_Chart2, 1 );
lv_obj_set_y( ui_Chart2, 12 );
lv_obj_set_align( ui_Chart2, LV_ALIGN_CENTER );
lv_chart_set_type( ui_Chart2, LV_CHART_TYPE_LINE);
lv_chart_set_axis_tick( ui_Chart2, LV_CHART_AXIS_PRIMARY_X, 10, 5, 5, 2, true, 50);
lv_chart_set_axis_tick( ui_Chart2, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 2, true, 50);
lv_chart_set_axis_tick( ui_Chart2, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 2, true, 25);
lv_chart_series_t* ui_Chart2_series_1 = lv_chart_add_series(ui_Chart2, lv_color_hex(0x3617EB), LV_CHART_AXIS_PRIMARY_Y);
static lv_coord_t ui_Chart2_series_1_array[] = { 0,10,20,40,30,80,40,20,10,0 };
lv_chart_set_ext_y_array(ui_Chart2, ui_Chart2_series_1, ui_Chart2_series_1_array);
lv_chart_series_t* ui_Chart2_series_2 = lv_chart_add_series(ui_Chart2, lv_color_hex(0xD5A802), LV_CHART_AXIS_SECONDARY_Y);
static lv_coord_t ui_Chart2_series_2_array[] = { 16,30,40,70,50,60,23,3,5 };
lv_chart_set_ext_y_array(ui_Chart2, ui_Chart2_series_2, ui_Chart2_series_2_array);
lv_chart_series_t* ui_Chart2_series_3 = lv_chart_add_series(ui_Chart2, lv_color_hex(0x000000), LV_CHART_AXIS_SECONDARY_Y);
static lv_coord_t ui_Chart2_series_3_array[] = { 0,10,2,40,80,80,40,10,10,0,7 };
lv_chart_set_ext_y_array(ui_Chart2, ui_Chart2_series_3, ui_Chart2_series_3_array);
lv_chart_series_t* ui_Chart2_series_4 = lv_chart_add_series(ui_Chart2, lv_color_hex(0xFF0000), LV_CHART_AXIS_SECONDARY_Y);
static lv_coord_t ui_Chart2_series_4_array[] = { 10,20,40,80,80,0,20,10,0,3 };
lv_chart_set_ext_y_array(ui_Chart2, ui_Chart2_series_4, ui_Chart2_series_4_array);
lv_obj_set_style_bg_color(ui_Chart2, lv_color_hex(0x2FA73D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Chart2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image18 = lv_img_create(ui_GraphScreen);
lv_img_set_src(ui_Image18, &ui_img_upload_png);
lv_obj_set_width( ui_Image18, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_Image18, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_Image18, -222 );
lv_obj_set_y( ui_Image18, 15 );
lv_obj_set_align( ui_Image18, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image18, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image18, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_angle(ui_Image18,2700);
lv_obj_set_style_img_recolor(ui_Image18, lv_color_hex(0x145B0A), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_Image18, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel14 = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_Panel14, 100);
lv_obj_set_height( ui_Panel14, 40);
lv_obj_set_x( ui_Panel14, -176 );
lv_obj_set_y( ui_Panel14, -133 );
lv_obj_set_align( ui_Panel14, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel14, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel14, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel14, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel14, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image6 = lv_img_create(ui_Panel14);
lv_img_set_src(ui_Image6, &ui_img_1484485426);
lv_obj_set_width( ui_Image6, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image6, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image6, -29 );
lv_obj_set_y( ui_Image6, 0 );
lv_obj_set_align( ui_Image6, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image6, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image6, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image6,125);

ui_Panel9 = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_Panel9, 100);
lv_obj_set_height( ui_Panel9, 40);
lv_obj_set_x( ui_Panel9, -58 );
lv_obj_set_y( ui_Panel9, -133 );
lv_obj_set_align( ui_Panel9, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel9, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel9, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel9, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image19 = lv_img_create(ui_Panel9);
lv_img_set_src(ui_Image19, &ui_img_humidity_png);
lv_obj_set_width( ui_Image19, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image19, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image19, -29 );
lv_obj_set_y( ui_Image19, -1 );
lv_obj_set_align( ui_Image19, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image19, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image19, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image19,125);

ui_Panel15 = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_Panel15, 100);
lv_obj_set_height( ui_Panel15, 40);
lv_obj_set_x( ui_Panel15, 58 );
lv_obj_set_y( ui_Panel15, -133 );
lv_obj_set_align( ui_Panel15, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel15, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel15, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel15, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel15, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image11 = lv_img_create(ui_Panel15);
lv_img_set_src(ui_Image11, &ui_img_dew_png);
lv_obj_set_width( ui_Image11, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image11, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image11, -29 );
lv_obj_set_y( ui_Image11, 1 );
lv_obj_set_align( ui_Image11, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image11, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image11, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image11,125);

ui_Panel16 = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_Panel16, 100);
lv_obj_set_height( ui_Panel16, 40);
lv_obj_set_x( ui_Panel16, 176 );
lv_obj_set_y( ui_Panel16, -133 );
lv_obj_set_align( ui_Panel16, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel16, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel16, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel16, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel16, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image21 = lv_img_create(ui_Panel16);
lv_img_set_src(ui_Image21, &ui_img_60476769);
lv_obj_set_width( ui_Image21, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_Image21, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_Image21, -29 );
lv_obj_set_y( ui_Image21, 0 );
lv_obj_set_align( ui_Image21, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image21, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image21, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_GraphScreen, ui_event_GraphScreen, LV_EVENT_ALL, NULL);

}