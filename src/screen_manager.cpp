#include "screen_manager.h"
#include "tent.h"
#include "screens/cancel.h"
#include "screens/cancel_confirm.h"
#include "screens/timer.h"
#include "screens/fan.h"
#include "screens/tent_size.h"
#include "screens/temp_unit.h"
#include "screens/grow_started.h"
#include "screens/wifi_splash.h"
#include "screens/wifi.h"

extern Tent tent;

void ScreenManager::setup()
{
    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(ILI9341_BLACK);

    ts.begin();
    ts.setRotation(3); // 1 for 2.4 screen, 3 for 2.8
}

void ScreenManager::tick()
{
    if (ts.touched()) {
        tent.displayLightHigh(); // Switch on Displaylight on touch

        if (!current) {
            return;
        }

        TS_Point p = ts.getPosition();
        p.x += 20; // calibration
        current->processTouch(p.x, p.y);
        delay(10);

    } else {
        renderButtons();
    }
}

void ScreenManager::render()
{
    if (current) {
        markNeedsRedraw(DIMMED);
        current->render();
        current->update();
    }
}

void ScreenManager::homeScreen()
{
    current.reset(new HomeScreen());
    render();
}

void ScreenManager::growStartedScreen()
{
    current.reset(new GrowStartedScreen());
    render();
}

void ScreenManager::cancelScreen()
{
    current.reset(new CancelScreen());
    render();
}

void ScreenManager::cancelConfirmationScreen()
{
    current.reset(new CancelConfirmScreen());
    render();
}

void ScreenManager::timerScreen()
{
    current.reset(new TimerScreen());
    render();
}

void ScreenManager::wifiScreen()
{
    current.reset(new WifiScreen());
    render();
}

void ScreenManager::wifiSplashScreen()
{
    current.reset(new WifiSplashScreen());
    render();
}

void ScreenManager::fanScreen()
{
    current.reset(new FanScreen());
    render();
}

void ScreenManager::tentSizeScreen()
{
    current.reset(new TentSizeScreen());
    render();
}

void ScreenManager::tempUnitScreen()
{
    current.reset(new TempUnitScreen());
    render();
}

void ScreenManager::renderButtons(bool forced)
{
    if (current) {
        current->renderButtons(forced);
    }
}

void ScreenManager::markNeedsRedraw(redrawMarker m)
{
    redrawMarkers |= (int)m;
}

bool ScreenManager::wasNeedsRedraw(redrawMarker m)
{
    bool ret = redrawMarkers & m;
    redrawMarkers &= ~m;
    return ret;
}
