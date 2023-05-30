// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_DayCounterScreen_screen_init(void)
{
ui_DayCounterScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_DayCounterScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_DayCounterScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_DayCounterScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label11 = lv_label_create(ui_DayCounterScreen);
lv_obj_set_width( ui_Label11, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label11, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label11, -97 );
lv_obj_set_y( ui_Label11, -16 );
lv_obj_set_align( ui_Label11, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label11,"Day Counter");
lv_obj_set_style_text_font(ui_Label11, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImgButton2 = lv_imgbtn_create(ui_DayCounterScreen);
lv_imgbtn_set_src(ui_ImgButton2, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_2060199463, NULL);
lv_imgbtn_set_src(ui_ImgButton2, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_2060199463, NULL);
lv_obj_set_height( ui_ImgButton2, 64);
lv_obj_set_width( ui_ImgButton2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_x( ui_ImgButton2, 113 );
lv_obj_set_y( ui_ImgButton2, -65 );
lv_obj_set_align( ui_ImgButton2, LV_ALIGN_CENTER );
lv_obj_set_style_img_recolor(ui_ImgButton2, lv_color_hex(0x242424), LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_img_recolor_opa(ui_ImgButton2, 255, LV_PART_MAIN| LV_STATE_PRESSED);

ui_ImgButton1 = lv_imgbtn_create(ui_DayCounterScreen);
lv_imgbtn_set_src(ui_ImgButton1, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_1749885216, NULL);
lv_imgbtn_set_src(ui_ImgButton1, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_1749885216, NULL);
lv_obj_set_height( ui_ImgButton1, 64);
lv_obj_set_width( ui_ImgButton1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_x( ui_ImgButton1, 113 );
lv_obj_set_y( ui_ImgButton1, 65 );
lv_obj_set_align( ui_ImgButton1, LV_ALIGN_CENTER );
lv_obj_set_style_img_recolor(ui_ImgButton1, lv_color_hex(0x242424), LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_img_recolor_opa(ui_ImgButton1, 255, LV_PART_MAIN| LV_STATE_PRESSED);

ui_Label15 = lv_label_create(ui_DayCounterScreen);
lv_obj_set_width( ui_Label15, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label15, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label15, -93 );
lv_obj_set_y( ui_Label15, -84 );
lv_obj_set_align( ui_Label15, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label15,"21");
lv_obj_set_style_text_font(ui_Label15, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Label15, lv_color_hex(0xACACAC), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Label15, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Label15, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_Label15, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Label15, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Label15, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Label15, 8, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image1 = lv_img_create(ui_DayCounterScreen);
lv_img_set_src(ui_Image1, &ui_img_appointment_png);
lv_obj_set_width( ui_Image1, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image1, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image1, -162 );
lv_obj_set_y( ui_Image1, -86 );
lv_obj_set_align( ui_Image1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel10 = lv_obj_create(ui_DayCounterScreen);
lv_obj_set_width( ui_Panel10, 230);
lv_obj_set_height( ui_Panel10, 77);
lv_obj_set_x( ui_Panel10, -99 );
lv_obj_set_y( ui_Panel10, 107 );
lv_obj_set_align( ui_Panel10, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel10, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel10, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel10, 20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image15 = lv_img_create(ui_Panel10);
lv_img_set_src(ui_Image15, &ui_img_harvest_png);
lv_obj_set_width( ui_Image15, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image15, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image15, -77 );
lv_obj_set_y( ui_Image15, 1 );
lv_obj_set_align( ui_Image15, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image15, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image15, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Button1 = lv_btn_create(ui_Panel10);
lv_obj_set_width( ui_Button1, 100);
lv_obj_set_height( ui_Button1, 50);
lv_obj_set_x( ui_Button1, 31 );
lv_obj_set_y( ui_Button1, 1 );
lv_obj_set_align( ui_Button1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0xFE7B0F), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label22 = lv_label_create(ui_Button1);
lv_obj_set_width( ui_Label22, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label22, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label22, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label22,"Finish");
lv_obj_set_style_text_font(ui_Label22, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImgButton9 = lv_imgbtn_create(ui_DayCounterScreen);
lv_imgbtn_set_src(ui_ImgButton9, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_1668913270, NULL);
lv_obj_set_width( ui_ImgButton9, 32);
lv_obj_set_height( ui_ImgButton9, 32);
lv_obj_set_x( ui_ImgButton9, 203 );
lv_obj_set_y( ui_ImgButton9, -126 );
lv_obj_set_align( ui_ImgButton9, LV_ALIGN_CENTER );
lv_obj_set_style_img_recolor(ui_ImgButton9, lv_color_hex(0xC3C3C3), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_ImgButton9, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

}
