#include "home.h"
#include "icons.h"
#include "tent.h"
#include "screen_manager.h"

extern ScreenManager screenManager;
extern Tent tent;

const float waterLevelBoxHeight = 120;
const int waterLevelBoxTop = 80;

void HomeScreen::render()
{
    tft.fillScreen(ILI9341_BLACK);
    buttons.clear();
    buttons.push_back(Button("wifiBtn", 260, 5, 60, 30, "", 18, 8));

    if (tent.state.getDayCount() == -1) {

        tft.setTextColor(ILI9341_LIGHTGREY);
        tft.setTextSize(2);

        tft.setCursor(126, 40);
        tft.print("Hello!");

        tft.drawBitmap(20, 20, tomato_filled_50, 50, 50, ILI9341_RED);

        buttons.push_back(Button("startGrowBtn", 25, 110, 270, 38, "Start a Grow", 28, 8));
        buttons.push_back(Button("startDryingBtn", 25, 180, 270, 38, "Dry a Harvest", 18, 8));

    } else { // a grow/dry is in progress

        switch (tent.state.getMode()) {
        case 'g':
            tft.drawRect(20, 180, 250, 38, ILI9341_BLACK);
            tft.drawBitmap(165, 4, fan_36, 36, 36, ILI9341_LIGHTGREY);
            tft.drawBitmap(32, 72, temperature_30, 30, 30, ILI9341_WHITE);
            tft.drawBitmap(40, 116, hygrometer_30, 30, 30, ILI9341_WHITE);

            drawDayCounter();
            drawTemperature();
            drawHumidity();
            drawSoilMoistureMeter();
            drawSoilMoisture();
            drawSoilTemperature();
            drawTimerStatus();
            drawFanStatus();

            buttons.push_back(Button("dayCounterBtn", 40, 170, 130, 45, "", 18, 8));
            buttons.push_back(Button("lightBtn", 0, 0, 139, 50, "", 18, 8));
            buttons.push_back(Button("fanBtn", 155, 0, 105, 50, "", 18, 8));
            buttons.push_back(Button("tempBtn", 40, 70, 160, 85, "", 18, 8));
            break;
        case 'd':
            tft.drawRect(20, 180, 250, 38, ILI9341_BLACK);
            tft.drawBitmap(165, 4, fan_36, 36, 36, ILI9341_LIGHTGREY);
            tft.drawBitmap(32, 72, temperature_30, 30, 30, ILI9341_WHITE);
            tft.drawBitmap(40, 116, hygrometer_30, 30, 30, ILI9341_WHITE);
            tft.drawBitmap(17, 4, wind_36, 36, 36, ILI9341_YELLOW);
            tft.drawBitmap(250, 150, about_36, 36, 36, ILI9341_DARKGREY);

            tft.setTextSize(2);
            tft.setTextColor(ILI9341_YELLOW);
            tft.setCursor(62, 14);
            tft.print("Drying");

            drawDayCounter();
            drawTemperature();
            drawHumidity();
            drawFanStatus();

            buttons.push_back(Button("dayCounterBtn", 40, 170, 130, 45, "", 18, 8));
            buttons.push_back(Button("fanBtn", 155, 0, 105, 50, "", 18, 8));
            buttons.push_back(Button("tempBtn", 40, 70, 160, 85, "", 18, 8));
            buttons.push_back(Button("dryingHintbtn", 250, 150, 36, 36, "", 18, 8));

            break;
        }
    }

    renderButtons(true);
}

void HomeScreen::update()
{
    if (wifiReady != WiFi.ready()) {
        wifiReady = WiFi.ready();
        renderButton(buttons[0]);
    }

    if (tent.state.getDayCount() == -1) {
        return;
    }

    if (screenManager.wasNeedsRedraw(TEMPERATURE))
        drawTemperature();
    if (screenManager.wasNeedsRedraw(HUMIDITY))
        drawHumidity();
    if (screenManager.wasNeedsRedraw(FAN))
        drawFanStatus();
    if (screenManager.wasNeedsRedraw(DAY))
        drawDayCounter();

    if (tent.state.getMode() == 'g') {
        if (screenManager.wasNeedsRedraw(TIMER))
            drawTimerStatus();
        if (screenManager.wasNeedsRedraw(SOIL_MOISTURE))
            drawSoilMoisture();
        if (screenManager.wasNeedsRedraw(SOIL_TEMPERATURE))
            drawSoilTemperature();
    }

    Screen::update();
}

void HomeScreen::drawTemperature()
{
    tft.fillRect(86, 75, 141, 40, ILI9341_BLACK);
    tft.setCursor(86, 75);
    tft.setTextColor(ILI9341_WHITE);

    if (tent.sensors.tentHumidity < 0) {
        tft.setTextSize(3);
        tft.setTextColor(ILI9341_MAGENTA);
        tft.print("Sensor");
        return;
    }

    char tempUnit = tent.state.getTempUnit();

    tft.setTextSize(3);
    tft.print(String::format("%.1f", tempUnit == 'F' ? tent.sensors.tentTemperatureF : tent.sensors.tentTemperatureC));

    tft.setTextSize(2);
    tft.print(String::format(" %c", tempUnit));

    tft.setCursor(86, 100);
    tft.setTextSize(1);
    tft.print(String::format("%.1f", tempUnit == 'F' ? tent.sensors.outsideTentTemperatureF : tent.sensors.outsideTentTemperatureC));
    tft.print(String::format(" %c", tempUnit));
}

void HomeScreen::drawHumidity()
{
    tft.fillRect(86, 122, 141, 40, ILI9341_BLACK);
    tft.setCursor(86, 122);
    tft.setTextColor(ILI9341_WHITE);

    if (tent.sensors.tentHumidity < 0) {
        tft.setTextSize(3);
        tft.setTextColor(ILI9341_MAGENTA);
        tft.print("Error");
        return;
    }

    tft.setTextSize(3);
    tft.print(String::format("%.1f", tent.sensors.tentHumidity));

    tft.setTextSize(2);
    tft.print(" %");
    
    tft.setCursor(86, 147);
    tft.setTextSize(1);
    tft.print(String::format("%.1f", tent.sensors.outsideTentHumidity));
    tft.print(" %");
}

void HomeScreen::drawSoilMoistureMeter()
{
    float temp = tent.sensors.soilTemperatureF;
    if (temp <= 0) {
        return;
    }

    //icon
    tft.drawBitmap(280, waterLevelBoxTop - 30, iconWateringCan_24x24, 24, 24, ILI9341_GREEN);

    //outside box
    tft.drawRect(280, waterLevelBoxTop, 25, waterLevelBoxHeight, ILI9341_DARKGREY);
}

void HomeScreen::drawSoilMoisture()
{
    float temp = tent.sensors.soilTemperatureF;

    if (temp <= 0) {
        return;
    }

    double waterLevel = tent.sensors.waterLevel;

    if (waterLevel >= 100)
        waterLevel = 99.9;
    else if (waterLevel < 0)
        waterLevel = 0;
    int waterLevelHeight = floor((waterLevelBoxHeight / 100) * waterLevel);
    int waterLevelTop = (waterLevelBoxHeight - waterLevelHeight) + waterLevelBoxTop - 1;

    //draw black over remainder
    tft.fillRect(281, waterLevelBoxTop + 1, 23, waterLevelBoxHeight - waterLevelHeight - 2, ILI9341_BLACK);

    //draw current water level
    tft.fillRect(281, waterLevelTop, 23, waterLevelHeight, ILI9341_BLUE);
}

void HomeScreen::drawSoilTemperature()
{
    char tempUnit = tent.state.getTempUnit();
    float temp = tempUnit == 'F' ? tent.sensors.soilTemperatureF : tent.sensors.soilTemperatureC;
    int x = 272;
    int y = waterLevelBoxTop + waterLevelBoxHeight + 6;

    tft.fillRect(x, y, 320 - x, 12, ILI9341_BLACK);

    if (temp <= 0) {
        return;
    }

    if (temp < 100) {
        x += 4;
    }

    tft.setCursor(x, y);
    tft.setTextSize(1);
    tft.setTextColor(ILI9341_OLIVE);
    tft.print(String::format("%.1f %c", temp, tempUnit));
}

void HomeScreen::drawDayCounter()
{
    tft.fillRect(130, 180, 80, 25, ILI9341_BLACK);

    tft.setCursor(70, 180);
    tft.setTextColor(ILI9341_CYAN);
    tft.setTextSize(3);

    tft.print("Day " + String(tent.state.getDayCount()));
}

void HomeScreen::drawClock()
{
    String currentTime = Time.format(Time.now(), "%l:%M %P %S");

    tft.fillRect(190, 7, 140, 18, ILI9341_BLACK);

    tft.setCursor(190, 7);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.print(currentTime);
}

void HomeScreen::renderButton(Button& btn)
{
    if (btn.getName() == "startGrowBtn") {
        drawButton(btn, ILI9341_OLIVE, 3);
    } else if (btn.getName() == "startDryingBtn") {
        drawButton(btn, ILI9341_OLIVE, 3);
    } else if (btn.getName() == "wifiBtn") {
        tft.drawBitmap(btn.x0 + 19, btn.y0 + 5, iconWifi_24x24, 24, 24, WiFi.ready() ? ILI9341_LIGHTGREY : ILI9341_DARKGREY);
    }
}

void HomeScreen::renderButtonPressed(Button& btn)
{
    uint16_t x0 = btn.x0, y0 = btn.y0, w = btn.w, h = btn.h;

    if (btn.getName() == "startGrowBtn") {
        tft.drawRect(x0, y0, w, h, ILI9341_LIGHTGREY);
    }
    if (btn.getName() == "startDryingBtn") {
        tft.drawRect(x0, y0, w, h, ILI9341_LIGHTGREY);
    }
}

void HomeScreen::handleButton(Button& btn)
{
    if (btn.getName() == "startGrowBtn") {
        tent.growLight("HIGH");
        tent.state.setMode('g');
        tent.state.setDayCount(1);

        screenManager.growStartedScreen();

        delay(1500);

        screenManager.homeScreen();
        tent.start();

    } else if (btn.getName() == "startDryingBtn") {
        tent.state.setMode('d');
        tent.state.setDayDuration(0);
        tent.state.setDayCount(1);

        delay(400);

        screenManager.homeScreen();
        tent.start();

    } else if (btn.getName() == "wifiBtn") {
        screenManager.wifiScreen();

    } else if (btn.getName() == "dayCounterBtn") {
        screenManager.cancelScreen();

    } else if (btn.getName() == "lightBtn") {
        screenManager.lightScreen();

    } else if (btn.getName() == "fanBtn") {
        screenManager.fanScreen();

    } else if (btn.getName() == "tempBtn") {
        screenManager.climateScreen();

    } else if (btn.getName() == "dryingHintbtn") {
        screenManager.dryingHintScreen();
    }
}
