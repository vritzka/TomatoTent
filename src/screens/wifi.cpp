#include "wifi.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"
#include <Arduino.h>
extern "C" {
#include "libs/qrduino/qrencode.h"
}

extern ScreenManager screenManager;
extern Tent tent;
extern uint16_t __system_product_version;

WifiScreen::WifiScreen()
    : Screen()
{
    if (strinbuf[0] == 0) {
        String url = "https://my.tomatotent.com/graphs/" + System.deviceID();
        strncpy((char*)strinbuf, url.c_str(), 245);
        qrencode();
    }
}

void WifiScreen::render()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.drawBitmap(20, 14, iconWifi_24x24, 24, 24, ILI9341_WHITE);

    tft.setCursor(60, 18);
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(2);
    tft.print("WiFi");

    tft.setCursor(60, 38);
    tft.setTextSize(1);
    if (WiFi.ready())
        tft.print(String::format("Connected: %s (%d%%)", WiFi.SSID(), (int)WiFi.RSSI().getStrength()));
    else if (WiFi.connecting())
        tft.print("Connecting ...");
    else
        tft.print("Disconnected");

    tft.setCursor(60, 52);
    tft.setTextSize(1);
    tft.setTextColor(ILI9341_LIGHTGREY);
    tft.print(String::format("TomatoTent v%d ", __system_product_version));
    if (WiFi.ready())     
        tft.print("on http://" + WiFi.localIP().toString());

    if (Particle.connected()) {
        int x, y, xOffset = 220, yOffset = 90;
        tft.setTextSize(1);
        tft.setTextColor(ILI9341_WHITE);
        tft.setCursor(xOffset, yOffset);
        tft.print("Grow Graphs");
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
    } 

    buttons.push_back(Button("wifiOnBtn", 30, 100, 80, 38, "On", 25, 8));
    buttons.push_back(Button("wifiOffBtn", 115, 100, 80, 38, "Off", 16, 8));
    buttons.push_back(Button("wifiClearBtn", 240, 10, 75, 30, "Clear", 9, 8));
    buttons.push_back(Button("wifiOkBtn", 30, 150, 165, 38, "Back", 50, 8));

    renderButtons(true);
}

void WifiScreen::renderButton(Button& btn)
{
    if (btn.getName() == "wifiOnBtn") {
        drawButton(btn, WiFi.ready() || WiFi.connecting() ? ILI9341_OLIVE : ILI9341_BLACK, 3);

    } else if (btn.getName() == "wifiOffBtn") {
        drawButton(btn, !WiFi.ready() && !WiFi.connecting() ? ILI9341_OLIVE : ILI9341_BLACK, 3);

    } else if (btn.getName() == "wifiOkBtn") {
        drawButton(btn, ILI9341_OLIVE, 3);

    } else if (btn.getName() == "wifiClearBtn") {
        drawButton(btn, ILI9341_BLACK, 2);
    }
}

void WifiScreen::renderButtonPressed(Button& btn)
{
    if (btn.getName() == "wifiClearBtn") {
        drawButton(btn, ILI9341_WHITE, 2);
    }
}

void WifiScreen::handleButton(Button& btn)
{
    if (btn.getName() == "wifiOnBtn") {
        Particle.connect();
        tent.state.setWifiStatus(1);
        screenManager.wifiScreen();

    } else if (btn.getName() == "wifiOffBtn") {
        WiFi.off();
        tent.state.setWifiStatus(0);
        screenManager.wifiScreen();
        
    } else if (btn.getName() == "wifiClearBtn") {
        screenManager.wifiClearConfirmScreen();

    } else if (btn.getName() == "wifiOkBtn") {
        screenManager.homeScreen();
    }
}
