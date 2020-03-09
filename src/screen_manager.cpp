#include "screen_manager.h"
#include "tent.h"
#include "screens/cancel.h"
#include "screens/cancel_confirm.h"
#include "screens/timer.h"
#include "screens/fan.h"
#include "screens/temp_unit.h"
#include "screens/grow_started.h"
#include "screens/wifi_splash.h"
#include "screens/wifi.h"

extern Tent tent;

static void tft_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint16_t c;
    ScreenManager *sm = reinterpret_cast<ScreenManager*>(disp->user_data);
    Adafruit_ILI9341 &tft = sm->tft;

    tft.startWrite(area->x1, area->y1, area->x2, area->y2);
    for (int y = area->y1; y <= area->y2; y++) {
        for (int x = area->x1; x <= area->x2; x++) {
            c = color_p->full;
            tft.writeColor(c);
            color_p++;
        }
    }
    tft.endWrite();
    lv_disp_flush_ready(disp);
}

void ScreenManager::lvTick()
{
    lv_tick_inc(LVGL_TICK_PERIOD);
}

void ScreenManager::setup()
{
    lv_init();

    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(ILI9341_RED);

    lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * 10);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = 320;
    disp_drv.ver_res = 240;
    disp_drv.user_data = reinterpret_cast<void*>(this);
    disp_drv.flush_cb = tft_flush;
    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    lv_obj_t *label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(label, "Hello!");
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_task_handler();
    lvTimer.start();

    ts.begin();
    ts.setRotation(3); // 1 for 2.4 screen, 3 for 2.8
}

void ScreenManager::tick()
{
    lv_task_handler();
    return;

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
    return;
    if (current) {
        markNeedsRedraw(DIMMED);
        current->render();
        current->update();
    }
}

void ScreenManager::homeScreen()
{
    //current.reset(new HomeScreen());
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
