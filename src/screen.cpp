#include <Particle.h>
#include <Arduino.h>
#include "screen.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"

extern ScreenManager screenManager;
extern Tent tent;

Screen::Screen()
    : tft { screenManager.tft }
{
}

void Screen::renderButtons(bool forced)
{
    for (auto it = buttons.begin(); it != buttons.end(); ++it) {
        Button& btn = *it;
        if (forced) {
            this->renderButton(btn);
        } else if (btn.getStatus() == "pressed") {
            btn.setStatus("none");
            this->renderButton(btn);
        }
    }
}

void Screen::processTouch(int x, int y)
{
    for (auto it = buttons.begin(); it != buttons.end(); ++it) {
        Button& btn = *it;
        if (!btn.isPressed(x, y)) {
            continue;
        }
        if (btn.getStatus() != "none") {
            continue;
        }

        btn.setStatus("pressed");
        this->renderButtonPressed(btn);
        this->handleButton(btn);
        break;
    }
}

void Screen::drawButton(Button& btn, int color, int textSize)
{
    uint16_t x0 = btn.x0, y0 = btn.y0, w = btn.w, h = btn.h, textOffsetLeft = btn.textOffsetLeft, textOffsetTop = btn.textOffsetTop;
    String buttonText = btn.buttonText;

    tft.drawRect(x0, y0, w, h, ILI9341_WHITE);
    tft.fillRect(x0 + 1, y0 + 1, w - 2, h - 2, color);

    tft.setCursor(x0 + textOffsetLeft, y0 + textOffsetTop);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(textSize);
    tft.print(buttonText);
}

void Screen::drawButtonTriangleUp(Button& btn, int color)
{
    tft.fillTriangle(btn.x0, btn.y1, btn.x0 + btn.w / 2, btn.y0, btn.x1, btn.y1, color);
    tft.drawTriangle(btn.x0, btn.y1, btn.x0 + btn.w / 2, btn.y0, btn.x1, btn.y1, ILI9341_LIGHTGREY);
}

void Screen::drawButtonTriangleDown(Button& btn, int color)
{
    tft.fillTriangle(btn.x0, btn.y0, btn.x0 + btn.w / 2, btn.y1, btn.x1, btn.y0, color);
    tft.drawTriangle(btn.x0, btn.y0, btn.x0 + btn.w / 2, btn.y1, btn.x1, btn.y0, ILI9341_LIGHTGREY);
}

void Screen::drawButtonTriangleRight(Button& btn, int color)
{
    tft.fillTriangle(btn.x0, btn.y1, btn.x0, btn.y0, btn.x1, btn.y0 + btn.h / 2, color);
    tft.drawTriangle(btn.x0, btn.y1, btn.x0, btn.y0, btn.x1, btn.y0 + btn.h / 2, ILI9341_LIGHTGREY);
}

void Screen::drawButtonTriangleLeft(Button& btn, int color)
{
    tft.fillTriangle(btn.x0, btn.y0 + btn.h / 2, btn.x1, btn.y0, btn.x1, btn.y1, color);
    tft.drawTriangle(btn.x0, btn.y0 + btn.h / 2, btn.x1, btn.y0, btn.x1, btn.y1, ILI9341_LIGHTGREY);
}


void Screen::drawFanStatus()
{
    tft.fillRect(200, 10, 56, 35, ILI9341_BLACK);

    tft.setCursor(210, 10);
    tft.setTextSize(2);
    tft.setTextColor(ILI9341_LIGHTGREY);

    tft.print(String(String::format("%.0f", tent.state.getFanSpeed())));

    tft.print("%");

    tft.setTextSize(1);
    tft.setTextColor(ILI9341_DARKGREY);
    if (tent.state.getFanAutoMode()) {
        tft.setCursor(200, 30);
        tft.print("automatic");
    } else {
        tft.setCursor(210, 30);
        tft.print("manual");
    }
}

void Screen::drawTimerStatus(bool ignoreDayCounter)
{
    int hoursLeft;
    int minutesLeft;
    int maxBrightness = tent.state.getLedBrightnessMax();

    if (tent.state.isDay()) {
        tft.setTextColor(ILI9341_YELLOW);
        hoursLeft = ((tent.state.getDayDuration() - tent.state.getMinutesInPhotoperiod()) / 60);
        minutesLeft = (tent.state.getDayDuration() - tent.state.getMinutesInPhotoperiod()) % 60;
    } else {
        tft.setTextColor(ILI9341_BLUE);
        hoursLeft = ((((24 * 60) - tent.state.getDayDuration()) - tent.state.getMinutesInPhotoperiod()) / 60);
        minutesLeft = (((24 * 60) - tent.state.getDayDuration()) - tent.state.getMinutesInPhotoperiod()) % 60;
    }

    if (hoursLeft < 0 || minutesLeft < 0) {

        tent.countMinute(ignoreDayCounter);

    } else {

        tft.fillRect(5, 5, 137, 37, ILI9341_BLACK);
        if(tent.state.getDayDuration() != 1440 && tent.state.getDayDuration() != 0) {
            tft.setCursor(50, 10);
            tft.setTextSize(2);
            tft.print(String(hoursLeft));
            tft.setTextSize(1);
            tft.print("hrs ");
            tft.setTextSize(2);
            tft.print("" + String(minutesLeft));
            tft.setTextSize(1);
            tft.print("min");
        }

        tft.setCursor(53, 31);
        tft.setTextSize(1);
        if (tent.state.isDay()) {
            tft.drawBitmap(7, 5, sun_36, 36, 36, ILI9341_YELLOW);

            if(tent.state.getDayDuration() == 1440) {
                tft.print("always on");
            } else {
                tft.print("until sunset"); 
            }
            
            if(maxBrightness < 100) {
                tft.setCursor(18,20);
                tft.setTextColor(ILI9341_DARKGREY);
                uint16_t c = maxBrightness/10;
                if(c < 1)
                    c = 1;
                uint16_t r = 11;
                while(r >= c) {
                    tft.drawCircle(25,22,r,ILI9341_BLACK);
                    r -= 1;
                }
            }
            
        } else {
            tft.drawBitmap(7, 5, moon_and_stars_36, 36, 36, ILI9341_BLUE);
            if(tent.state.getDayDuration() == 0) {
                tft.print("always off");
            } else {
                tft.print("until sunrise");
            }
        }
    }
}


void Screen::update()
{
    if (screenManager.wasNeedsRedraw(DIMMED)) {
        if (tent.getGrowLightStatus() == "LOW" || tent.getGrowLightStatus() == "MUTE") {
            drawDimmedIndicator();
        } else {
            hideDimmedIndicator();
        }
    }
}

void Screen::drawDimmedIndicator()
{
    tft.fillRoundRect(0, 220, 320, 25, 5, ILI9341_RED);

    tft.setCursor(120, 222);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    if (tent.getGrowLightStatus() == "LOW") {
        tft.print("Dimmed (" + String(tent.dimTimeout) + "m)");
    } else {
        tft.print("Lights Off");
    }

    tft.drawBitmap(97, 222, iconBulb_16x16, 16, 16, ILI9341_WHITE);
}

void Screen::hideDimmedIndicator()
{
    tft.fillRoundRect(0, 220, 320, 25, 5, ILI9341_BLACK);
}
