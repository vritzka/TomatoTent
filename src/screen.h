#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include "button.h"
#include "Adafruit_ILI9341.h"

class Screen {
protected:
    Adafruit_ILI9341& tft;
    std::vector<Button> buttons;
    void drawButton(Button& btn, int color, int textSize);
    void drawButtonTriangleUp(Button& btn, int color);
    void drawButtonTriangleDown(Button& btn, int color);
    void drawButtonTriangleRight(Button& btn, int color);
    void drawButtonTriangleLeft(Button& btn, int color);
    void drawFanStatus();
    void drawTimerStatus(bool ignoreDayCounter = false);
    void drawDayCounter();
    void drawDimmedIndicator();
    void hideDimmedIndicator();

public:
    Screen();
    void renderButtons(bool forced = false);
    void processTouch(int x, int y);

    //virtual:
    virtual String getName() = 0;
    virtual void render() = 0;
    virtual void update();
    virtual void renderButton(Button& btn) = 0;
    virtual void renderButtonPressed(Button& btn) = 0;
    virtual void handleButton(Button& btn) = 0;
    virtual ~Screen() = default;
};

#endif