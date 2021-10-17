#include "cancel_confirm.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"

extern ScreenManager screenManager;
extern Tent tent;

void CancelConfirmScreen::render()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setCursor(10, 50);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(3);
    tft.print("Really Terminate?");

    buttons.push_back(Button("terminateYesBtn", 70, 120, 180, 28, "Yes", 78, 7));
    buttons.push_back(Button("terminateNoBtn", 70, 180, 180, 38, "No", 75, 8));

    renderButtons(true);
}

void CancelConfirmScreen::renderButton(Button& btn)
{
    if (btn.getName() == "terminateYesBtn") {
        drawButton(btn, ILI9341_RED, 2);

    } else if (btn.getName() == "terminateNoBtn") {
        drawButton(btn, ILI9341_OLIVE, 3);
    }
}

void CancelConfirmScreen::renderButtonPressed(Button& btn)
{
}

void CancelConfirmScreen::handleButton(Button& btn)
{
    if (btn.getName() == "terminateYesBtn") {
        tent.growLight("OFF");
        tent.fan("OFF");
        tent.stop();

        tent.state.init();
        screenManager.homeScreen();

    } else if (btn.getName() == "terminateNoBtn") {
        screenManager.lightScreen();
    }
}
