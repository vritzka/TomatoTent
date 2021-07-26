#include "climate.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"

extern ScreenManager screenManager;
extern Tent tent;

void ClimateScreen::render()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.drawBitmap(20, 4, thermometer_36, 36, 36, ILI9341_WHITE);
    
    tft.setCursor(60, 11);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Units");

    buttons.push_back(Button("climateUnitFBtn", 150, 70, 40, 38, "F", 15, 11));
    buttons.push_back(Button("climateUnitCBtn", 150, 107, 40, 38, "C", 15, 11));

    buttons.push_back(Button("climateOkBtn", 150, 180, 40, 38, "OK", 9, 12));

    renderButtons(true);
}

void ClimateScreen::renderButton(Button& btn)
{
    if (btn.getName() == "climateUnitFBtn") {
        drawButton(btn, tent.state.getTempUnit() == 'F' ? ILI9341_OLIVE : ILI9341_BLACK, 2);

    } else if (btn.getName() == "climateUnitCBtn") {
        drawButton(btn, tent.state.getTempUnit() == 'C' ? ILI9341_OLIVE : ILI9341_BLACK, 2);

    } else if (btn.getName() == "climateOkBtn") {
        drawButton(btn, ILI9341_OLIVE, 2);
    }
}

void ClimateScreen::renderButtonPressed(Button& btn)
{

}

void ClimateScreen::handleButton(Button& btn)
{
    if (btn.getName() == "climateUnitFBtn") {
        char tempUnit = tent.state.getTempUnit();
        if (tempUnit == 'F')
            return;

        tent.state.setTempUnit('F');

        renderButton(buttons[0]);
        renderButton(buttons[1]);

    } else if (btn.getName() == "climateUnitCBtn") {
        char tempUnit = tent.state.getTempUnit();
        if (tempUnit == 'C')
            return;

        tent.state.setTempUnit('C');

        renderButton(buttons[0]);
        renderButton(buttons[1]);

    } else if (btn.getName() == "climateOkBtn") {
        screenManager.homeScreen();

    } 
}