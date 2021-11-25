#include "climate.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"

extern ScreenManager screenManager;
extern Tent tent;

void ClimateScreen::render()
{
    tft.fillScreen(ILI9341_BLACK);

    tft.drawBitmap(20, 4, climate_36, 36, 36, ILI9341_GREENYELLOW);

    tft.setCursor(63, 14);
    tft.setTextColor(ILI9341_GREENYELLOW);
    tft.setTextSize(2);
    tft.print("Climate");

    buttons.push_back(Button("climateAutoBtn", 250, 70, 50, 30, "Auto", 14, 12));
    buttons.push_back(Button("climateManualBtn", 250, 107, 50, 30, "Manu", 14, 12));

    buttons.push_back(Button("climateUnitFBtn", 180, 10, 40, 30, "F", 15, 12));
    buttons.push_back(Button("climateUnitCBtn", 240, 10, 40, 30, "C", 15, 12));

    buttons.push_back(Button("climateOkBtn", 250, 180, 40, 38, "OK", 9, 12));

    drawClimateSettings();

    renderButtons(true);
}

void ClimateScreen::renderButton(Button& btn)
{
    if (btn.getName() == "climateAutoBtn") {
        drawButton(btn, tent.state.getClimateAutoMode() ? ILI9341_OLIVE : ILI9341_BLACK, 1);

    } else if (btn.getName() == "climateManualBtn") {
        drawButton(btn, !tent.state.getClimateAutoMode() ? ILI9341_OLIVE : ILI9341_BLACK, 1);

    } else if (btn.getName() == "climateUnitFBtn") {
        drawButton(btn, tent.state.getTempUnit() == 'F' ? ILI9341_OLIVE : ILI9341_BLACK, 1);
        tft.drawCircle( btn.x0 + 10, btn.y0 + 10, 2, ILI9341_LIGHTGREY);

    } else if (btn.getName() == "climateUnitCBtn") {
        drawButton(btn, tent.state.getTempUnit() == 'C' ? ILI9341_OLIVE : ILI9341_BLACK, 1);
        tft.drawCircle( btn.x0 + 10, btn.y0 + 10, 2, ILI9341_LIGHTGREY);

    } else if (btn.getName() == "targetTempUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_RED);

    } else if (btn.getName() == "targetTempDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_RED);

    } else if (btn.getName() == "targetHumUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_RED);

    } else if (btn.getName() == "targetHumDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_RED);

    } else if (btn.getName() == "climateOkBtn") {
        drawButton(btn, ILI9341_OLIVE, 2);
    }
}

void ClimateScreen::renderButtonPressed(Button& btn)
{
    if (btn.getName() == "targetTempUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_WHITE);

    } else if (btn.getName() == "targetTempDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_WHITE);

    } else if (btn.getName() == "targetHumUpBtn") {
        drawButtonTriangleUp(btn, ILI9341_WHITE);

    } else if (btn.getName() == "targetHumDownBtn") {
        drawButtonTriangleDown(btn, ILI9341_WHITE);
    }
}

void ClimateScreen::handleButton(Button& btn)
{
    if (btn.getName() == "climateUnitFBtn") {
        char tempUnit = tent.state.getTempUnit();
        if (tempUnit == 'F')
            return;   

        float targetTemperature = tent.state.getTargetTemperature();
        targetTemperature = round(tent.convertCtoF(targetTemperature));
        tent.state.setTargetTemperature(targetTemperature);

        tent.state.setTempUnit('F');

        renderButton(buttons[2]);
        renderButton(buttons[3]); 

        if (!tent.state.getClimateAutoMode())
            drawTargetTemperature();

    } else if (btn.getName() == "climateUnitCBtn") {
        char tempUnit = tent.state.getTempUnit();
        if (tempUnit == 'C')
            return;

        float targetTemperature = tent.state.getTargetTemperature();
        targetTemperature = round(tent.convertFtoC(targetTemperature));
        tent.state.setTargetTemperature(targetTemperature);

        tent.state.setTempUnit('C');

        renderButton(buttons[2]);
        renderButton(buttons[3]);

        if (!tent.state.getClimateAutoMode())
            drawTargetTemperature();

    } else if (btn.getName() == "climateOkBtn") {
        screenManager.homeScreen();

    } else if (btn.getName() == "targetTempUpBtn") {
        bool warning = 0;
        char tempUnit = tent.state.getTempUnit();
        float targetTemperature = tent.state.getTargetTemperature();

        if (tempUnit == 'F') {
            targetTemperature += 2;
            warning = (targetTemperature < 97) ? false : true;

        } else if (tempUnit == 'C') {
            targetTemperature += 1;
            warning = (targetTemperature < 35) ? false : true;
        }

        if (!warning)
            tent.state.setTargetTemperature(targetTemperature);

        drawTargetTemperature(warning);
        tent.adjustFan();

    } else if (btn.getName() == "targetTempDownBtn") {
        bool warning;
        char tempUnit = tent.state.getTempUnit();
        float targetTemperature = tent.state.getTargetTemperature();

        if (tempUnit == 'F') {
            targetTemperature -= 2;
            warning = (targetTemperature > 47) ? false : true;
        } else if (tempUnit == 'C') {
            targetTemperature -= 1;
            warning = (targetTemperature > 9) ? false : true;
        }

        if (!warning)
            tent.state.setTargetTemperature(targetTemperature);

        drawTargetTemperature(warning);
        tent.adjustFan();

    } else if (btn.getName() == "targetHumUpBtn") {
        float targetHumidity = tent.state.getTargetHumidity();
        targetHumidity += 5;

        bool warning = (targetHumidity < 100) ? false : true;

        if (!warning)
            tent.state.setTargetHumidity(targetHumidity);

        drawTargetHumidity(warning);
        tent.adjustFan();

    } else if (btn.getName() == "targetHumDownBtn") {
        float targetHumidity = tent.state.getTargetHumidity();
        targetHumidity -= 5;

        bool warning = (targetHumidity > 0) ? false : true;

        if (!warning)
            tent.state.setTargetHumidity(targetHumidity);

        drawTargetHumidity(warning);
        tent.adjustFan();

    } else if (btn.getName() == "climateAutoBtn") {
        tent.state.setClimateAutoMode(true);
        renderButton(buttons[0]);
        renderButton(buttons[1]);

        drawClimateSettings();
        
    } else if (btn.getName() == "climateManualBtn") {
        tent.state.setClimateAutoMode(false);
        renderButton(buttons[0]);
        renderButton(buttons[1]);

        drawClimateSettings();

    }
}

void ClimateScreen::drawTargetTemperature(bool warning)
{
    tft.fillRect(102, 88, 47, 22, ILI9341_BLACK);
    float targetTemperature = tent.state.getTargetTemperature();
    char tempUnit = tent.state.getTempUnit();

    if (warning) {
        tft.setCursor(102, 88);
        tft.setTextSize(3);
        tft.setTextColor(ILI9341_RED);
        tft.print(String::format("%.0f", targetTemperature));
        tft.setTextSize(1);
        tft.print(tempUnit);
        unsigned long waitUntil = millis() + 100;
        while (waitUntil > millis()) {
        }
    }
    tft.setCursor(102, 88);
    tft.setTextSize(3);
    tft.setTextColor(ILI9341_WHITE);
    tft.print(String::format("%.0f", targetTemperature));
    tft.setTextSize(1);
    tft.print(tempUnit);
}

void ClimateScreen::drawTargetHumidity(bool warning)
{
    tft.fillRect(102, 172, 47, 22, ILI9341_BLACK);
    float targetHumidity = tent.state.getTargetHumidity();
    if (warning) {
        tft.setTextColor(ILI9341_RED);
        if (targetHumidity < 10) {
            tft.setCursor(110, 172);
        } else {
            tft.setCursor(102, 172);
        }
        tft.setTextSize(3);
        tft.print(String::format("%.0f", targetHumidity));
        tft.setTextSize(1);
        tft.print("%");
        unsigned long waitUntil = millis() + 100;
        while (waitUntil > millis()) {
        }
    }
    tft.setTextColor(ILI9341_WHITE);
    if (targetHumidity < 10) {
        tft.setCursor(110, 172);
    } else {
        tft.setCursor(102, 172);
    }
    tft.setTextSize(3);
    tft.print(String::format("%.0f", targetHumidity));
    tft.setTextSize(1);
    tft.print("%");
}

void ClimateScreen::drawClimateSettings(void)
{
    tft.fillRect(10, 60, 189, 145, ILI9341_BLACK);

    if(tent.state.getClimateAutoMode()) {

        while(buttons.size() > 5) {
            buttons.pop_back();
        }

        tft.setTextColor(ILI9341_DARKGREY);
        tft.setCursor(64,80);
        tft.setTextSize(2);
        tft.print("Automatic");
        tft.setCursor(78,110);
        tft.print("Climate");
        tft.setCursor(78,140);
        tft.print("Control");
        tft.setCursor(84,170);
        tft.print("Active");

        tft.drawBitmap(10, 139, robot_48, 48, 48, ILI9341_GREENYELLOW);

    } else {
        
        tft.setCursor(64, 60);
        tft.setTextSize(1);
        tft.print("Target Temperature");
        buttons.push_back(Button("targetTempUpBtn", 165, 86, 30, 30, "", 0, 0));
        buttons.push_back(Button("targetTempDownBtn", 40, 86, 30, 30, "", 0, 0));

        tft.setCursor(83, 150);
        tft.setTextSize(1);
        tft.print("Max Humidity");
        buttons.push_back(Button("targetHumUpBtn", 165, 170, 30, 30, "", 0, 0));
        buttons.push_back(Button("targetHumDownBtn", 40, 170, 30, 30, "", 0, 0));

        drawTargetTemperature();
        drawTargetHumidity();
        renderButtons(true);

    }
}