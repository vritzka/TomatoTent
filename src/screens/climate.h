#ifndef CLIMATESCREEN_H
#define CLIMATESCREEN_H

#include "../screen.h"

class ClimateScreen : public Screen {
public:
    String getName() { return "climateScreen"; }
    void render();
    void renderButton(Button& btn);
    void renderButtonPressed(Button& btn);
    void handleButton(Button& btn);
};
#endif
