// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void fanspin_Animation( lv_obj_t *TargetObject, int delay);
void Gentle_rock_Animation( lv_obj_t *TargetObject, int delay);
void startGrowButtonAppear_Animation( lv_obj_t *TargetObject, int delay);
void dryHarvestButtonAppear_Animation( lv_obj_t *TargetObject, int delay);
void moveTomato_Animation( lv_obj_t *TargetObject, int delay);

// SCREEN: ui_SplashScreen
void ui_SplashScreen_screen_init(void);
void ui_event_SplashScreen( lv_event_t * e);
lv_obj_t *ui_SplashScreen;
void ui_event_StartNewGrowButton( lv_event_t * e);
lv_obj_t *ui_StartNewGrowButton;
lv_obj_t *ui_Label3;
lv_obj_t *ui_Image7;
void ui_event_DryAHarvestButton( lv_event_t * e);
lv_obj_t *ui_DryAHarvestButton;
lv_obj_t *ui_Label2;
lv_obj_t *ui_Image10;
lv_obj_t *ui_tomato;

// SCREEN: ui_HomeScreen
void ui_HomeScreen_screen_init(void);
void ui_event_HomeScreen( lv_event_t * e);
lv_obj_t *ui_HomeScreen;
lv_obj_t *ui_HomeSky;
void ui_event_TemperaturePanel( lv_event_t * e);
lv_obj_t *ui_TemperaturePanel;
lv_obj_t *ui_Label5;
lv_obj_t *ui_HomeTempUnitLabel;
lv_obj_t *ui_Image5;
void ui_event_Panel1( lv_event_t * e);
lv_obj_t *ui_Panel1;
lv_obj_t *ui_Label4;
lv_obj_t *ui_Label6;
lv_obj_t *ui_Image3;
lv_obj_t *ui_Panel5;
lv_obj_t *ui_Label7;
lv_obj_t *ui_Label8;
lv_obj_t *ui_Image2;
void ui_event_Panel4( lv_event_t * e);
lv_obj_t *ui_Panel4;
lv_obj_t *ui_Label9;
lv_obj_t *ui_Label13;
lv_obj_t *ui_Fan;
void ui_event_Panel11( lv_event_t * e);
lv_obj_t *ui_Panel11;
lv_obj_t *ui_DayCounterMainLabel;
lv_obj_t *ui_TimeLeftLabel;
lv_obj_t *ui_DayNightLabel;
lv_obj_t *ui_ArrowUp1;
void ui_event_WifiIcon( lv_event_t * e);
lv_obj_t *ui_WifiIcon;

// SCREEN: ui_LightDurationScreen
void ui_LightDurationScreen_screen_init(void);
void ui_event_LightDurationScreen( lv_event_t * e);
lv_obj_t *ui_LightDurationScreen;
lv_obj_t *ui_Panel8;
void ui_event_LightDurationSlider( lv_event_t * e);
lv_obj_t *ui_LightDurationSlider;
void ui_event_NowSlider( lv_event_t * e);
lv_obj_t *ui_NowSlider;
lv_obj_t *ui_Image8;
lv_obj_t *ui_Image9;
lv_obj_t *ui_ArrowDown;
lv_obj_t *ui_ArrowUp;
lv_obj_t *ui_LightDurationLightLabel;
lv_obj_t *ui_LightDurationDarkLabel;

// SCREEN: ui_LEDBrightnessScreen
void ui_LEDBrightnessScreen_screen_init(void);
void ui_event_LEDBrightnessScreen( lv_event_t * e);
lv_obj_t *ui_LEDBrightnessScreen;
lv_obj_t *ui_LEDBrightnessLabel;
lv_obj_t *ui_arrowdown1;
lv_obj_t *ui_Label12;
lv_obj_t *ui_Image4;
lv_obj_t *ui_Panel6;
void ui_event_LEDBrightnessSlider( lv_event_t * e);
lv_obj_t *ui_LEDBrightnessSlider;
lv_obj_t *ui_arrowdown2;

// SCREEN: ui_DayCounterScreen
void ui_DayCounterScreen_screen_init(void);
void ui_event_DayCounterScreen( lv_event_t * e);
lv_obj_t *ui_DayCounterScreen;
lv_obj_t *ui_Label11;
void ui_event_DayDownButton( lv_event_t * e);
lv_obj_t *ui_DayDownButton;
lv_obj_t *ui_DayCounterLabel;
lv_obj_t *ui_Image1;
lv_obj_t *ui_Panel10;
lv_obj_t *ui_Image15;
void ui_event_Button1( lv_event_t * e);
lv_obj_t *ui_Button1;
lv_obj_t *ui_Label22;
void ui_event_ImgButton9( lv_event_t * e);
lv_obj_t *ui_ImgButton9;
void ui_event_DayUpButton( lv_event_t * e);
lv_obj_t *ui_DayUpButton;

// SCREEN: ui_GraphScreen
void ui_GraphScreen_screen_init(void);
void ui_event_GraphScreen( lv_event_t * e);
lv_obj_t *ui_GraphScreen;
lv_obj_t *ui_Chart2;
lv_obj_t *ui_Image18;
lv_obj_t *ui_Panel14;
lv_obj_t *ui_Image6;
lv_obj_t *ui_Panel9;
lv_obj_t *ui_Image19;
lv_obj_t *ui_Panel15;
lv_obj_t *ui_Image11;
lv_obj_t *ui_Panel16;
lv_obj_t *ui_Fan2;

// SCREEN: ui_FanSettingsScreen
void ui_FanSettingsScreen_screen_init(void);
void ui_event_FanSettingsScreen( lv_event_t * e);
lv_obj_t *ui_FanSettingsScreen;
lv_obj_t *ui_Label14;
lv_obj_t *ui_Image12;
lv_obj_t *ui_Panel13;
void ui_event_fanSpeedSlider( lv_event_t * e);
lv_obj_t *ui_fanSpeedSlider;
void ui_event_ImgButton5( lv_event_t * e);
lv_obj_t *ui_ImgButton5;
lv_obj_t *ui_FanSpeedMinLabel;
lv_obj_t *ui_FanSpeedMaxLabel;
lv_obj_t *ui_Label25;

// SCREEN: ui_ClimateControlScreen
void ui_ClimateControlScreen_screen_init(void);
lv_obj_t *ui_ClimateControlScreen;
lv_obj_t *ui_ClimateSettingsScreen;
lv_obj_t *ui_Image14;
lv_obj_t *ui_HumiditySwitchPanel;
void ui_event_HumidityDropdown( lv_event_t * e);
lv_obj_t *ui_HumidityDropdown;
lv_obj_t *ui_Label18;
lv_obj_t *ui_TemperatureSwitchPanel;
void ui_event_TemperatureDropdown( lv_event_t * e);
lv_obj_t *ui_TemperatureDropdown;
lv_obj_t *ui_Label17;
lv_obj_t *ui_Panel2;
void ui_event_ClimateModeSwitch( lv_event_t * e);
lv_obj_t *ui_ClimateModeSwitch;
lv_obj_t *ui_Label19;
lv_obj_t *ui_Label20;
void ui_event_ImgButton6( lv_event_t * e);
lv_obj_t *ui_ImgButton6;
lv_obj_t *ui_Panel17;
void ui_event_TempUnitSwitch( lv_event_t * e);
lv_obj_t *ui_TempUnitSwitch;
lv_obj_t *ui_Label27;
lv_obj_t *ui_Label16;

// SCREEN: ui_WifiSettingsScreen
void ui_WifiSettingsScreen_screen_init(void);
void ui_event_WifiSettingsScreen( lv_event_t * e);
lv_obj_t *ui_WifiSettingsScreen;
void ui_event_Keyboard2( lv_event_t * e);
lv_obj_t *ui_Keyboard2;
lv_obj_t *ui_WifiPassword;
lv_obj_t *ui_WifiDropdown;
lv_obj_t *ui_Image13;
void ui_event_WifiSwitch( lv_event_t * e);
lv_obj_t *ui_WifiSwitch;
lv_obj_t *ui_WifiStatusLabel;
void ui_event_ImgButton7( lv_event_t * e);
lv_obj_t *ui_ImgButton7;
void ui_event_ImgButton2( lv_event_t * e);
lv_obj_t *ui_ImgButton2;
void ui_event_ImgButton4( lv_event_t * e);
lv_obj_t *ui_ImgButton4;
lv_obj_t *ui_QrCode1;

// SCREEN: ui_GeneralSettingsScreen
void ui_GeneralSettingsScreen_screen_init(void);
void ui_event_GeneralSettingsScreen( lv_event_t * e);
lv_obj_t *ui_GeneralSettingsScreen;
lv_obj_t *ui_Label23;
lv_obj_t *ui_Panel12;
lv_obj_t *ui_Label24;
void ui_event_ScreenBrightnessSlider( lv_event_t * e);
lv_obj_t *ui_ScreenBrightnessSlider;
lv_obj_t *ui_ScreenBrightnessLabel;
lv_obj_t *ui_Image17;
lv_obj_t *ui_Panel18;
lv_obj_t *ui_Switch4;
lv_obj_t *ui_Image20;

// SCREEN: ui_SoftwareUpdateScreen
void ui_SoftwareUpdateScreen_screen_init(void);
lv_obj_t *ui_SoftwareUpdateScreen;
void ui_event_FirmwareUpgradeButton( lv_event_t * e);
lv_obj_t *ui_FirmwareUpgradeButton;
lv_obj_t *ui_Label21;
lv_obj_t *ui_Image21;
lv_obj_t *ui_Label10;
void ui_event_ImgButton1( lv_event_t * e);
lv_obj_t *ui_ImgButton1;
lv_obj_t *ui_UpgradeStatusBar;
lv_obj_t *ui_SoftwareVersionsPanel;
lv_obj_t *ui_CurrentVersionLabel;
lv_obj_t *ui____initial_actions0;
const lv_img_dsc_t *ui_imgset_bg[1] = {&ui_img_bg2_png};
const lv_img_dsc_t *ui_imgset_1030300351[1] = {&ui_img_1669444289};
const lv_img_dsc_t *ui_imgset_421117529[1] = {&ui_img_182264864};
const lv_img_dsc_t *ui_imgset_877854534[2] = {&ui_img_60476769, &ui_img_1142205948};
const lv_img_dsc_t *ui_imgset_1334665161[2] = {&ui_img_320680866, &ui_img_1756057095};
const lv_img_dsc_t *ui_imgset_1554743838[1] = {&ui_img_1180469587};
const lv_img_dsc_t *ui_imgset_now_arrow_[1] = {&ui_img_now_arrow_2_png};
const lv_img_dsc_t *ui_imgset_1293913949[1] = {&ui_img_303216376};
const lv_img_dsc_t *ui_imgset_459865801[2] = {&ui_img_290017612, &ui_img_791711567};
const lv_img_dsc_t *ui_imgset_521497507[1] = {&ui_img_1484485426};
const lv_img_dsc_t *ui_imgset_1675718514[1] = {&ui_img_953604683};
const lv_img_dsc_t *ui_imgset_co[1] = {&ui_img_co2_png};
const lv_img_dsc_t *ui_imgset_37643851[1] = {&ui_img_713338696};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void fanspin_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 1500);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle );
lv_anim_set_values(&PropertyAnimation_0, 0, 3600 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_linear);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 0);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE );
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle );
lv_anim_start(&PropertyAnimation_0);

}
void Gentle_rock_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 200);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom );
lv_anim_set_values(&PropertyAnimation_0, 0, 10 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_linear);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 200);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE );
lv_anim_set_repeat_delay(&PropertyAnimation_0, 3000);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_zoom );
lv_anim_start(&PropertyAnimation_0);

}
void startGrowButtonAppear_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 1000);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x );
lv_anim_set_values(&PropertyAnimation_0, 0, 430 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_overshoot);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 0);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x );
lv_anim_start(&PropertyAnimation_0);

}
void dryHarvestButtonAppear_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 1000);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x );
lv_anim_set_values(&PropertyAnimation_0, 0, -435 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_overshoot);
lv_anim_set_delay( &PropertyAnimation_0, delay + 300 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 0);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x );
lv_anim_start(&PropertyAnimation_0);

}
void moveTomato_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 400);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x );
lv_anim_set_values(&PropertyAnimation_0, 0, -170 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_overshoot);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 0);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x );
lv_anim_start(&PropertyAnimation_0);
ui_anim_user_data_t *PropertyAnimation_1_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_1_user_data->target = TargetObject;
PropertyAnimation_1_user_data->val = -1;
lv_anim_t PropertyAnimation_1;
lv_anim_init(&PropertyAnimation_1);
lv_anim_set_time(&PropertyAnimation_1, 400);
lv_anim_set_user_data(&PropertyAnimation_1, PropertyAnimation_1_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_y );
lv_anim_set_values(&PropertyAnimation_1, 0, -110 );
lv_anim_set_path_cb( &PropertyAnimation_1, lv_anim_path_overshoot);
lv_anim_set_delay( &PropertyAnimation_1, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_1, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_1, 0);
lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
lv_anim_set_early_apply( &PropertyAnimation_1, false );
lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_y );
lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_SplashScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      init_tomatotent( e );
}
}
void ui_event_StartNewGrowButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      start_grow( e );
}
}
void ui_event_DryAHarvestButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_FADE_ON, 1000, 0);
}
}
void ui_event_HomeScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_LightDurationScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0);
}
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_GeneralSettingsScreen, LV_SCR_LOAD_ANIM_MOVE_TOP, 500, 0);
}
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_GraphScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
}
}
void ui_event_TemperaturePanel( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_LONG_PRESSED) {
      _ui_screen_change( ui_ClimateControlScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_Panel1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_LONG_PRESSED) {
      _ui_screen_change( ui_ClimateControlScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_Panel4( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_LONG_PRESSED) {
      _ui_screen_change( ui_FanSettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_Panel11( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_LONG_PRESSED) {
      _ui_screen_change( ui_DayCounterScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_WifiIcon( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_WifiSettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_LightDurationScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_LEDBrightnessScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
}
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
}
if ( event_code == LV_EVENT_SCREEN_UNLOAD_START) {
      save_light_duration_screen( e );
}
}
void ui_event_LightDurationSlider( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      light_duration_slider( e );
}
}
void ui_event_NowSlider( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      now_slider( e );
}
}
void ui_event_LEDBrightnessScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_LightDurationScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0);
}
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_DayCounterScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
}
if ( event_code == LV_EVENT_SCREEN_UNLOAD_START) {
      save_led_brightness_screen( e );
}
}
void ui_event_LEDBrightnessSlider( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      LEDBrightnessSlider( e );
}
}
void ui_event_DayCounterScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_LEDBrightnessScreen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
}
}
void ui_event_DayDownButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      decrease_day_counter( e );
}
}
void ui_event_Button1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      stop_grow( e );
}
}
void ui_event_ImgButton9( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_DayUpButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      increase_day_counter( e );
}
}
void ui_event_GraphScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
}
}
void ui_event_FanSettingsScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_UNLOAD_START) {
      save_fan_settings_screen( e );
}
}
void ui_event_fanSpeedSlider( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      fanspeed_slider( e );
}
}
void ui_event_ImgButton5( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_HumidityDropdown( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      humidity_dropdown( e );
}
}
void ui_event_TemperatureDropdown( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      temperature_dropdown( e );
}
}
void ui_event_ClimateModeSwitch( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      climate_mode_switch( e );
}
}
void ui_event_ImgButton6( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_TempUnitSwitch( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      temp_unit_switch( e );
}
}
void ui_event_WifiSettingsScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_UNLOAD_START) {
      save_wifi_screen( e );
}
}
void ui_event_Keyboard2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_READY) {
      WifiKeyboardReady( e );
}
}
void ui_event_WifiSwitch( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      wifi_switch( e );
}
}
void ui_event_ImgButton7( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_ImgButton2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_SoftwareUpdateScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_ImgButton4( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      wifi_scan_button( e );
}
}
void ui_event_GeneralSettingsScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0);
}
if ( event_code == LV_EVENT_SCREEN_UNLOAD_START) {
      save_general_settings_screen( e );
}
}
void ui_event_ScreenBrightnessSlider( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      screen_brightness_slider( e );
}
}
void ui_event_FirmwareUpgradeButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      software_upgrade_button( e );
}
}
void ui_event_ImgButton1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_WifiSettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_SplashScreen_screen_init();
ui_HomeScreen_screen_init();
ui_LightDurationScreen_screen_init();
ui_LEDBrightnessScreen_screen_init();
ui_DayCounterScreen_screen_init();
ui_GraphScreen_screen_init();
ui_FanSettingsScreen_screen_init();
ui_ClimateControlScreen_screen_init();
ui_WifiSettingsScreen_screen_init();
ui_GeneralSettingsScreen_screen_init();
ui_SoftwareUpdateScreen_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_SplashScreen);
}
