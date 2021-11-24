#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <Particle.h>
#include <Arduino.h>

#include "screen.h"
#include "screens/home.h"

#include "XPT2046_Touch.h"
#include "Adafruit_ILI9341.h"
#include "Adafruit_mfGFX.h"

#define TCS_PIN D5
#define TIRQ_PIN A0
#define TFT_DC A1
#define TFT_CS A2
#define TFT_RST D6

enum redrawMarker {
    TEMPERATURE = 1,
    HUMIDITY = 2,
    SOIL_MOISTURE = 4,
    TIMER = 8,
    FAN = 16,
    DAY = 32,
    DIMMED = 64,
    SOIL_TEMPERATURE = 128,
    FAN_SPEED_SETTINGS = 256,
    VPD = 512
};

class ScreenManager {
private:
    int redrawMarkers;
    void render();

    XPT2046_Touchscreen ts = XPT2046_Touchscreen(SPI1, 320, 240, TCS_PIN, TIRQ_PIN);

public:
    Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
    std::unique_ptr<Screen> current = std::make_unique<HomeScreen>();

    void setup();
    void tick();

    void renderButtons(bool forced = false);
    void markNeedsRedraw(redrawMarker m);
    bool wasNeedsRedraw(redrawMarker m);

    void homeScreen();
    void growStartedScreen();
    void cancelConfirmationScreen();
    void lightScreen();
    void wifiScreen();
    void wifiSplashScreen();
    void wifiClearConfirmScreen();
    void fanScreen();
    void firmwareUpdateScreen();
    void climateScreen();
};
#endif
