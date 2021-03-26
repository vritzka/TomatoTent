#ifndef TENT_H
#define TENT_H

#include "Particle.h"
#include <Arduino.h>
#include "libs/DFRobot_SHT20.h"
#include "libs/SHT30.h"
#include "libs/I2CSoilMoistureSensor.h"
#include "libs/T67XX.h"
#include "tent_state.h"

#define GROW_LIGHT_BRIGHTNESS_PIN TX
#define GROW_LIGHT_ON_OFF_PIN D7
#define FAN_SPEED_PIN RX
#define TFT_BRIGHTNESS_PIN WKP
#define DIM_PIN DAC

class Tent {
private:
    DFRobot_SHT20 sht20;
    SHT30 sht30;
    SHT30 sht30_outside_tent;
    I2CSoilMoistureSensor soil;
    Timer sensorTimer, minuteTimer;
    Timer displayDimTimer, displayOffTimer;

    int16_t displayBrightness = 0;
    String growLightStatus;
    unsigned long lastDisplayLightTime = 0;
    bool dimmerBtnPressed = false;
    unsigned long lastDimmerBtnTime = 0;

    bool needsSensorUpdate;
    void markNeedsSensorUpdate();

    void dimGrowLight();
    void muteGrowLight();
    void fadeGrowLight(String mode, int percent);

    void displayLightLow();
    void displayLightOff();

    void publishMetrics();

public:
    Tent();
    TentState state;
    int dimTimeout = 0;

    struct {
        double tentTemperatureC;
        double tentTemperatureF;
        double tentHumidity;
        double outsideTentTemperatureC;
        double outsideTentTemperatureF;
        double outsideTentHumidity;
        double soilTemperatureC;
        double soilTemperatureF;
        double waterLevel;
    } sensors;

    struct {
        double lightBrightness;
        double tentTemperature;
        double tentHumidity;
        double outsideTentTemperature;
        double outsideTentHumidity;
        double soilTemperature;
        int soilMoisture;
    } rawSensors;

    void setup();
    void start();
    void stop();

    void adjustFan();
    void countMinute(bool ignoreDayCounter = false);
    void minutelyTick();

    void checkInputs();
    void checkSensors();
    void checkTent();
    void checkSoil();

    float convertFtoC(float tempF);
    float convertCtoF(float tempC);

    void fan(String fanStatus);
    int growLight(String brightness);
    String getGrowLightStatus(void);
    bool displayLightHigh(void);
    int16_t getDisplayBrightness(void);
};
#endif
