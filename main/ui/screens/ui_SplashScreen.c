// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_SplashScreen_screen_init(void)
{
ui_SplashScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SplashScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SplashScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SplashScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_StartNewGrowButton = lv_btn_create(ui_SplashScreen);
lv_obj_set_width( ui_StartNewGrowButton, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_StartNewGrowButton, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_StartNewGrowButton, -430 );
lv_obj_set_y( ui_StartNewGrowButton, -9 );
lv_obj_set_align( ui_StartNewGrowButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_StartNewGrowButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_StartNewGrowButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_StartNewGrowButton, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_StartNewGrowButton, lv_color_hex(0x2C472A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_StartNewGrowButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_StartNewGrowButton, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_StartNewGrowButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_StartNewGrowButton, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_StartNewGrowButton, 25, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_StartNewGrowButton, 25, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_StartNewGrowButton, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_StartNewGrowButton, 15, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label3 = lv_label_create(ui_StartNewGrowButton);
lv_obj_set_width( ui_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label3,"Start        Grow");
lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_44, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image7 = lv_img_create(ui_StartNewGrowButton);
lv_img_set_src(ui_Image7, &ui_img_plant_png);
lv_obj_set_width( ui_Image7, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image7, LV_SIZE_CONTENT);   /// 64
lv_obj_set_align( ui_Image7, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image7, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image7, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_DryAHarvestButton = lv_btn_create(ui_SplashScreen);
lv_obj_set_width( ui_DryAHarvestButton, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_DryAHarvestButton, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_DryAHarvestButton, 435 );
lv_obj_set_y( ui_DryAHarvestButton, 96 );
lv_obj_set_align( ui_DryAHarvestButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_DryAHarvestButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_DryAHarvestButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_DryAHarvestButton, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_DryAHarvestButton, lv_color_hex(0x2C472A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_DryAHarvestButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_DryAHarvestButton, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_DryAHarvestButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_DryAHarvestButton, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_DryAHarvestButton, 25, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_DryAHarvestButton, 25, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_DryAHarvestButton, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_DryAHarvestButton, 15, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label2 = lv_label_create(ui_DryAHarvestButton);
lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label2,"Dry       Harvest");
lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_44, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image10 = lv_img_create(ui_DryAHarvestButton);
lv_img_set_src(ui_Image10, &ui_img_dry_png);
lv_obj_set_width( ui_Image10, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image10, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image10, -42 );
lv_obj_set_y( ui_Image10, 3 );
lv_obj_set_align( ui_Image10, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image10, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image10, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_tomato = lv_img_create(ui_SplashScreen);
lv_img_set_src(ui_tomato, &ui_img_tomato_png);
lv_obj_set_width( ui_tomato, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_tomato, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_tomato, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_tomato, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_tomato, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_StartNewGrowButton, ui_event_StartNewGrowButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_DryAHarvestButton, ui_event_DryAHarvestButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_SplashScreen, ui_event_SplashScreen, LV_EVENT_ALL, NULL);

}
