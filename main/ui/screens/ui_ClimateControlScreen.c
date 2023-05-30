// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_ClimateControlScreen_screen_init(void)
{
ui_ClimateControlScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ClimateControlScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ClimateControlScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ClimateControlScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ClimateSettingsScreen = lv_label_create(ui_ClimateControlScreen);
lv_obj_set_width( ui_ClimateSettingsScreen, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ClimateSettingsScreen, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ClimateSettingsScreen, -146 );
lv_obj_set_y( ui_ClimateSettingsScreen, -123 );
lv_obj_set_align( ui_ClimateSettingsScreen, LV_ALIGN_CENTER );
lv_label_set_text(ui_ClimateSettingsScreen,"Climate");
lv_obj_set_style_text_font(ui_ClimateSettingsScreen, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image14 = lv_img_create(ui_ClimateControlScreen);
lv_img_set_src(ui_Image14, &ui_img_261459337);
lv_obj_set_width( ui_Image14, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image14, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image14, -149 );
lv_obj_set_y( ui_Image14, -67 );
lv_obj_set_align( ui_Image14, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image14, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image14, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel3 = lv_obj_create(ui_ClimateControlScreen);
lv_obj_set_width( ui_Panel3, 220);
lv_obj_set_height( ui_Panel3, 120);
lv_obj_set_x( ui_Panel3, -118 );
lv_obj_set_y( ui_Panel3, 73 );
lv_obj_set_align( ui_Panel3, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel3, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Dropdown2 = lv_dropdown_create(ui_Panel3);
lv_dropdown_set_options( ui_Dropdown2, "10%\n20%\n30%\n40%\n50%\n60%\n70%\n80%\n90%" );
lv_obj_set_width( ui_Dropdown2, 150);
lv_obj_set_height( ui_Dropdown2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Dropdown2, 0 );
lv_obj_set_y( ui_Dropdown2, 17 );
lv_obj_set_align( ui_Dropdown2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Dropdown2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_set_style_text_align(ui_Dropdown2, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Dropdown2, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_text_color(ui_Dropdown2, lv_color_hex(0x555CFA), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Dropdown2, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

ui_Label18 = lv_label_create(ui_Panel3);
lv_obj_set_width( ui_Label18, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label18, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label18, 0 );
lv_obj_set_y( ui_Label18, -36 );
lv_obj_set_align( ui_Label18, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label18,"Target Humidity");
lv_obj_set_style_text_font(ui_Label18, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel7 = lv_obj_create(ui_ClimateControlScreen);
lv_obj_set_width( ui_Panel7, 220);
lv_obj_set_height( ui_Panel7, 120);
lv_obj_set_x( ui_Panel7, 121 );
lv_obj_set_y( ui_Panel7, 70 );
lv_obj_set_align( ui_Panel7, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel7, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel7, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel7, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Dropdown1 = lv_dropdown_create(ui_Panel7);
lv_dropdown_set_options( ui_Dropdown1, "10°C\n12°C\n14°C\n16°C\n18°C\n20°C\n22°C\n24°C\n26°C\n28°C\n30°C\n32°C" );
lv_obj_set_width( ui_Dropdown1, 150);
lv_obj_set_height( ui_Dropdown1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Dropdown1, 0 );
lv_obj_set_y( ui_Dropdown1, 17 );
lv_obj_set_align( ui_Dropdown1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Dropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_set_style_text_font(ui_Dropdown1, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_text_color(ui_Dropdown1, lv_color_hex(0xB29D15), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Dropdown1, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

ui_Label17 = lv_label_create(ui_Panel7);
lv_obj_set_width( ui_Label17, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label17, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label17, 0 );
lv_obj_set_y( ui_Label17, -36 );
lv_obj_set_align( ui_Label17, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label17,"Target Temperature");
lv_obj_set_style_text_font(ui_Label17, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel2 = lv_obj_create(ui_ClimateControlScreen);
lv_obj_set_width( ui_Panel2, 220);
lv_obj_set_height( ui_Panel2, 80);
lv_obj_set_x( ui_Panel2, 39 );
lv_obj_set_y( ui_Panel2, -61 );
lv_obj_set_align( ui_Panel2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Switch2 = lv_switch_create(ui_Panel2);
lv_obj_set_width( ui_Switch2, 50);
lv_obj_set_height( ui_Switch2, 25);
lv_obj_set_x( ui_Switch2, 0 );
lv_obj_set_y( ui_Switch2, 3 );
lv_obj_set_align( ui_Switch2, LV_ALIGN_CENTER );

ui_Label19 = lv_label_create(ui_Panel2);
lv_obj_set_width( ui_Label19, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label19, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label19, -63 );
lv_obj_set_y( ui_Label19, 1 );
lv_obj_set_align( ui_Label19, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label19,"Auto");
lv_obj_set_style_text_font(ui_Label19, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label20 = lv_label_create(ui_Panel2);
lv_obj_set_width( ui_Label20, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label20, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label20, 66 );
lv_obj_set_y( ui_Label20, 3 );
lv_obj_set_align( ui_Label20, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label20,"Manual");
lv_obj_set_style_text_font(ui_Label20, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImgButton6 = lv_imgbtn_create(ui_ClimateControlScreen);
lv_imgbtn_set_src(ui_ImgButton6, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_1668913270, NULL);
lv_obj_set_width( ui_ImgButton6, 32);
lv_obj_set_height( ui_ImgButton6, 32);
lv_obj_set_x( ui_ImgButton6, 203 );
lv_obj_set_y( ui_ImgButton6, -126 );
lv_obj_set_align( ui_ImgButton6, LV_ALIGN_CENTER );
lv_obj_set_style_img_recolor(ui_ImgButton6, lv_color_hex(0xC3C3C3), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_ImgButton6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_ImgButton6, ui_event_ImgButton6, LV_EVENT_ALL, NULL);

}
