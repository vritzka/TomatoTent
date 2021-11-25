#ifndef FIRMWAREUPDATECONFIRMSCREEN_H
#define FIRMWAREUPDATECONFIRMSCREEN_H

#include "../screen.h"

class FirmwareUpdateConfirmScreen : public Screen {
public:
    String getName() { return "firmwareUpdateConfirmScreen"; }
    void render();
    void renderButton(Button& btn);
    void renderButtonPressed(Button& btn);
    void handleButton(Button& btn);
    void update();
};
#endif
