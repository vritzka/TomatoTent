#include "firmware_update_confirm.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"

extern ScreenManager screenManager;
extern Tent tent;

void FirmwareUpdateConfirmScreen::render()
{
    tft.fillScreen(ILI9341_PURPLE);
    
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(2);
    tft.setCursor(65, 40);
    tft.print("Update Software?");
    
    buttons.push_back(Button("updateYesBtn", 70, 120, 180, 28, "Yes", 78, 7));
    buttons.push_back(Button("updateNoBtn", 70, 180, 180, 38, "No", 75, 8));

    renderButtons(true);
}

void FirmwareUpdateConfirmScreen::renderButton(Button& btn)
{
    if (btn.getName() == "updateYesBtn") {
        drawButton(btn, ILI9341_OLIVE, 2);

    } else if (btn.getName() == "updateNoBtn") {
        drawButton(btn, ILI9341_OLIVE, 3);
    }
}

void FirmwareUpdateConfirmScreen::renderButtonPressed(Button& btn)
{
}

void FirmwareUpdateConfirmScreen::handleButton(Button& btn)
{
    if (btn.getName() == "updateYesBtn") {
        System.enableUpdates();
        screenManager.homeScreen();

    } else if (btn.getName() == "updateNoBtn") {
        System.disableUpdates();
        screenManager.wifiScreen();
    }
}

void FirmwareUpdateConfirmScreen::update()
{
    //overwrite dim indicator
}