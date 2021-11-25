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
    void drawTargetTemperature(bool warning = false);
    void drawTargetHumidity(bool warning = false);
    void drawClimateSettings(void);
};
#endif
