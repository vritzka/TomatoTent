#ifndef BUTTON_H
#define BUTTON_H

#include <Particle.h>

class Button {

    String name;
    String currentStatus;

public:
    uint16_t x0, x1;
    uint16_t y0, y1;
    uint16_t w, h;
    String buttonText;
    uint16_t textOffsetLeft;
    uint16_t textOffsetTop;

    Button(String name, uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, String buttonText, uint16_t textOffsetLeft, uint16_t textOffsetTop);

    String getName() { return this->name; }

    bool isPressed(int x, int y);
    void setStatus(String status) { this->currentStatus = status; }
    String getStatus() { return this->currentStatus; }
};
#endif