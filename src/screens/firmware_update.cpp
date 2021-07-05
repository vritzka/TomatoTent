#include "firmware_update.h"
#include "icons.h"

void FirmwareUpdateScreen::render()
{
    tft.fillScreen(ILI9341_PURPLE);

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.setCursor(30, 50);
    tft.print("New Software arriving");

    tft.setCursor(25, 90);
    tft.setTextSize(1);
    tft.print("(Don't switch me off! Will take 10 minutes.)");

    tft.drawBitmap(192, 180, tomato_filled_50, 50, 50, ILI9341_RED);
}

void FirmwareUpdateScreen::update()
{
    // override to prevent dimmer overlays
}