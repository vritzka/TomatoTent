#ifndef FANSCREEN_H
#define FANSCREEN_H

#include "../screen.h"

class FanScreen : public Screen {
public:
    String getName() { return "fanScreen"; }
    void render();
    void update();
    void renderButton(Button& btn);
    void renderButtonPressed(Button& btn);
    void handleButton(Button& btn);
    void drawFanSpeedMax(bool warning = 0);
    void drawFanSpeedMin(bool warning = 0);
};
#endif
