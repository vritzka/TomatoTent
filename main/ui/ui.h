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
// SCREEN: ui_SplashScreen
void ui_SplashScreen_screen_init(void);
void ui_event_SplashScreen( lv_event_t * e);
extern lv_obj_t *ui_SplashScreen;
// SCREEN: ui_LaunchScreen
void ui_LaunchScreen_screen_init(void);
extern lv_obj_t *ui_LaunchScreen;
extern lv_obj_t *ui_Image1;
void ui_event_StartNewGrow( lv_event_t * e);
extern lv_obj_t *ui_StartNewGrow;
extern lv_obj_t *ui_Label3;
extern lv_obj_t *ui_DryAHarverst;
extern lv_obj_t *ui_Label2;
// SCREEN: ui_HomeScreen
void ui_HomeScreen_screen_init(void);
void ui_event_HomeScreen( lv_event_t * e);
extern lv_obj_t *ui_HomeScreen;
extern lv_obj_t *ui_sun;
void ui_event_Panel2( lv_event_t * e);
extern lv_obj_t *ui_Panel2;
extern lv_obj_t *ui_Bar2;
extern lv_obj_t *ui_Label10;
extern lv_obj_t *ui_Label11;
extern lv_obj_t *ui_Panel3;
extern lv_obj_t *ui_Label5;
extern lv_obj_t *ui_Label1;
extern lv_obj_t *ui_Image5;
extern lv_obj_t *ui_Panel1;
extern lv_obj_t *ui_Label4;
extern lv_obj_t *ui_Label6;
extern lv_obj_t *ui_Image3;
extern lv_obj_t *ui_Panel5;
extern lv_obj_t *ui_Label7;
extern lv_obj_t *ui_Label8;
extern lv_obj_t *ui_Image2;
extern lv_obj_t *ui_Panel4;
extern lv_obj_t *ui_Label9;
extern lv_obj_t *ui_Label13;
extern lv_obj_t *ui_fan;
extern lv_obj_t *ui_Image6;
// SCREEN: ui_LightSettingsScreen
void ui_LightSettingsScreen_screen_init(void);
extern lv_obj_t *ui_LightSettingsScreen;
extern lv_obj_t *ui_Panel8;
extern lv_obj_t *ui_Slider2;
extern lv_obj_t *ui_Label14;
extern lv_obj_t *ui_Label12;
extern lv_obj_t *ui_Panel9;
extern lv_obj_t *ui_Slider1;
extern lv_obj_t *ui_Label16;
extern lv_obj_t *ui_Label17;
// SCREEN: ui_SettingsScreen
void ui_SettingsScreen_screen_init(void);
void ui_event_SettingsScreen( lv_event_t * e);
extern lv_obj_t *ui_SettingsScreen;
extern lv_obj_t *ui_Panel6;
void ui_event_Slider4( lv_event_t * e);
extern lv_obj_t *ui_Slider4;
extern lv_obj_t *ui_LCDBrightness;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_tomato_png);   // assets/tomato.png
LV_IMG_DECLARE( ui_img_sun2_png);   // assets/sun2.png
LV_IMG_DECLARE( ui_img_1484485426);   // assets/thermometer-2.png
LV_IMG_DECLARE( ui_img_humidity_png);   // assets/humidity.png
LV_IMG_DECLARE( ui_img_dew_png);   // assets/dew.png
LV_IMG_DECLARE( ui_img_1142205948);   // assets/fan-3.png
LV_IMG_DECLARE( ui_img_wifi_png);   // assets/wifi.png
LV_IMG_DECLARE( ui_img_303216376);   // assets/sliders-2.png
LV_IMG_DECLARE( ui_img_bg2_png);   // assets/bg2.png
LV_IMG_DECLARE( ui_img_1669444289);   // assets/corners-bgs1.png
LV_IMG_DECLARE( ui_img_182264864);   // assets/corners-details2.png
LV_IMG_DECLARE( ui_img_60476769);   // assets/fan-2.png

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
