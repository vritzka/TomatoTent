#ifndef SCREEN_H
#define SCREEN_H

#include <Particle.h>
#include <Arduino.h>

#include <Adafruit_ILI9341.h>
#include <button.h>
#include "systemStatus.h"
#include "tent.h"

extern Adafruit_ILI9341 tft;
extern Button button;
extern SystemStatus systemStatus;
extern Tent tent;
extern float fanSpeed;
extern float fanSpeedPercent;

class Screen {

public:
    Screen();
    void homeScreen(Button* buttons, String& currentScreen);
    void growStartedScreen(Button* buttons, String& currentScreen);
    void cancelScreen(Button* buttons, String& currentScreen);
    void cancelConfirmationScreen(Button* buttons, String& currentScreen);
    void timerScreen(Button* buttons, String& currentScreen);
    void wifiScreen(Button* buttons, String& currentScreen);
    void wifiSetupScreen(Button* buttons, String& currentScreen);
    void fanScreen(Button* buttons, String& currentScreen);
    void tempUnitScreen(Button* buttons, String& currentScreen);
    void clear(Button* buttons);
};
#endif
