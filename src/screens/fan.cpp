#include "fan.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"

extern ScreenManager screenManager;
extern Tent tent;

void FanScreen::render()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.drawBitmap(25, 6, fan_24, 24, 24, ILI9341_WHITE);

    tft.setCursor(60, 12);
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(2);
    tft.print("Fan Speed");

    buttons.push_back(Button("fanAutoBtn", 20, 65, 150, 38, "Automatic", 20, 11));
    buttons.push_back(Button("fanManualBtn", 20, 115, 150, 38, "Manual", 40, 11));
    buttons.push_back(Button("fanOkBtn", 20, 170, 150, 38, "Ok", 55, 8));

    drawFanSpeedSettings();

    renderButtons(true);
    drawFanStatus();
}

void FanScreen::update()
{
    if (screenManager.wasNeedsRedraw(FAN))
        drawFanStatus();

    if (screenManager.wasNeedsRedraw(FAN_SPEED_SETTINGS))
        drawFanSpeedSettings();

    Screen::update();
}

void FanScreen::renderButton(Button& btn)
{
    if (btn.getName() == "fanAutoBtn") {
        drawButton(btn, tent.state.getFanAutoMode() ? ILI9341_OLIVE : ILI9341_BLACK, 2);

    } else if (btn.getName() == "fanManualBtn") {
        drawButton(btn, !tent.state.getFanAutoMode() ? ILI9341_OLIVE : ILI9341_BLACK, 2);

    } else if (btn.getName() == "fanUpBtn") {
        if (tent.state.getFanAutoMode())
            return;
        drawButtonTriangleUp(btn, ILI9341_RED);

    } else if (btn.getName() == "fanDownBtn") {
        if (tent.state.getFanAutoMode())
            return;
        drawButtonTriangleDown(btn, ILI9341_RED);

    } else if (btn.getName() == "fanOkBtn") {
        drawButton(btn, ILI9341_OLIVE, 3);

    } else if (btn.getName() == "fanMinUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_RED);

    } else if (btn.getName() == "fanMinDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_RED);

    } else if (btn.getName() == "fanMaxUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_RED);

    } else if (btn.getName() == "fanMaxDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_RED);
    }
}

void FanScreen::renderButtonPressed(Button& btn)
{
    if (btn.getName() == "fanUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_WHITE);

    } else if (btn.getName() == "fanDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_WHITE);

    } else if (btn.getName() == "fanMinUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_WHITE);

    } else if (btn.getName() == "fanMinDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_WHITE);

    } else if (btn.getName() == "fanMaxUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_WHITE);

    } else if (btn.getName() == "fanMaxDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_WHITE);
    }
}

void FanScreen::handleButton(Button& btn)
{
    if (btn.getName() == "fanAutoBtn") {

        if (tent.state.getFanAutoMode())
            return;

        tent.state.setFanAutoMode(true);
        buttons.pop_back();
        buttons.pop_back();
        screenManager.markNeedsRedraw(FAN_SPEED_SETTINGS);
        tent.adjustFan();
        screenManager.markNeedsRedraw(FAN);

    } else if (btn.getName() == "fanManualBtn") {
        if (!tent.state.getFanAutoMode())
            return;

        tent.state.setFanAutoMode(false);
        buttons.pop_back();
        buttons.pop_back();
        buttons.pop_back();
        buttons.pop_back();
        screenManager.markNeedsRedraw(FAN_SPEED_SETTINGS);
        tent.adjustFan();
        screenManager.markNeedsRedraw(FAN);

    } else if (btn.getName() == "fanUpBtn") {
        float fanSpeedPercent = tent.state.getFanSpeed();
        tent.state.setFanAutoMode(false);
        renderButton(buttons[0]);
        renderButton(buttons[1]);

        if (fanSpeedPercent < 100) {
            fanSpeedPercent += 5;
            if(fanSpeedPercent > 100)
                fanSpeedPercent = 100;
            tent.state.setFanSpeed(fanSpeedPercent);
            tent.adjustFan();
            screenManager.markNeedsRedraw(FAN);
        }
    } else if (btn.getName() == "fanDownBtn") {
        float fanSpeedPercent = tent.state.getFanSpeed();
        tent.state.setFanAutoMode(false);
        renderButton(buttons[0]);
        renderButton(buttons[1]);

        if (fanSpeedPercent > 5) {
            fanSpeedPercent -= 5;
            if(fanSpeedPercent < 5)
                fanSpeedPercent == 5;
            tent.state.setFanSpeed(fanSpeedPercent);
            tent.adjustFan();
            screenManager.markNeedsRedraw(FAN);
        }
    } else if (btn.getName() == "fanMinUpBtn") {
        float fanSpeedMin = tent.state.getFanSpeedMin();
        float fanSpeedMax = tent.state.getFanSpeedMax();
        fanSpeedMin += 5;

        bool warning = (fanSpeedMin < fanSpeedMax) ? false : true;

        if (!warning)
            tent.state.setFanSpeedMin(fanSpeedMin);

        drawFanSpeedMin(warning);
        drawFanSpeedMax(warning);
        tent.adjustFan();

    } else if (btn.getName() == "fanMinDownBtn") {
        float fanSpeedMin = tent.state.getFanSpeedMin();
        fanSpeedMin -= 5;

        bool warning = (fanSpeedMin < 5) ? true : false;

        if (!warning)
            tent.state.setFanSpeedMin(fanSpeedMin);

        drawFanSpeedMin(warning);
        tent.adjustFan();

    } else if (btn.getName() == "fanMaxUpBtn") {
        float fanSpeedMax = tent.state.getFanSpeedMax();
        fanSpeedMax += 5;

        bool warning = (fanSpeedMax > 103) ? true : false;

        if (!warning)
            tent.state.setFanSpeedMax(fanSpeedMax);

        drawFanSpeedMax(warning);
        tent.adjustFan();

    } else if (btn.getName() == "fanMaxDownBtn") {
        float fanSpeedMin = tent.state.getFanSpeedMin();
        float fanSpeedMax = tent.state.getFanSpeedMax();
        fanSpeedMax -= 5;

        bool warning = (fanSpeedMax > fanSpeedMin) ? false : true;

        if (!warning)
            tent.state.setFanSpeedMax(fanSpeedMax);

        drawFanSpeedMax(warning);
        drawFanSpeedMin(warning);
        tent.adjustFan();

    } else if (btn.getName() == "fanOkBtn") {
        screenManager.homeScreen();
    }
}

void FanScreen::drawFanSpeedSettings(void)
{
    if (tent.state.getFanAutoMode()) {
        tft.fillRect(225, 75, 51, 122, ILI9341_BLACK);
        tft.setTextColor(ILI9341_WHITE);

        tft.setCursor(232, 64);
        tft.setTextSize(2);
        tft.println("HIGH");
        drawFanSpeedMax();

        tft.setCursor(240, 139);
        tft.setTextSize(2);
        tft.print("LOW");
        drawFanSpeedMin();

        buttons.push_back(Button("fanMaxUpBtn", 280, 85, 30, 30, "", 0, 0));
        buttons.push_back(Button("fanMaxDownBtn", 200, 85, 30, 30, "", 0, 0));
        buttons.push_back(Button("fanMinUpBtn", 280, 160, 30, 30, "", 0, 0));
        buttons.push_back(Button("fanMinDownBtn", 200, 160, 30, 30, "", 0, 0));
        renderButton(buttons[0]);
        renderButton(buttons[1]);
        renderButton(buttons[3]);
        renderButton(buttons[4]);
        renderButton(buttons[5]);
        renderButton(buttons[6]);
    } else {
        tft.fillRect(195, 60, 120, 142, ILI9341_BLACK);
        buttons.push_back(Button("fanUpBtn", 225, 75, 50, 50, "", 0, 0));
        buttons.push_back(Button("fanDownBtn", 225, 145, 50, 50, "", 0, 0));
        renderButton(buttons[0]);
        renderButton(buttons[1]);
        renderButton(buttons[3]);
        renderButton(buttons[4]);
    }
}

void FanScreen::drawFanSpeedMax(bool warning)
{
    tft.fillRect(233, 92, 47, 15, ILI9341_BLACK);
    float fanSpeedMax = tent.state.getFanSpeedMax();

    if (warning) {
        tft.setTextColor(ILI9341_RED);
        if (fanSpeedMax < 100) {
            tft.setCursor(239, 92);
        } else {
            tft.setCursor(233, 92);
        }
        tft.setTextSize(2);
        tft.print(String::format("%.0f", fanSpeedMax) + "%");

        unsigned long waitUntil = millis() + 100;
        while (waitUntil > millis()) {
        }
    }

    tft.setTextColor(ILI9341_WHITE);
    if (fanSpeedMax < 100) {
        tft.setCursor(239, 92);
    } else {
        tft.setCursor(233, 92);
    }
    tft.setTextSize(2);
    tft.print(String::format("%.0f", fanSpeedMax) + "%");
}

void FanScreen::drawFanSpeedMin(bool warning)
{
    tft.fillRect(239, 167, 40, 15, ILI9341_BLACK);
    float fanSpeedMin = tent.state.getFanSpeedMin();

    if (warning) {
        tft.setTextColor(ILI9341_RED);
        if (fanSpeedMin == 5) {
            tft.setCursor(245, 167);
        } else {
            tft.setCursor(239, 167);
        }
        tft.setTextSize(2);
        tft.print(String::format("%.0f", fanSpeedMin) + "%");

        unsigned long waitUntil = millis() + 100;
        while (waitUntil > millis()) {
        }
    }

    tft.setTextColor(ILI9341_WHITE);
    if (fanSpeedMin == 5) {
        tft.setCursor(245, 167);
    } else {
        tft.setCursor(239, 167);
    }
    tft.setTextSize(2);
    tft.print(String::format("%.0f", fanSpeedMin) + "%");
}
