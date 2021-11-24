#include "wifi_clear_confirm.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"

extern ScreenManager screenManager;
extern Tent tent;

void WifiClearConfirmScreen::render()
{
    tft.fillScreen(ILI9341_BLACK);
    
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(2);
    tft.setCursor(20, 40);
    tft.print("Clear all WiFi Passwords");
    tft.setCursor(40, 70);
    tft.print("and switch Wifi off?");
    
    buttons.push_back(Button("clearYesBtn", 70, 120, 180, 28, "Yes", 78, 7));
    buttons.push_back(Button("clearNoBtn", 70, 180, 180, 38, "No", 75, 8));

    renderButtons(true);
}

void WifiClearConfirmScreen::renderButton(Button& btn)
{
    if (btn.getName() == "clearYesBtn") {
        drawButton(btn, ILI9341_RED, 2);

    } else if (btn.getName() == "clearNoBtn") {
        drawButton(btn, ILI9341_OLIVE, 3);
    }
}

void WifiClearConfirmScreen::renderButtonPressed(Button& btn)
{
}

void WifiClearConfirmScreen::handleButton(Button& btn)
{
    if (btn.getName() == "clearYesBtn") {
        WiFi.off();
        tent.state.setWifiStatus(0);
        WiFi.clearCredentials();
        screenManager.wifiScreen();

    } else if (btn.getName() == "clearNoBtn") {
        screenManager.wifiScreen();
    }
}
