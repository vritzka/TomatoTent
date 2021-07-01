#include "wifi_splash.h"
#include "icons.h"

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
    tft.print("Use a SmartPhone, Tablet or Computer");
    tft.setCursor(20, 70);
    tft.print("Go to WiFi settings, scan for Networks.");
    tft.setCursor(20, 90);
    tft.print("Connect to the Network called TTNT-xxxx.");
    tft.setCursor(20, 110);
    tft.print("Open a Web Browser (Safari, Chrome, IE).");
    tft.setCursor(20, 130);
    tft.print("Navigate to http://192.168.0.1");
    tft.setCursor(20, 150);
    tft.print("Follow the instructions there.");

    tft.setCursor(20, 200);
    tft.setTextSize(2);
    tft.setTextColor(ILI9341_GREEN);
    tft.print("community.tomatotent.de");
}
