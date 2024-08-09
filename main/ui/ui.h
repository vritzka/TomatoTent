// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
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
void ShowDimmerIndication_Animation( lv_obj_t *TargetObject, int delay);
void HideDimmerIndication_Animation( lv_obj_t *TargetObject, int delay);
void ShowDimmerIndication2_Animation( lv_obj_t *TargetObject, int delay);
void HideDimmerIndication2_Animation( lv_obj_t *TargetObject, int delay);
void scanning_Animation( lv_obj_t *TargetObject, int delay);
// SCREEN: ui_SplashScreen
void ui_SplashScreen_screen_init(void);
void ui_event_SplashScreen( lv_event_t * e);
extern lv_obj_t *ui_SplashScreen;
void ui_event_StartNewGrowButton( lv_event_t * e);
extern lv_obj_t *ui_StartNewGrowButton;
extern lv_obj_t *ui_Label3;
extern lv_obj_t *ui_Image7;
void ui_event_DryAHarvestButton( lv_event_t * e);
extern lv_obj_t *ui_DryAHarvestButton;
extern lv_obj_t *ui_Label2;
extern lv_obj_t *ui_Image10;
extern lv_obj_t *ui_tomato;
extern lv_obj_t *ui_tomatotentText;
// SCREEN: ui_HomeScreen
void ui_HomeScreen_screen_init(void);
void ui_event_HomeScreen( lv_event_t * e);
extern lv_obj_t *ui_HomeScreen;
extern lv_obj_t *ui_HomeSky;
void ui_event_TemperaturePanel( lv_event_t * e);
extern lv_obj_t *ui_TemperaturePanel;
extern lv_obj_t *ui_TemperatureLabel;
extern lv_obj_t *ui_HomeTempUnitLabel;
extern lv_obj_t *ui_Image5;
void ui_event_HumidityPanel( lv_event_t * e);
extern lv_obj_t *ui_HumidityPanel;
extern lv_obj_t *ui_HumidityLabel;
extern lv_obj_t *ui_Label6;
extern lv_obj_t *ui_Image3;
void ui_event_KpaPanel( lv_event_t * e);
extern lv_obj_t *ui_KpaPanel;
extern lv_obj_t *ui_Image2;
extern lv_obj_t *ui_VPDLabel;
void ui_event_FanSpeedPanel( lv_event_t * e);
extern lv_obj_t *ui_FanSpeedPanel;
extern lv_obj_t *ui_FanSpeedLabel;
extern lv_obj_t *ui_Fan;
void ui_event_WifiIcon( lv_event_t * e);
extern lv_obj_t *ui_WifiIcon;
extern lv_obj_t *ui_DimmerIconPanel;
extern lv_obj_t *ui_Image23;
extern lv_obj_t *ui_DimmerArc;
extern lv_obj_t *ui_Co2Panel;
extern lv_obj_t *ui_Co2Label;
extern lv_obj_t *ui_Label1;
extern lv_obj_t *ui_Co2Image;
void ui_event_DayCounterPanel( lv_event_t * e);
extern lv_obj_t *ui_DayCounterPanel;
extern lv_obj_t *ui_DayCounterMainLabel;
extern lv_obj_t *ui_TimeLeftLabel;
extern lv_obj_t *ui_Image1;
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
extern lv_obj_t *ui_LightDurationLightLabel;
extern lv_obj_t *ui_LightDurationDarkLabel;
extern lv_obj_t *ui_Panel6;
void ui_event_LEDBrightnessSlider( lv_event_t * e);
extern lv_obj_t *ui_LEDBrightnessSlider;
extern lv_obj_t *ui_Image4;
extern lv_obj_t *ui_LEDBrightnessLabel;
extern lv_obj_t *ui_Panel10;
extern lv_obj_t *ui_Image15;
void ui_event_Button1( lv_event_t * e);
extern lv_obj_t *ui_Button1;
extern lv_obj_t *ui_Label22;
extern lv_obj_t *ui_Panel4;
void ui_event_DayDownButton( lv_event_t * e);
extern lv_obj_t *ui_DayDownButton;
void ui_event_DayUpButton( lv_event_t * e);
extern lv_obj_t *ui_DayUpButton;
extern lv_obj_t *ui_DayCounterLabel;
extern lv_obj_t *ui_CalendarImage;
// SCREEN: ui_GraphScreen
void ui_GraphScreen_screen_init(void);
void ui_event_GraphScreen( lv_event_t * e);
extern lv_obj_t *ui_GraphScreen;
extern lv_obj_t *ui_bud;
extern lv_obj_t *ui_Chart;
void ui_event_TempSeriesPanel( lv_event_t * e);
extern lv_obj_t *ui_TempSeriesPanel;
extern lv_obj_t *ui_Image6;
extern lv_obj_t *ui_TemperatureLabel2;
extern lv_obj_t *ui_TempUnitLabel2;
void ui_event_HumiditySeriesPanel( lv_event_t * e);
extern lv_obj_t *ui_HumiditySeriesPanel;
extern lv_obj_t *ui_Image19;
extern lv_obj_t *ui_HumidityLabel2;
extern lv_obj_t *ui_Label7;
void ui_event_CO2SeriesPanel( lv_event_t * e);
extern lv_obj_t *ui_CO2SeriesPanel;
extern lv_obj_t *ui_Image11;
extern lv_obj_t *ui_Co2Label2;
extern lv_obj_t *ui_Label8;
void ui_event_FanspeedSeriesPanel( lv_event_t * e);
extern lv_obj_t *ui_FanspeedSeriesPanel;
extern lv_obj_t *ui_Fan2;
extern lv_obj_t *ui_FanSpeedLabel2;
extern lv_obj_t *ui_Label9;
extern lv_obj_t *ui_VPDSeriesPanel;
extern lv_obj_t *ui_Image16;
extern lv_obj_t *ui_VPDLabel2;
extern lv_obj_t *ui_Label5;
extern lv_obj_t *ui_DimmerIconPanel2;
extern lv_obj_t *ui_Image18;
extern lv_obj_t *ui_DimmerBar2;
// SCREEN: ui_ClimateControlScreen
void ui_ClimateControlScreen_screen_init(void);
void ui_event_ClimateControlScreen( lv_event_t * e);
extern lv_obj_t *ui_ClimateControlScreen;
extern lv_obj_t *ui_Image14;
extern lv_obj_t *ui_ClimateSettingsScreen;
extern lv_obj_t *ui_ClimateValuesPanel;
void ui_event_HumidityDropdown( lv_event_t * e);
extern lv_obj_t *ui_HumidityDropdown;
extern lv_obj_t *ui_Label18;
void ui_event_TemperatureDropdown( lv_event_t * e);
extern lv_obj_t *ui_TemperatureDropdown;
extern lv_obj_t *ui_Label17;
extern lv_obj_t *ui_Panel2;
void ui_event_ClimateModeSwitch( lv_event_t * e);
extern lv_obj_t *ui_ClimateModeSwitch;
extern lv_obj_t *ui_Label19;
extern lv_obj_t *ui_Label20;
extern lv_obj_t *ui_Panel13;
void ui_event_fanSpeedSlider( lv_event_t * e);
extern lv_obj_t *ui_fanSpeedSlider;
extern lv_obj_t *ui_Fan3;
extern lv_obj_t *ui_FanSpeedMinLabel;
extern lv_obj_t *ui_FanSpeedMaxLabel;
extern lv_obj_t *ui_FanSpeedLabel3;
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
extern lv_obj_t *ui_QrCode1;
void ui_event_scanning( lv_event_t * e);
extern lv_obj_t *ui_scanning;
// SCREEN: ui_GeneralSettingsScreen
void ui_GeneralSettingsScreen_screen_init(void);
void ui_event_GeneralSettingsScreen( lv_event_t * e);
extern lv_obj_t *ui_GeneralSettingsScreen;
extern lv_obj_t *ui_Image20;
extern lv_obj_t *ui_Label23;
extern lv_obj_t *ui_Panel12;
extern lv_obj_t *ui_Label24;
void ui_event_ScreenBrightnessSlider( lv_event_t * e);
extern lv_obj_t *ui_ScreenBrightnessSlider;
extern lv_obj_t *ui_ScreenBrightnessLabel;
extern lv_obj_t *ui_SoftwareUpdatePanel;
extern lv_obj_t *ui_CurrentVersionLabel;
extern lv_obj_t *ui_SoftwareVersionsPanel;
extern lv_obj_t *ui_UpgradeStatusBar;
extern lv_obj_t *ui_Label10;
void ui_event_FirmwareUpgradeButton( lv_event_t * e);
extern lv_obj_t *ui_FirmwareUpgradeButton;
extern lv_obj_t *ui_Label21;
extern lv_obj_t *ui_Panel1;
extern lv_obj_t *ui_DimmerPolarityContainer;
void ui_event_PolaritySwitch1( lv_event_t * e);
extern lv_obj_t *ui_PolaritySwitch1;
void ui_event_PolaritySwitch2( lv_event_t * e);
extern lv_obj_t *ui_PolaritySwitch2;
void ui_event_PolaritySwitch3( lv_event_t * e);
extern lv_obj_t *ui_PolaritySwitch3;
void ui_event_PolaritySwitch4( lv_event_t * e);
extern lv_obj_t *ui_PolaritySwitch4;
void ui_event_PolaritySwitch5( lv_event_t * e);
extern lv_obj_t *ui_PolaritySwitch5;
void ui_event_PolaritySwitch6( lv_event_t * e);
extern lv_obj_t *ui_PolaritySwitch6;
extern lv_obj_t *ui_Image17;
extern lv_obj_t *ui_Container2;
extern lv_obj_t *ui_Roller1;
extern lv_obj_t *ui_Label12;
extern lv_obj_t *ui_Panel17;
void ui_event_TempUnitSwitch( lv_event_t * e);
extern lv_obj_t *ui_TempUnitSwitch;
extern lv_obj_t *ui_Label27;
extern lv_obj_t *ui_Label16;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_plant_png);   // assets/plant.png
LV_IMG_DECLARE( ui_img_dry_png);   // assets/dry.png
LV_IMG_DECLARE( ui_img_tomato_png);   // assets/tomato.png
LV_IMG_DECLARE( ui_img_tomatotent_text_png);   // assets/tomatotent_text.png
LV_IMG_DECLARE( ui_img_791711567);   // assets/sun-3.png
LV_IMG_DECLARE( ui_img_1484485426);   // assets/thermometer-2.png
LV_IMG_DECLARE( ui_img_humidity_png);   // assets/humidity.png
LV_IMG_DECLARE( ui_img_1774250380);   // assets/dew-4.png
LV_IMG_DECLARE( ui_img_60476769);   // assets/fan-2.png
LV_IMG_DECLARE( ui_img_wifi_png);   // assets/wifi.png
LV_IMG_DECLARE( ui_img_640654572);   // assets/sunglasses-2.png
LV_IMG_DECLARE( ui_img_co2_png);   // assets/co2.png
LV_IMG_DECLARE( ui_img_appointment_png);   // assets/appointment.png
LV_IMG_DECLARE( ui_img_303216376);   // assets/sliders-2.png
LV_IMG_DECLARE( ui_img_now_arrow_2_png);   // assets/now_arrow_2.png
LV_IMG_DECLARE( ui_img_432815713);   // assets/night-mode.png
LV_IMG_DECLARE( ui_img_1756057095);   // assets/led-light-3.png
LV_IMG_DECLARE( ui_img_harvest_png);   // assets/harvest.png
LV_IMG_DECLARE( ui_img_1749885216);   // assets/chevron-downwards-arrow.png
LV_IMG_DECLARE( ui_img_2060199463);   // assets/chevron-upwards-arrow.png
LV_IMG_DECLARE( ui_img_bud_png);   // assets/bud.png
LV_IMG_DECLARE( ui_img_17176521);   // assets/dew-3.png
LV_IMG_DECLARE( ui_img_261459337);   // assets/climate-change.png
LV_IMG_DECLARE( ui_img_1142205948);   // assets/fan-3.png
LV_IMG_DECLARE( ui_img_953604683);   // assets/wifi-2.png
LV_IMG_DECLARE( ui_img_1668913270);   // assets/back-up.png
LV_IMG_DECLARE( ui_img_refresh_png);   // assets/refresh.png
LV_IMG_DECLARE( ui_img_1668210446);   // assets/rj45-3.png
LV_IMG_DECLARE( ui_img_713338696);   // assets/cloud-computing-2.png
LV_IMG_DECLARE( ui_img_1324581693);   // assets/dimmer-3.png
LV_IMG_DECLARE( ui_img_320680866);   // assets/led-light-2.png
LV_IMG_DECLARE( ui_img_1180469587);   // assets/moon-2.png
LV_IMG_DECLARE( ui_img_290017612);   // assets/sun-2.png
LV_IMG_DECLARE( ui_img_1130838376);   // assets/thermometer-4.png
LV_IMG_DECLARE( ui_img_1319116584);   // assets/wall-socket-2.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
