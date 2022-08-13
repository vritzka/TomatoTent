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
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Fan Speed");

    buttons.push_back(Button("fanOkBtn", 225, 180, 80, 38, "Ok", 28, 12));

    buttons.push_back(Button("fanMaxUpBtn", 165, 86, 30, 30, "", 0, 0));
    buttons.push_back(Button("fanMaxDownBtn", 40, 86, 30, 30, "", 0, 0));
    buttons.push_back(Button("fanMinUpBtn", 165, 170, 30, 30, "", 0, 0));
    buttons.push_back(Button("fanMinDownBtn", 40, 170, 30, 30, "", 0, 0));

    tft.fillRect(225, 75, 51, 122, ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);

    tft.setCursor(110, 69);
    tft.setTextSize(1);
    tft.println("MAX");
    drawFanSpeedMax();

    tft.setCursor(110, 153);
    tft.setTextSize(1);
    tft.print("MIN");
    drawFanSpeedMin();

    renderButtons(true);
    drawFanStatus();
}

void FanScreen::update()
{
    if (screenManager.wasNeedsRedraw(FAN))
        drawFanStatus();

    Screen::update();
}

void FanScreen::renderButton(Button& btn)
{

    if (btn.getName() == "fanOkBtn") {
        drawButton(btn, ILI9341_OLIVE, 2);

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
    if (btn.getName() == "fanMinUpBtn") {
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
    if (btn.getName() == "fanMinUpBtn") {
        float fanSpeedMin = tent.state.getFanSpeedMin();
        float fanSpeedMax = tent.state.getFanSpeedMax();

        bool warning = (fanSpeedMin == fanSpeedMax) ? true : false;

        if (!warning) {
            if((fanSpeedMax - fanSpeedMin) >= 5) {
                fanSpeedMin += 5;
            } else if((fanSpeedMax - fanSpeedMin) < 5) {
                fanSpeedMin = fanSpeedMax;
            }

            tent.state.setFanSpeedMin(fanSpeedMin);
        }

        drawFanSpeedMin(warning);
        drawFanSpeedMax(warning);
        tent.adjustFan();

    } else if (btn.getName() == "fanMinDownBtn") {
        float fanSpeedMin = tent.state.getFanSpeedMin();

        bool warning = (fanSpeedMin == 5) ? true : false;

        if (!warning) {
            if(fanSpeedMin >= 10) {
                fanSpeedMin -= 5;
            } else if(fanSpeedMin < 5) {
                fanSpeedMin = 5;
            }

            tent.state.setFanSpeedMin(fanSpeedMin);
        }
        drawFanSpeedMin(warning);
        tent.adjustFan();

    } else if (btn.getName() == "fanMaxUpBtn") {

        float fanSpeedMax = tent.state.getFanSpeedMax();

        bool warning = (fanSpeedMax == 100) ? true : false;

        if (!warning) {
            if(fanSpeedMax <= 95) {
                fanSpeedMax += 5;
            } else if(fanSpeedMax > 95) {
                fanSpeedMax = 100;
            }

            tent.state.setFanSpeedMax(fanSpeedMax);
        }

        drawFanSpeedMax(warning);
        tent.adjustFan();

    } else if (btn.getName() == "fanMaxDownBtn") {
        float fanSpeedMin = tent.state.getFanSpeedMin();
        float fanSpeedMax = tent.state.getFanSpeedMax();

        bool warning = (fanSpeedMin == fanSpeedMax) ? true : false;

        if (!warning) {
            if((fanSpeedMax - fanSpeedMin) >= 5) {
                fanSpeedMax -= 5;
            } else if((fanSpeedMax - fanSpeedMin) < 5) {
                fanSpeedMax = fanSpeedMin;
            }

            tent.state.setFanSpeedMax(fanSpeedMax);
        }

        drawFanSpeedMin(warning);
        drawFanSpeedMax(warning);
        tent.adjustFan();

    } else if (btn.getName() == "fanOkBtn") {
        screenManager.homeScreen();
    }
}

void FanScreen::drawFanSpeedMax(bool warning)
{
    tft.fillRect(85, 88, 70, 21, ILI9341_BLACK);
    float fanSpeedMax = tent.state.getFanSpeedMax();

    tft.setTextSize(3);

    if (warning) {
        tft.setTextColor(ILI9341_RED);
        if (fanSpeedMax == 100) {
            tft.setCursor(85, 88);
        } else if(fanSpeedMax < 100 && fanSpeedMax >= 10) {
            tft.setCursor(95, 88);
        } else {
            tft.setCursor(102, 88);
        }

        tft.print(String::format("%.0f", fanSpeedMax) + "%");

        unsigned long waitUntil = millis() + 100;
        while (waitUntil > millis()) {}
    }

    tft.setTextColor(ILI9341_WHITE);
    if (fanSpeedMax == 100) {
        tft.setCursor(85, 88);
    } else if(fanSpeedMax < 100 && fanSpeedMax >= 10) {
        tft.setCursor(95, 88);
    } else {
        tft.setCursor(102, 88);
    }

    tft.print(String::format("%.0f", fanSpeedMax) + "%");
}

void FanScreen::drawFanSpeedMin(bool warning)
{
    tft.fillRect(85, 172, 70, 21, ILI9341_BLACK);
    float fanSpeedMin = tent.state.getFanSpeedMin();

    tft.setTextSize(3);

    if (warning) {
        tft.setTextColor(ILI9341_RED);

        if (fanSpeedMin == 100) {
            tft.setCursor(85, 172);
        } else if(fanSpeedMin < 100 && fanSpeedMin >= 10) {
            tft.setCursor(95, 172);
        } else {
            tft.setCursor(102, 172);
        }        
        tft.print(String::format("%.0f", fanSpeedMin) + "%");

        unsigned long waitUntil = millis() + 100;
        while (waitUntil > millis()) {}
    }

    tft.setTextColor(ILI9341_WHITE);
    if (fanSpeedMin == 100) {
        tft.setCursor(85, 172);
    } else if(fanSpeedMin < 100 && fanSpeedMin >= 10) {
        tft.setCursor(95, 172);
    } else {
        tft.setCursor(102, 172);
    }  

    tft.print(String::format("%.0f", fanSpeedMin) + "%");
}
