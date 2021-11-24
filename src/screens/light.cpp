#include "light.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"

extern ScreenManager screenManager;
extern Tent tent;

void LightScreen::render()
{
    tft.fillScreen(ILI9341_BLACK);

    uint16_t dayDuration = tent.state.getDayDuration();
    renderDayDuration(dayDuration);

    buttons.push_back(Button("timerUpBtn", 40, 55, 40, 40, "", 0, 0));
    buttons.push_back(Button("timerDownBtn", 40, 165, 40, 40, "", 0, 0));

    buttons.push_back(Button("nowLeftBtn", 120, 60, 30, 30, "", 0, 0));
    buttons.push_back(Button("nowRightBtn", 170, 60, 30, 30, "", 0, 0));

    buttons.push_back(Button("dayLeftBtn", 120, 130, 30, 30, "", 0, 0));
    buttons.push_back(Button("dayRightBtn", 170, 130, 30, 30, "", 0, 0));

    buttons.push_back(Button("brightnessUpBtn", 235, 55, 40, 40, "", 0, 0));
    buttons.push_back(Button("brightnessDownBtn", 235, 165, 40, 40, "", 0, 0));

    buttons.push_back(Button("cancelBtn", 260, 10, 50, 30, "End", 9, 8));

    buttons.push_back(Button("lightOkBtn", 140, 180, 40, 38, "OK", 9, 12));

    tft.setCursor(152, 45);
    tft.setTextColor(ILI9341_LIGHTGREY);
    tft.setTextSize(1);
    tft.print("NOW");

    tft.setCursor(152, 115);
    tft.print("DAY");

    renderLedBrightness();
    drawTimerStatus();
    drawDayCounter();



    renderButtons(true);
}

void LightScreen::update()
{
    if (screenManager.wasNeedsRedraw(TIMER))
        drawTimerStatus();

    Screen::update();
}

void LightScreen::renderButton(Button& btn)
{
    if (btn.getName() == "timerUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_RED);

    } else if (btn.getName() == "timerDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_RED);

    } else if (btn.getName() == "nowRightBtn") {
        drawButtonTriangleRight(btn, ILI9341_RED);

    } else if (btn.getName() == "nowLeftBtn") {
        drawButtonTriangleLeft(btn, ILI9341_RED);

    } else if (btn.getName() == "dayRightBtn") {
        drawButtonTriangleRight(btn, ILI9341_RED);

    } else if (btn.getName() == "dayLeftBtn") {
        drawButtonTriangleLeft(btn, ILI9341_RED);

    } else if (btn.getName() == "brightnessUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_CYAN);

    } else if (btn.getName() == "brightnessDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_CYAN);

    } else if (btn.getName() == "cancelBtn") {
        drawButton(btn, ILI9341_BLACK, 2);

    } else if (btn.getName() == "lightOkBtn") {
        drawButton(btn, ILI9341_OLIVE, 2);
    }
}

void LightScreen::renderButtonPressed(Button& btn)
{
    if (btn.getName() == "timerUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_WHITE);

    } else if (btn.getName() == "timerDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_WHITE);

    } else if (btn.getName() == "nowRightBtn") {
        drawButtonTriangleRight(btn, ILI9341_WHITE);

    } else if (btn.getName() == "nowLeftBtn") {
        drawButtonTriangleLeft(btn, ILI9341_WHITE);

    } else if (btn.getName() == "dayRightBtn") {
        drawButtonTriangleRight(btn, ILI9341_WHITE);

    } else if (btn.getName() == "dayLeftBtn") {
        drawButtonTriangleLeft(btn, ILI9341_WHITE);

    } else if (btn.getName() == "brightnessUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_WHITE);

    } else if (btn.getName() == "brightnessDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_WHITE);
    }
}

void LightScreen::handleButton(Button& btn)
{
    if (btn.getName() == "timerUpBtn") {
        int16_t dayDuration = tent.state.getDayDuration();
        int16_t minutesInPhotoperiod = tent.state.getMinutesInPhotoperiod();
        uint16_t nightDuration = 1440 - dayDuration;
        bool isDay = tent.state.isDay();

        dayDuration += 60;

        if (dayDuration > 1440)
            return;

        if (!isDay) {

            minutesInPhotoperiod -= 60;

            if (minutesInPhotoperiod < 0) {
                tent.state.setIsDay(true);
                tent.growLight("HIGH");
                minutesInPhotoperiod = dayDuration + minutesInPhotoperiod;
            }

            tent.state.setMinutesInPhotoperiod(minutesInPhotoperiod);
        }

        if (dayDuration == 1440) {
            tent.state.setDayDuration(dayDuration);
            tent.state.setMinutesInPhotoperiod(minutesInPhotoperiod);
        } else {
            tent.state.setDayDuration(dayDuration);
        }

        renderDayDuration(dayDuration);
        drawTimerStatus(true);

    } else if (btn.getName() == "timerDownBtn") {
        int16_t dayDuration = tent.state.getDayDuration();
        int16_t minutesInPhotoperiod = tent.state.getMinutesInPhotoperiod();
        uint16_t nightDuration = 1440 - dayDuration;
        bool isDay = tent.state.isDay();

        dayDuration -= 60;

        if (dayDuration < 0) {
            return;
        }

        if (isDay) {

            if (minutesInPhotoperiod > dayDuration) {
                tent.state.setIsDay(false);
                tent.growLight("OFF");
                minutesInPhotoperiod = minutesInPhotoperiod - dayDuration;
            }
            tent.state.setMinutesInPhotoperiod(minutesInPhotoperiod);

        } else {
            tent.state.setMinutesInPhotoperiod(minutesInPhotoperiod + 60);
        }

        if (dayDuration == 0) {
            tent.state.setDayDuration(dayDuration);
        } else {
            tent.state.setDayDuration(dayDuration);
        }

        renderDayDuration(dayDuration);
        drawTimerStatus(true);

    } else if (btn.getName() == "nowRightBtn") {

        uint16_t dayDuration = tent.state.getDayDuration();
        uint16_t nightDuration = 1440 - dayDuration;
        uint16_t minutesInPhotoperiod = tent.state.getMinutesInPhotoperiod();
        uint16_t minutesLeftinPhotoperiod;

        if (dayDuration == 0 || dayDuration == 1440)
            return;

        if (tent.state.isDay()) {
            minutesLeftinPhotoperiod = dayDuration - minutesInPhotoperiod;

            if (minutesLeftinPhotoperiod <= 60) {
                tent.state.setIsDay(false);
                tent.growLight("OFF");
                minutesInPhotoperiod = 60 - minutesLeftinPhotoperiod;
            } else {
                minutesInPhotoperiod += 60;
            }

        } else {
            minutesLeftinPhotoperiod = ((24 * 60) - dayDuration) - minutesInPhotoperiod;

            if (minutesLeftinPhotoperiod <= 60) {
                return;
            } else {
                minutesInPhotoperiod += 60;
            }
        }

        tent.state.setMinutesInPhotoperiod(minutesInPhotoperiod);
        drawTimerStatus(true);

    } else if (btn.getName() == "nowLeftBtn") {

        uint16_t dayDuration = tent.state.getDayDuration();
        uint16_t nightDuration = 1440 - dayDuration;
        uint16_t minutesInPhotoperiod = tent.state.getMinutesInPhotoperiod();
        uint16_t minutesLeftinPhotoperiod;

        if (dayDuration == 0 || dayDuration == 1440)
            return;

        if (tent.state.isDay()) {
            minutesLeftinPhotoperiod = dayDuration - minutesInPhotoperiod;

            if (minutesInPhotoperiod <= 60) {
                minutesInPhotoperiod = 0;
            } else {
                minutesInPhotoperiod -= 60;
            }

        } else {
            minutesLeftinPhotoperiod = nightDuration - minutesInPhotoperiod;

            if (minutesInPhotoperiod <= 60) {
                tent.state.setIsDay(true);
                tent.growLight("HIGH");
                minutesInPhotoperiod = dayDuration - (60 - minutesInPhotoperiod);
            } else {
                minutesInPhotoperiod -= 60;
            }
        }

        tent.state.setMinutesInPhotoperiod(minutesInPhotoperiod);
        drawTimerStatus(true);

    } else if (btn.getName() == "dayRightBtn") {
        if(tent.state.getDayCount() >= 9999)
            return;
        tent.state.setDayCount(tent.state.getDayCount() + 1);
        drawDayCounter();

    } else if (btn.getName() == "dayLeftBtn") {
        if(tent.state.getDayCount() == 0)
            return;
        tent.state.setDayCount(tent.state.getDayCount() - 1);
        drawDayCounter();

    } else if (btn.getName() == "brightnessUpBtn") {
        int brightness = tent.state.getLedBrightnessMax();
        if (brightness == 100)
            return;

        brightness += 10;
        tent.state.setLedBrightnessMax(brightness);
        if (tent.state.isDay())
            tent.growLight("HIGH");

        renderLedBrightness();
        drawTimerStatus();
        screenManager.markNeedsRedraw(DIMMED);

    } else if (btn.getName() == "brightnessDownBtn") {
        int brightness = tent.state.getLedBrightnessMax();
        if (brightness == 10)
            return;

        brightness -= 10;
        tent.state.setLedBrightnessMax(brightness);
        if (tent.state.isDay())
            tent.growLight("HIGH");

        renderLedBrightness();
        drawTimerStatus();
        screenManager.markNeedsRedraw(DIMMED);

    } else if (btn.getName() == "cancelBtn") {
        screenManager.cancelConfirmationScreen();
    
    } else if (btn.getName() == "lightOkBtn") {
        screenManager.homeScreen();
    }
}

void LightScreen::renderDayDuration(int dayDuration)
{
    int dayDurationHours = dayDuration / 60;

    tft.fillRect(41, 120, 39, 23, ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);

    if (dayDurationHours < 10) {
        tft.setCursor(53, 121);

    } else if (dayDurationHours >= 20) {
        tft.setCursor(44, 121);

    } else {
        tft.setCursor(42, 121);
    }

    tft.print(String(dayDurationHours));

    tft.setTextSize(1);
    tft.setTextColor(ILI9341_LIGHTGREY);
    tft.setCursor(37, 104);
    tft.print("DAYLIGHT");
    tft.setCursor(46, 152);
    tft.print("HOURS");
}

void LightScreen::renderLedBrightness()
{
    tft.fillRect(229, 121, 60, 26, ILI9341_BLACK);
    int brightnessPercent = tent.state.getLedBrightnessMax();

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);

    if (brightnessPercent == 100) {
        tft.setCursor(229, 121);

    } else if (brightnessPercent == 5) {
        tft.setCursor(248, 121);

    } else {
        tft.setCursor(238, 121);
    }

    tft.print(String(brightnessPercent));

    tft.setTextColor(ILI9341_LIGHTGREY);
    tft.setTextSize(1);

    tft.setCursor(237, 104);
    tft.print("DIMMER");

    tft.setCursor(250, 147);
    tft.setTextSize(2);
    tft.print("%");
}