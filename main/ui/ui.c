// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void fanspin_Animation( lv_obj_t *TargetObject, int delay);
void Gentle_rock_Animation( lv_obj_t *TargetObject, int delay);

// SCREEN: ui_SplashScreen
void ui_SplashScreen_screen_init(void);
void ui_event_SplashScreen( lv_event_t * e);
lv_obj_t *ui_SplashScreen;

// SCREEN: ui_LaunchScreen
void ui_LaunchScreen_screen_init(void);
lv_obj_t *ui_LaunchScreen;
lv_obj_t *ui_Image1;
void ui_event_StartNewGrow( lv_event_t * e);
lv_obj_t *ui_StartNewGrow;
lv_obj_t *ui_Label3;
lv_obj_t *ui_DryAHarverst;
lv_obj_t *ui_Label2;

// SCREEN: ui_HomeScreen
void ui_HomeScreen_screen_init(void);
void ui_event_HomeScreen( lv_event_t * e);
lv_obj_t *ui_HomeScreen;
lv_obj_t *ui_sun;
void ui_event_Panel2( lv_event_t * e);
lv_obj_t *ui_Panel2;
lv_obj_t *ui_Bar2;
lv_obj_t *ui_Label10;
lv_obj_t *ui_Label11;
lv_obj_t *ui_Panel3;
lv_obj_t *ui_Label5;
lv_obj_t *ui_Label1;
lv_obj_t *ui_Image5;
lv_obj_t *ui_Panel1;
lv_obj_t *ui_Label4;
lv_obj_t *ui_Label6;
lv_obj_t *ui_Image3;
lv_obj_t *ui_Panel5;
lv_obj_t *ui_Label7;
lv_obj_t *ui_Label8;
lv_obj_t *ui_Image2;
lv_obj_t *ui_Panel4;
lv_obj_t *ui_Label9;
lv_obj_t *ui_Label13;
lv_obj_t *ui_fan;
lv_obj_t *ui_Image6;

// SCREEN: ui_LightDurationScreen
void ui_LightDurationScreen_screen_init(void);
lv_obj_t *ui_LightDurationScreen;
lv_obj_t *ui_Panel8;
void ui_event_LightDurationSlider( lv_event_t * e);
lv_obj_t *ui_LightDurationSlider;
lv_obj_t *ui_LightDurationLabel;
lv_obj_t *ui_Label12;
lv_obj_t *ui_Panel9;
lv_obj_t *ui_Slider1;
lv_obj_t *ui_Label16;
lv_obj_t *ui_Label17;

// SCREEN: ui_SettingsScreen
void ui_SettingsScreen_screen_init(void);
void ui_event_SettingsScreen( lv_event_t * e);
lv_obj_t *ui_SettingsScreen;
lv_obj_t *ui_Panel6;
void ui_event_Slider4( lv_event_t * e);
lv_obj_t *ui_Slider4;
lv_obj_t *ui_LCDBrightness;
lv_obj_t *ui____initial_actions0;
const lv_img_dsc_t *ui_imgset_bg[1] = {&ui_img_bg2_png};
const lv_img_dsc_t *ui_imgset_1030300351[1] = {&ui_img_1669444289};
const lv_img_dsc_t *ui_imgset_421117529[1] = {&ui_img_182264864};
const lv_img_dsc_t *ui_imgset_877854534[2] = {&ui_img_60476769, &ui_img_1142205948};
const lv_img_dsc_t *ui_imgset_1293913949[1] = {&ui_img_303216376};
const lv_img_dsc_t *ui_imgset_sun[1] = {&ui_img_sun2_png};
const lv_img_dsc_t *ui_imgset_521497507[1] = {&ui_img_1484485426};

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
lv_anim_set_time(&PropertyAnimation_0, 1000);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom );
lv_anim_set_values(&PropertyAnimation_0, 0, 30 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_ease_in);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 1000);
lv_anim_set_playback_delay(&PropertyAnimation_0, 100);
lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE );
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_zoom );
lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_SplashScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      play_intro( e );
}
}
void ui_event_StartNewGrow( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_OVER_TOP, 500, 0);
}
}
void ui_event_HomeScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      fanspin_Animation(ui_fan, 0);
      Gentle_rock_Animation(ui_sun, 0);
}
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_SettingsScreen, LV_SCR_LOAD_ANIM_MOVE_TOP, 300, 0);
}
}
void ui_event_Panel2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_LONG_PRESSED) {
      _ui_screen_change( ui_LightDurationScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
}
void ui_event_LightDurationSlider( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      light_duration_slider( e );
}
}
void ui_event_SettingsScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_HomeScreen, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 0);
}
}
void ui_event_Slider4( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      _ui_slider_set_text_value( ui_LCDBrightness, target, "", "%");
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_SplashScreen_screen_init();
ui_LaunchScreen_screen_init();
ui_HomeScreen_screen_init();
ui_LightDurationScreen_screen_init();
ui_SettingsScreen_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_SplashScreen);
}
