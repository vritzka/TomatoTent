#ifndef WIFICLEARCONFIRMSCREEN_H
#define WIFICLEARCONFIRMSCREEN_H

#include "../screen.h"

class WifiClearConfirmScreen : public Screen {
public:
    String getName() { return "wifiClearConfirmScreen"; }
    void render();
    void renderButton(Button& btn);
    void renderButtonPressed(Button& btn);
    void handleButton(Button& btn);
};
#endif
