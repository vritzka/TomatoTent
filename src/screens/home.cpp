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

        tft.setCursor(126, 15);
        tft.print("Hi,");

        tft.setCursor(75, 40);
        tft.print("I'm Tomatotent.");

        tft.drawBitmap(110, 65, tomato_filled_100, 100, 100, ILI9341_RED);

        buttons.push_back(Button("startGrowBtn", 35, 180, 250, 38, "Start a Grow", 18, 8));

    } else { // a grow is in progress

        tft.drawRect(20, 180, 250, 38, ILI9341_BLACK);
        tft.drawBitmap(165, 4, fan_36, 36, 36, ILI9341_WHITE);

        drawDayCounter();
        drawTemperature();
        drawHumidity();
        drawSoilMoistureMeter();
        drawSoilMoisture();
        drawSoilTemperature();
        drawTimerStatus();
        drawFanStatus();

        buttons.push_back(Button("dayCounterBtn", 20, 180, 250, 38, "", 18, 8));
        buttons.push_back(Button("timerBtn", 10, 10, 115, 30, "", 18, 8));
        buttons.push_back(Button("fanBtn", 145, 10, 115, 35, "", 18, 8));
        buttons.push_back(Button("tempBtn", 50, 55, 115, 35, "", 18, 8));
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

    if (screenManager.wasNeedsRedraw(TIMER))
        drawTimerStatus();
    if (screenManager.wasNeedsRedraw(TEMPERATURE))
        drawTemperature();
    if (screenManager.wasNeedsRedraw(HUMIDITY))
        drawHumidity();
    if (screenManager.wasNeedsRedraw(SOIL_MOISTURE))
        drawSoilMoisture();
    if (screenManager.wasNeedsRedraw(SOIL_TEMPERATURE))
        drawSoilTemperature();
    if (screenManager.wasNeedsRedraw(FAN))
        drawFanStatus();
    if (screenManager.wasNeedsRedraw(DAY))
        drawDayCounter();

    Screen::update();
}

void HomeScreen::drawTemperature()
{
    tft.fillRect(50, 70, 141, 25, ILI9341_BLACK);
    tft.setCursor(50, 70);
    tft.setTextColor(ILI9341_GREEN);

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
}

void HomeScreen::drawHumidity()
{
    tft.fillRect(50, 120, 141, 25, ILI9341_BLACK);
    tft.setCursor(50, 120);
    tft.setTextColor(ILI9341_PINK);

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
}

void HomeScreen::drawSoilMoistureMeter()
{
    //icon
    tft.drawBitmap(280, waterLevelBoxTop - 30, iconWateringCan_24x24, 24, 24, ILI9341_GREEN);

    //outside box
    tft.drawRect(280, waterLevelBoxTop, 25, waterLevelBoxHeight, ILI9341_DARKGREY);
}

void HomeScreen::drawSoilMoisture()
{
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

void HomeScreen::drawTimerStatus()
{
    int hoursLeft;
    int minutesLeft;

    if (tent.state.isDay()) {
        tft.setTextColor(ILI9341_YELLOW);
        hoursLeft = floor((tent.state.getDayDuration() - tent.state.getMinutesInPhotoperiod()) / 60);
        minutesLeft = (tent.state.getDayDuration() - tent.state.getMinutesInPhotoperiod()) % 60;
    } else {
        tft.setTextColor(ILI9341_BLUE);
        hoursLeft = floor((((24 * 60) - tent.state.getDayDuration()) - tent.state.getMinutesInPhotoperiod()) / 60);
        minutesLeft = (((24 * 60) - tent.state.getDayDuration()) - tent.state.getMinutesInPhotoperiod()) % 60;
    }

    if (hoursLeft < 0 || minutesLeft < 0) {

        tent.countMinute();

    } else {

        tft.fillRect(5, 5, 137, 37, ILI9341_BLACK);

        tft.setCursor(50, 10);
        tft.setTextSize(2);

        tft.print(String(hoursLeft));
        tft.setTextSize(1);
        tft.print("hrs ");
        tft.setTextSize(2);
        tft.print("" + String(minutesLeft));
        tft.setTextSize(1);
        tft.print("min");

        tft.setCursor(53, 31);
        tft.setTextSize(1);
        if (tent.state.isDay()) {
            tft.drawBitmap(7, 5, sun_36, 36, 36, ILI9341_YELLOW);
            tft.print("until sunset");
        } else {
            tft.drawBitmap(7, 5, moon_and_stars_36, 36, 36, ILI9341_BLUE);
            tft.print("until sunrise");
        }
    }
}

void HomeScreen::drawDayCounter()
{
    tft.fillRect(130, 180, 80, 25, ILI9341_BLACK);

    tft.setCursor(70, 180);
    tft.setTextColor(ILI9341_WHITE);
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

    } else if (btn.getName() == "wifiBtn") {
        tft.drawBitmap(btn.x0 + 19, btn.y0 + 5, iconWifi_24x24, 24, 24, WiFi.ready() ? ILI9341_LIGHTGREY : ILI9341_DARKGREY);
    }
}

void HomeScreen::renderButtonPressed(Button& btn)
{
    uint16_t x0 = btn.x0, y0 = btn.y0, w = btn.w, h = btn.h;

    if (btn.getName() == "startGrowBtn") {
        tft.drawRect(x0, y0, w, h, ILI9341_RED);
    }
}

void HomeScreen::handleButton(Button& btn)
{
    if (btn.getName() == "startGrowBtn") {
        tent.growLight("HIGH");
        tent.state.setDayCount(1);

        screenManager.growStartedScreen();

        delay(3000);

        screenManager.homeScreen();
        tent.start();

    } else if (btn.getName() == "wifiBtn") {
        screenManager.wifiScreen();

    } else if (btn.getName() == "dayCounterBtn") {
        screenManager.cancelScreen();

    } else if (btn.getName() == "timerBtn") {
        screenManager.timerScreen();

    } else if (btn.getName() == "fanBtn") {
        screenManager.fanScreen();

    } else if (btn.getName() == "tempBtn") {
        screenManager.tempUnitScreen();
    }
}
