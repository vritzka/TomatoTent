// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: TT

#include "../ui.h"

void ui_SoftwareUpdateScreen_screen_init(void)
{
ui_SoftwareUpdateScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SoftwareUpdateScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SoftwareUpdateScreen, lv_color_hex(0x28652A), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SoftwareUpdateScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_FirmwareUpgradeButton = lv_btn_create(ui_SoftwareUpdateScreen);
lv_obj_set_width( ui_FirmwareUpgradeButton, 100);
lv_obj_set_height( ui_FirmwareUpgradeButton, 50);
lv_obj_set_x( ui_FirmwareUpgradeButton, 0 );
lv_obj_set_y( ui_FirmwareUpgradeButton, 45 );
lv_obj_set_align( ui_FirmwareUpgradeButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_FirmwareUpgradeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_FirmwareUpgradeButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label21 = lv_label_create(ui_FirmwareUpgradeButton);
lv_obj_set_width( ui_Label21, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label21, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label21, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label21,"Upgrade");

ui_Image21 = lv_img_create(ui_SoftwareUpdateScreen);
lv_img_set_src(ui_Image21, &ui_img_713338696);
lv_obj_set_width( ui_Image21, LV_SIZE_CONTENT);  /// 64
lv_obj_set_height( ui_Image21, LV_SIZE_CONTENT);   /// 64
lv_obj_set_x( ui_Image21, -176 );
lv_obj_set_y( ui_Image21, -99 );
lv_obj_set_align( ui_Image21, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image21, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image21, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label10 = lv_label_create(ui_SoftwareUpdateScreen);
lv_obj_set_width( ui_Label10, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label10, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label10, 24 );
lv_obj_set_y( ui_Label10, -100 );
lv_obj_set_align( ui_Label10, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label10,"Software Upgrade");
lv_obj_set_style_text_font(ui_Label10, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImgButton1 = lv_imgbtn_create(ui_SoftwareUpdateScreen);
lv_imgbtn_set_src(ui_ImgButton1, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_1668913270, NULL);
lv_obj_set_width( ui_ImgButton1, 32);
lv_obj_set_height( ui_ImgButton1, 32);
lv_obj_set_x( ui_ImgButton1, 203 );
lv_obj_set_y( ui_ImgButton1, -125 );
lv_obj_set_align( ui_ImgButton1, LV_ALIGN_CENTER );
lv_obj_set_style_img_recolor(ui_ImgButton1, lv_color_hex(0xC3C3C3), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_ImgButton1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_UpgradeStatusBar = lv_bar_create(ui_SoftwareUpdateScreen);
lv_obj_set_width( ui_UpgradeStatusBar, 250);
lv_obj_set_height( ui_UpgradeStatusBar, 15);
lv_obj_set_x( ui_UpgradeStatusBar, 0 );
lv_obj_set_y( ui_UpgradeStatusBar, 103 );
lv_obj_set_align( ui_UpgradeStatusBar, LV_ALIGN_CENTER );

ui_SoftwareVersionsPanel = lv_obj_create(ui_SoftwareUpdateScreen);
lv_obj_set_width( ui_SoftwareVersionsPanel, 300);
lv_obj_set_height( ui_SoftwareVersionsPanel, 52);
lv_obj_set_x( ui_SoftwareVersionsPanel, 21 );
lv_obj_set_y( ui_SoftwareVersionsPanel, -30 );
lv_obj_set_align( ui_SoftwareVersionsPanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SoftwareVersionsPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SoftwareVersionsPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SoftwareVersionsPanel, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_SoftwareVersionsPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_SoftwareVersionsPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CurrentVersionLabel = lv_label_create(ui_SoftwareVersionsPanel);
lv_obj_set_width( ui_CurrentVersionLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_CurrentVersionLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_CurrentVersionLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_CurrentVersionLabel,"Already on latest Version (");

lv_obj_add_event_cb(ui_FirmwareUpgradeButton, ui_event_FirmwareUpgradeButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ImgButton1, ui_event_ImgButton1, LV_EVENT_ALL, NULL);

}
