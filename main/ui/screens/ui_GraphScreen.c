// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_GraphScreen_screen_init(void)
{
ui_GraphScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_GraphScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_GraphScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_GraphScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_HomeSky2 = lv_img_create(ui_GraphScreen);
lv_img_set_src(ui_HomeSky2, &ui_img_791711567);
lv_obj_set_width( ui_HomeSky2, LV_SIZE_CONTENT);  /// 128
lv_obj_set_height( ui_HomeSky2, LV_SIZE_CONTENT);   /// 128
lv_obj_set_x( ui_HomeSky2, -283 );
lv_obj_set_y( ui_HomeSky2, -87 );
lv_obj_set_align( ui_HomeSky2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_HomeSky2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_HomeSky2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_img_recolor(ui_HomeSky2, lv_color_hex(0x000000), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_HomeSky2, 100, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_bud = lv_img_create(ui_GraphScreen);
lv_img_set_src(ui_bud, &ui_img_bud_png);
lv_obj_set_width( ui_bud, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_bud, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_bud, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_bud, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_bud, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_blend_mode(ui_bud, LV_BLEND_MODE_NORMAL, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_opa(ui_bud, 120, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Chart = lv_chart_create(ui_GraphScreen);
lv_obj_set_width( ui_Chart, 720);
lv_obj_set_height( ui_Chart, 378);
lv_obj_set_x( ui_Chart, -6 );
lv_obj_set_y( ui_Chart, 32 );
lv_obj_set_align( ui_Chart, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Chart, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags
lv_chart_set_type( ui_Chart, LV_CHART_TYPE_LINE);
lv_chart_set_point_count( ui_Chart, 240);
lv_chart_set_range( ui_Chart, LV_CHART_AXIS_SECONDARY_Y, 200, 2000);
lv_chart_set_div_line_count( ui_Chart, 10, 5);
lv_chart_set_axis_tick( ui_Chart, LV_CHART_AXIS_PRIMARY_X, 0, 0, 10, 0, false, 40);
lv_chart_set_axis_tick( ui_Chart, LV_CHART_AXIS_PRIMARY_Y, 5, 0, 11, 2, true, 22);
lv_chart_set_axis_tick( ui_Chart, LV_CHART_AXIS_SECONDARY_Y, 5, 0, 10, 2, true, 25);
lv_obj_set_style_bg_color(ui_Chart, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Chart, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Chart, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Chart, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Chart, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_line_color(ui_Chart, lv_color_hex(0x627764), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_line_opa(ui_Chart, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_Chart, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Chart, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Chart, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Chart, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_object_set_themeable_style_property(ui_Chart, LV_PART_ITEMS| LV_STATE_DEFAULT, LV_STYLE_LINE_COLOR, _ui_theme_color_gray1);
ui_object_set_themeable_style_property(ui_Chart, LV_PART_ITEMS| LV_STATE_DEFAULT, LV_STYLE_LINE_OPA, _ui_theme_alpha_gray1);
lv_obj_set_style_line_width(ui_Chart, 3, LV_PART_ITEMS| LV_STATE_DEFAULT);
lv_obj_set_style_line_rounded(ui_Chart, true, LV_PART_ITEMS| LV_STATE_DEFAULT);

lv_obj_set_style_size(ui_Chart, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);

ui_object_set_themeable_style_property(ui_Chart, LV_PART_TICKS| LV_STATE_DEFAULT, LV_STYLE_LINE_COLOR, _ui_theme_color_gray1);
ui_object_set_themeable_style_property(ui_Chart, LV_PART_TICKS| LV_STATE_DEFAULT, LV_STYLE_LINE_OPA, _ui_theme_alpha_gray1);

ui_TempSeriesPanel = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_TempSeriesPanel, 120);
lv_obj_set_height( ui_TempSeriesPanel, 50);
lv_obj_set_x( ui_TempSeriesPanel, -295 );
lv_obj_set_y( ui_TempSeriesPanel, -202 );
lv_obj_set_align( ui_TempSeriesPanel, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_TempSeriesPanel, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_EVENT_BUBBLE );   /// Flags
lv_obj_clear_flag( ui_TempSeriesPanel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_TempSeriesPanel, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TempSeriesPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TempSeriesPanel, 40, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_TempSeriesPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_TempSeriesPanel, lv_color_hex(0xEF5F3C), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_border_opa(ui_TempSeriesPanel, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_width(ui_TempSeriesPanel, 3, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_side(ui_TempSeriesPanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN| LV_STATE_CHECKED);

ui_Image6 = lv_img_create(ui_TempSeriesPanel);
lv_img_set_src(ui_Image6, &ui_img_1484485426);
lv_obj_set_width( ui_Image6, 64);
lv_obj_set_height( ui_Image6, 64);
lv_obj_set_x( ui_Image6, -23 );
lv_obj_set_y( ui_Image6, 0 );
lv_obj_set_align( ui_Image6, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image6, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image6, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image6,125);

ui_TemperatureLabel2 = lv_label_create(ui_TempSeriesPanel);
lv_obj_set_width( ui_TemperatureLabel2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TemperatureLabel2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TemperatureLabel2, 15 );
lv_obj_set_y( ui_TemperatureLabel2, 2 );
lv_obj_set_align( ui_TemperatureLabel2, LV_ALIGN_CENTER );
lv_label_set_text(ui_TemperatureLabel2,"-");
lv_obj_set_style_text_font(ui_TemperatureLabel2, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TempUnitLabel2 = lv_label_create(ui_TempSeriesPanel);
lv_obj_set_width( ui_TempUnitLabel2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TempUnitLabel2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TempUnitLabel2, 31 );
lv_obj_set_y( ui_TempUnitLabel2, -12 );
lv_obj_set_align( ui_TempUnitLabel2, LV_ALIGN_CENTER );
lv_label_set_text(ui_TempUnitLabel2,"F");
lv_obj_set_style_text_font(ui_TempUnitLabel2, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_HumiditySeriesPanel = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_HumiditySeriesPanel, 120);
lv_obj_set_height( ui_HumiditySeriesPanel, 50);
lv_obj_set_x( ui_HumiditySeriesPanel, -149 );
lv_obj_set_y( ui_HumiditySeriesPanel, -202 );
lv_obj_set_align( ui_HumiditySeriesPanel, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_HumiditySeriesPanel, LV_OBJ_FLAG_CHECKABLE );   /// Flags
lv_obj_clear_flag( ui_HumiditySeriesPanel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_HumiditySeriesPanel, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_HumiditySeriesPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_HumiditySeriesPanel, 40, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_HumiditySeriesPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_HumiditySeriesPanel, lv_color_hex(0x3CB7FF), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_border_opa(ui_HumiditySeriesPanel, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_width(ui_HumiditySeriesPanel, 3, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_side(ui_HumiditySeriesPanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN| LV_STATE_CHECKED);

ui_Image19 = lv_img_create(ui_HumiditySeriesPanel);
lv_img_set_src(ui_Image19, &ui_img_humidity_png);
lv_obj_set_width( ui_Image19, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image19, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image19, -25 );
lv_obj_set_y( ui_Image19, -1 );
lv_obj_set_align( ui_Image19, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image19, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image19, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image19,125);

ui_HumidityLabel2 = lv_label_create(ui_HumiditySeriesPanel);
lv_obj_set_width( ui_HumidityLabel2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_HumidityLabel2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_HumidityLabel2, 15 );
lv_obj_set_y( ui_HumidityLabel2, 2 );
lv_obj_set_align( ui_HumidityLabel2, LV_ALIGN_CENTER );
lv_label_set_text(ui_HumidityLabel2,"-");
lv_obj_set_style_text_font(ui_HumidityLabel2, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label7 = lv_label_create(ui_HumiditySeriesPanel);
lv_obj_set_width( ui_Label7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label7, 31 );
lv_obj_set_y( ui_Label7, -12 );
lv_obj_set_align( ui_Label7, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label7,"%");
lv_obj_set_style_text_font(ui_Label7, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CO2SeriesPanel = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_CO2SeriesPanel, 120);
lv_obj_set_height( ui_CO2SeriesPanel, 50);
lv_obj_set_x( ui_CO2SeriesPanel, 0 );
lv_obj_set_y( ui_CO2SeriesPanel, -202 );
lv_obj_set_align( ui_CO2SeriesPanel, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_CO2SeriesPanel, LV_OBJ_FLAG_CHECKABLE );   /// Flags
lv_obj_clear_flag( ui_CO2SeriesPanel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_CO2SeriesPanel, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_CO2SeriesPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_CO2SeriesPanel, 40, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_CO2SeriesPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_CO2SeriesPanel, lv_color_hex(0xAFBDC4), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_border_opa(ui_CO2SeriesPanel, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_width(ui_CO2SeriesPanel, 3, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_side(ui_CO2SeriesPanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN| LV_STATE_CHECKED);

ui_Image11 = lv_img_create(ui_CO2SeriesPanel);
lv_img_set_src(ui_Image11, &ui_img_co2_png);
lv_obj_set_width( ui_Image11, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image11, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image11, -24 );
lv_obj_set_y( ui_Image11, -1 );
lv_obj_set_align( ui_Image11, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image11, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image11, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image11,125);

ui_Co2Label2 = lv_label_create(ui_CO2SeriesPanel);
lv_obj_set_width( ui_Co2Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Co2Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Co2Label2, 26 );
lv_obj_set_y( ui_Co2Label2, 2 );
lv_obj_set_align( ui_Co2Label2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Co2Label2,"-");
lv_obj_set_style_text_font(ui_Co2Label2, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label8 = lv_label_create(ui_CO2SeriesPanel);
lv_obj_set_width( ui_Label8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label8, 37 );
lv_obj_set_y( ui_Label8, -16 );
lv_obj_set_align( ui_Label8, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label8,"ppm");
lv_obj_set_style_text_font(ui_Label8, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_FanspeedSeriesPanel = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_FanspeedSeriesPanel, 120);
lv_obj_set_height( ui_FanspeedSeriesPanel, 50);
lv_obj_set_x( ui_FanspeedSeriesPanel, 293 );
lv_obj_set_y( ui_FanspeedSeriesPanel, -202 );
lv_obj_set_align( ui_FanspeedSeriesPanel, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_FanspeedSeriesPanel, LV_OBJ_FLAG_CHECKABLE );   /// Flags
lv_obj_clear_flag( ui_FanspeedSeriesPanel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_FanspeedSeriesPanel, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_FanspeedSeriesPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_FanspeedSeriesPanel, 40, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_FanspeedSeriesPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_FanspeedSeriesPanel, lv_color_hex(0x787373), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_border_opa(ui_FanspeedSeriesPanel, 255, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_width(ui_FanspeedSeriesPanel, 3, LV_PART_MAIN| LV_STATE_CHECKED);
lv_obj_set_style_border_side(ui_FanspeedSeriesPanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN| LV_STATE_CHECKED);

ui_Fan2 = lv_img_create(ui_FanspeedSeriesPanel);
lv_img_set_src(ui_Fan2, &ui_img_60476769);
lv_obj_set_width( ui_Fan2, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_Fan2, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_Fan2, -23 );
lv_obj_set_y( ui_Fan2, 0 );
lv_obj_set_align( ui_Fan2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Fan2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Fan2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_FanSpeedLabel2 = lv_label_create(ui_FanspeedSeriesPanel);
lv_obj_set_width( ui_FanSpeedLabel2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_FanSpeedLabel2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_FanSpeedLabel2, 23 );
lv_obj_set_y( ui_FanSpeedLabel2, 2 );
lv_obj_set_align( ui_FanSpeedLabel2, LV_ALIGN_CENTER );
lv_label_set_text(ui_FanSpeedLabel2,"-");
lv_obj_set_style_text_font(ui_FanSpeedLabel2, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label9 = lv_label_create(ui_FanspeedSeriesPanel);
lv_obj_set_width( ui_Label9, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label9, 31 );
lv_obj_set_y( ui_Label9, -13 );
lv_obj_set_align( ui_Label9, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label9,"%");
lv_obj_set_style_text_font(ui_Label9, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_VPDSeriesPanel = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_VPDSeriesPanel, 120);
lv_obj_set_height( ui_VPDSeriesPanel, 50);
lv_obj_set_x( ui_VPDSeriesPanel, 145 );
lv_obj_set_y( ui_VPDSeriesPanel, -202 );
lv_obj_set_align( ui_VPDSeriesPanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_VPDSeriesPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_VPDSeriesPanel, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_VPDSeriesPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_VPDSeriesPanel, 40, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_VPDSeriesPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image16 = lv_img_create(ui_VPDSeriesPanel);
lv_img_set_src(ui_Image16, &ui_img_17176521);
lv_obj_set_width( ui_Image16, 64);
lv_obj_set_height( ui_Image16, 64);
lv_obj_set_x( ui_Image16, -21 );
lv_obj_set_y( ui_Image16, 0 );
lv_obj_set_align( ui_Image16, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image16, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image16, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image16,125);

ui_VPDLabel2 = lv_label_create(ui_VPDSeriesPanel);
lv_obj_set_width( ui_VPDLabel2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_VPDLabel2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_VPDLabel2, 27 );
lv_obj_set_y( ui_VPDLabel2, 2 );
lv_obj_set_align( ui_VPDLabel2, LV_ALIGN_CENTER );
lv_label_set_text(ui_VPDLabel2,"-");
lv_obj_set_style_text_font(ui_VPDLabel2, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label5 = lv_label_create(ui_VPDSeriesPanel);
lv_obj_set_width( ui_Label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label5, 28 );
lv_obj_set_y( ui_Label5, -15 );
lv_obj_set_align( ui_Label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label5,"kpa");
lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_DimmerIconPanel2 = lv_obj_create(ui_GraphScreen);
lv_obj_set_width( ui_DimmerIconPanel2, 111);
lv_obj_set_height( ui_DimmerIconPanel2, 78);
lv_obj_set_x( ui_DimmerIconPanel2, 0 );
lv_obj_set_y( ui_DimmerIconPanel2, -283 );
lv_obj_set_align( ui_DimmerIconPanel2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_DimmerIconPanel2, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE );   /// Flags
lv_obj_clear_flag( ui_DimmerIconPanel2, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_style_bg_color(ui_DimmerIconPanel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_DimmerIconPanel2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_DimmerIconPanel2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image18 = lv_img_create(ui_DimmerIconPanel2);
lv_img_set_src(ui_Image18, &ui_img_640654572);
lv_obj_set_width( ui_Image18, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_Image18, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_Image18, 0 );
lv_obj_set_y( ui_Image18, -8 );
lv_obj_set_align( ui_Image18, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image18, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_EVENT_BUBBLE );   /// Flags
lv_obj_clear_flag( ui_Image18, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_DimmerBar2 = lv_bar_create(ui_DimmerIconPanel2);
lv_bar_set_range(ui_DimmerBar2, 0,900);
lv_bar_set_value(ui_DimmerBar2,900,LV_ANIM_OFF);
lv_bar_set_start_value(ui_DimmerBar2, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_DimmerBar2, 36);
lv_obj_set_height( ui_DimmerBar2, 5);
lv_obj_set_x( ui_DimmerBar2, 0 );
lv_obj_set_y( ui_DimmerBar2, 23 );
lv_obj_set_align( ui_DimmerBar2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_DimmerBar2, LV_OBJ_FLAG_EVENT_BUBBLE );   /// Flags
lv_obj_clear_flag( ui_DimmerBar2, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags
lv_obj_set_style_radius(ui_DimmerBar2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_DimmerBar2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_DimmerBar2, 50, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_DimmerBar2, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_DimmerBar2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_DimmerBar2, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_TempSeriesPanel, ui_event_TempSeriesPanel, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_HumiditySeriesPanel, ui_event_HumiditySeriesPanel, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_CO2SeriesPanel, ui_event_CO2SeriesPanel, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_FanspeedSeriesPanel, ui_event_FanspeedSeriesPanel, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_GraphScreen, ui_event_GraphScreen, LV_EVENT_ALL, NULL);

}
