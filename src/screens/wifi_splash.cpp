#include "wifi_splash.h"
#include "icons.h"
#include <Arduino.h>
extern "C" {
#include "libs/qrduino/qrencode.h"
}

WifiSplashScreen::WifiSplashScreen()
    : Screen()
{
        String url = "http://192.168.0.1";
        strncpy((char*)strinbuf, url.c_str(), 245);
        qrencode();
}

void WifiSplashScreen::render()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.drawBitmap(18, 5, iconWifi_24x24, 24, 24, ILI9341_WHITE);

    tft.setCursor(50, 10);
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(3);
    tft.print("WiFi Setup");

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(1);
    tft.setCursor(20, 50);
    tft.print("1. Take your Phone");
    tft.setCursor(20, 70);
    tft.print("2. Connect to WiFi Network TMT-XXXXXX");
    tft.setCursor(20, 90);
    tft.print("3. With your camera, scan this QR-code.");
    tft.setCursor(38, 104);
    tft.print("Or, open a Web Browser and");
    tft.setCursor(38, 118);
    tft.print("go to http://192.168.0.1");

    int x, y, xOffset = 220, yOffset = 105;
    tft.setTextSize(1);
    tft.setTextColor(ILI9341_WHITE);
    tft.setCursor(xOffset, yOffset);
    for (y = 0; y < WD; y++) {
        for (x = 0; x < WD; x++) {
            int color = QRBIT(x, y) ? ILI9341_WHITE : ILI9341_BLACK;
            int x0 = xOffset + x * 2, y0 = yOffset + 12 + y * 2;
            tft.drawPixel(x0, y0, color);
            tft.drawPixel(x0 + 1, y0, color);
            tft.drawPixel(x0, y0 + 1, color);
            tft.drawPixel(x0 + 1, y0 + 1, color);
        }
    }

    tft.setCursor(168, 220);
    tft.print("cancel");
    tft.drawBitmap(144, 216, arrow_down_24, 24, 24, ILI9341_WHITE);

}

void WifiSplashScreen::update() {
    return;
}
