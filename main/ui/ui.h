// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#ifndef _TT_UI_H
#define _TT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
void fanspin_Animation( lv_obj_t *TargetObject, int delay);
void Gentle_rock_Animation( lv_obj_t *TargetObject, int delay);
void startGrowButtonAppear_Animation( lv_obj_t *TargetObject, int delay);
void dryHarvestButtonAppear_Animation( lv_obj_t *TargetObject, int delay);
void moveTomato_Animation( lv_obj_t *TargetObject, int delay);
// SCREEN: ui_SplashScreen
void ui_SplashScreen_screen_init(void);
void ui_event_SplashScreen( lv_event_t * e);
extern lv_obj_t *ui_SplashScreen;
void ui_event_StartNewGrowButton( lv_event_t * e);
extern lv_obj_t *ui_StartNewGrowButton;
extern lv_obj_t *ui_Label3;
extern lv_obj_t *ui_Image7;
void ui_event_DryAHarverstButton( lv_event_t * e);
extern lv_obj_t *ui_DryAHarverstButton;
extern lv_obj_t *ui_Label2;
extern lv_obj_t *ui_Image10;
extern lv_obj_t *ui_tomato;
// SCREEN: ui_HomeScreen
void ui_HomeScreen_screen_init(void);
void ui_event_HomeScreen( lv_event_t * e);
extern lv_obj_t *ui_HomeScreen;
extern lv_obj_t *ui_sun;
void ui_event_TemperaturePanel( lv_event_t * e);
extern lv_obj_t *ui_TemperaturePanel;
extern lv_obj_t *ui_Label5;
extern lv_obj_t *ui_Label1;
extern lv_obj_t *ui_Image5;
void ui_event_Panel1( lv_event_t * e);
extern lv_obj_t *ui_Panel1;
extern lv_obj_t *ui_Label4;
extern lv_obj_t *ui_Label6;
extern lv_obj_t *ui_Image3;
extern lv_obj_t *ui_Panel5;
extern lv_obj_t *ui_Label7;
extern lv_obj_t *ui_Label8;
extern lv_obj_t *ui_Image2;
void ui_event_Panel4( lv_event_t * e);
extern lv_obj_t *ui_Panel4;
extern lv_obj_t *ui_Label9;
extern lv_obj_t *ui_Label13;
extern lv_obj_t *ui_fan;
void ui_event_Panel11( lv_event_t * e);
extern lv_obj_t *ui_Panel11;
extern lv_obj_t *ui_DayCounterMainLabel;
extern lv_obj_t *ui_Label10;
extern lv_obj_t *ui_ArrowUp1;
void ui_event_ImgButton3( lv_event_t * e);
extern lv_obj_t *ui_ImgButton3;
// SCREEN: ui_LightDurationScreen
void ui_LightDurationScreen_screen_init(void);
void ui_event_LightDurationScreen( lv_event_t * e);
extern lv_obj_t *ui_LightDurationScreen;
extern lv_obj_t *ui_Panel8;
void ui_event_LightDurationSlider( lv_event_t * e);
extern lv_obj_t *ui_LightDurationSlider;
void ui_event_NowSlider( lv_event_t * e);
extern lv_obj_t *ui_NowSlider;
extern lv_obj_t *ui_Image8;
extern lv_obj_t *ui_Image9;
extern lv_obj_t *ui_ArrowDown;
extern lv_obj_t *ui_ArrowUp;
extern lv_obj_t *ui_LightDurationLightLabel;
extern lv_obj_t *ui_LightDurationDarkLabel;
// SCREEN: ui_LEDBrightnessScreen
void ui_LEDBrightnessScreen_screen_init(void);
void ui_event_LEDBrightnessScreen( lv_event_t * e);
extern lv_obj_t *ui_LEDBrightnessScreen;
extern lv_obj_t *ui_LEDBrightnessLabel;
extern lv_obj_t *ui_arrowdown1;
extern lv_obj_t *ui_Label12;
extern lv_obj_t *ui_Image4;
extern lv_obj_t *ui_Panel6;
void ui_event_LEDBrightnessSlider( lv_event_t * e);
extern lv_obj_t *ui_LEDBrightnessSlider;
extern lv_obj_t *ui_arrowdown2;
// SCREEN: ui_DayCounterScreen
void ui_DayCounterScreen_screen_init(void);
void ui_event_DayCounterScreen( lv_event_t * e);
extern lv_obj_t *ui_DayCounterScreen;
extern lv_obj_t *ui_Label11;
void ui_event_DayDownButton( lv_event_t * e);
extern lv_obj_t *ui_DayDownButton;
extern lv_obj_t *ui_DayCounterLabel;
extern lv_obj_t *ui_Image1;
extern lv_obj_t *ui_Panel10;
extern lv_obj_t *ui_Image15;
extern lv_obj_t *ui_Button1;
extern lv_obj_t *ui_Label22;
void ui_event_ImgButton9( lv_event_t * e);
extern lv_obj_t *ui_ImgButton9;
void ui_event_DayUpButton( lv_event_t * e);
extern lv_obj_t *ui_DayUpButton;
// SCREEN: ui_GraphScreen
void ui_GraphScreen_screen_init(void);
void ui_event_GraphScreen( lv_event_t * e);
extern lv_obj_t *ui_GraphScreen;
extern lv_obj_t *ui_Chart2;
extern lv_obj_t *ui_Image18;
extern lv_obj_t *ui_Panel14;
extern lv_obj_t *ui_Image6;
extern lv_obj_t *ui_Panel9;
extern lv_obj_t *ui_Image19;
extern lv_obj_t *ui_Panel15;
extern lv_obj_t *ui_Image11;
extern lv_obj_t *ui_Panel16;
extern lv_obj_t *ui_Image21;
// SCREEN: ui_FanSettingsScreen
void ui_FanSettingsScreen_screen_init(void);
void ui_event_FanSettingsScreen( lv_event_t * e);
extern lv_obj_t *ui_FanSettingsScreen;
extern lv_obj_t *ui_Label14;
extern lv_obj_t *ui_Image12;
extern lv_obj_t *ui_Panel13;
void ui_event_fanSpeedSlider( lv_event_t * e);
extern lv_obj_t *ui_fanSpeedSlider;
void ui_event_ImgButton5( lv_event_t * e);
extern lv_obj_t *ui_ImgButton5;
extern lv_obj_t *ui_FanSpeedMinLabel;
extern lv_obj_t *ui_FanSpeedMaxLabel;
extern lv_obj_t *ui_Label25;
// SCREEN: ui_ClimateControlScreen
void ui_ClimateControlScreen_screen_init(void);
extern lv_obj_t *ui_ClimateControlScreen;
extern lv_obj_t *ui_ClimateSettingsScreen;
extern lv_obj_t *ui_Image14;
extern lv_obj_t *ui_Panel3;
extern lv_obj_t *ui_Dropdown2;
extern lv_obj_t *ui_Label18;
extern lv_obj_t *ui_Panel7;
extern lv_obj_t *ui_Dropdown1;
extern lv_obj_t *ui_Label17;
extern lv_obj_t *ui_Panel2;
extern lv_obj_t *ui_climateModeSwitch;
extern lv_obj_t *ui_Label19;
extern lv_obj_t *ui_Label20;
void ui_event_ImgButton6( lv_event_t * e);
extern lv_obj_t *ui_ImgButton6;
// SCREEN: ui_WifiSettingsScreen
void ui_WifiSettingsScreen_screen_init(void);
void ui_event_WifiSettingsScreen( lv_event_t * e);
extern lv_obj_t *ui_WifiSettingsScreen;
void ui_event_Keyboard2( lv_event_t * e);
extern lv_obj_t *ui_Keyboard2;
extern lv_obj_t *ui_WifiPassword;
extern lv_obj_t *ui_WifiDropdown;
extern lv_obj_t *ui_Image13;
void ui_event_WifiSwitch( lv_event_t * e);
extern lv_obj_t *ui_WifiSwitch;
extern lv_obj_t *ui_WifiStatusLabel;
void ui_event_ImgButton7( lv_event_t * e);
extern lv_obj_t *ui_ImgButton7;
// SCREEN: ui_GeneralSettingsScreen
void ui_GeneralSettingsScreen_screen_init(void);
void ui_event_GeneralSettingsScreen( lv_event_t * e);
extern lv_obj_t *ui_GeneralSettingsScreen;
extern lv_obj_t *ui_Label23;
extern lv_obj_t *ui_Panel12;
extern lv_obj_t *ui_Label24;
void ui_event_ScreenBrightnessSlider( lv_event_t * e);
extern lv_obj_t *ui_ScreenBrightnessSlider;
extern lv_obj_t *ui_ScreenBrightnessLabel;
extern lv_obj_t *ui_Image17;
extern lv_obj_t *ui_Panel18;
extern lv_obj_t *ui_Switch4;
extern lv_obj_t *ui_Panel17;
void ui_event_TempUnitSwitch( lv_event_t * e);
extern lv_obj_t *ui_TempUnitSwitch;
extern lv_obj_t *ui_Label27;
extern lv_obj_t *ui_Label16;
extern lv_obj_t *ui_Image20;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_plant_png);   // assets/plant.png
LV_IMG_DECLARE( ui_img_dry_png);   // assets/dry.png
LV_IMG_DECLARE( ui_img_tomato_png);   // assets/tomato.png
LV_IMG_DECLARE( ui_img_791711567);   // assets/sun-3.png
LV_IMG_DECLARE( ui_img_1484485426);   // assets/thermometer-2.png
LV_IMG_DECLARE( ui_img_humidity_png);   // assets/humidity.png
LV_IMG_DECLARE( ui_img_dew_png);   // assets/dew.png
LV_IMG_DECLARE( ui_img_1142205948);   // assets/fan-3.png
LV_IMG_DECLARE( ui_img_upload_png);   // assets/upload.png
LV_IMG_DECLARE( ui_img_wifi_png);   // assets/wifi.png
LV_IMG_DECLARE( ui_img_303216376);   // assets/sliders-2.png
LV_IMG_DECLARE( ui_img_now_arrow_2_png);   // assets/now_arrow_2.png
LV_IMG_DECLARE( ui_img_432815713);   // assets/night-mode.png
LV_IMG_DECLARE( ui_img_1756057095);   // assets/led-light-3.png
LV_IMG_DECLARE( ui_img_320680866);   // assets/led-light-2.png
LV_IMG_DECLARE( ui_img_1749885216);   // assets/chevron-downwards-arrow.png
LV_IMG_DECLARE( ui_img_appointment_png);   // assets/appointment.png
LV_IMG_DECLARE( ui_img_harvest_png);   // assets/harvest.png
LV_IMG_DECLARE( ui_img_1668913270);   // assets/back-up.png
LV_IMG_DECLARE( ui_img_2060199463);   // assets/chevron-upwards-arrow.png
LV_IMG_DECLARE( ui_img_60476769);   // assets/fan-2.png
LV_IMG_DECLARE( ui_img_261459337);   // assets/climate-change.png
LV_IMG_DECLARE( ui_img_953604683);   // assets/wifi-2.png
LV_IMG_DECLARE( ui_img_bg2_png);   // assets/bg2.png
LV_IMG_DECLARE( ui_img_1669444289);   // assets/corners-bgs1.png
LV_IMG_DECLARE( ui_img_182264864);   // assets/corners-details2.png
LV_IMG_DECLARE( ui_img_1180469587);   // assets/moon-2.png
LV_IMG_DECLARE( ui_img_290017612);   // assets/sun-2.png

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
