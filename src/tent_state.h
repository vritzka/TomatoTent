#pragma once

#include "Particle.h"
#include <Arduino.h>
#include "math.h"

class TentState {
    
    struct {
        int dayCounter; // counting days the grow or dry was active. Starting from 1
        bool isDay; // true if the light is on
        int minutesInPhotoperiod; // how long has the system been in current photoperiod?  E.g. 31 minutes in NIGHT
        int dayDuration; // how long is the light on?
        bool fanAutoMode; // 1 for auto, 0 for manual
        float fanSpeed; // 0-100%
        char tempUnit; // F or C
        bool wifiStatus; // 1=on, 0=off
        char mode; // g=growing, d=dryimg
    } eeprom;
    
     struct {
        uint8_t version;
        float targetTemperature;
        float targetHumidity;
        uint8_t fanSpeedMin;
        uint8_t fanSpeedMax;
        uint8_t ledBrightnessMax;
    } eeprom2;  
    

public:
    TentState();
    
    void init()
    {
        eeprom.dayCounter = -1;
        eeprom.isDay = true;
        eeprom.minutesInPhotoperiod = 0;
        eeprom.dayDuration = 18 * 60;
        eeprom.fanAutoMode = 1;
        eeprom.fanSpeed = 30;
        eeprom.tempUnit = 'F';
        eeprom.wifiStatus = 1;
        eeprom.mode = 'g';
        
        eeprom2.version = 2;
        eeprom2.targetTemperature = 77.0;
        eeprom2.targetHumidity = 70.0;
        eeprom2.fanSpeedMin = 25;
        eeprom2.fanSpeedMax = 50;
        eeprom2.ledBrightnessMax = 100;
        save();
    }
    
    void migrate()
    {
        eeprom2.version = 2;
        eeprom2.targetTemperature = 77.0;
        eeprom2.targetHumidity = 50.0;
        eeprom2.fanSpeedMin = 15;
        eeprom2.fanSpeedMax = 40;
        eeprom2.ledBrightnessMax = 100;
        save();
    }
    
    void begin();
    void save();

    bool isDay(void);
    void setIsDay(bool);

    int getDayCount(void);
    void setDayCount(int);

    char getMode(void);
    void setMode(char);

    int getMinutesInPhotoperiod(void);
    void setMinutesInPhotoperiod(int);

    int getDayDuration(void);
    void setDayDuration(int);

    bool getFanAutoMode(void);
    void setFanAutoMode(bool);

    float getFanSpeed(void);
    void setFanSpeed(float);

    uint8_t getFanSpeedMin(void);
    void setFanSpeedMin(float);

    uint8_t getFanSpeedMax(void);
    void setFanSpeedMax(float);

    char getTempUnit(void);
    void setTempUnit(char);

    bool getWifiStatus(void);
    void setWifiStatus(bool);

    float getTargetTemperature(void);
    void setTargetTemperature(float);

    float getTargetHumidity(void);
    void setTargetHumidity(float);
    
    uint8_t getLedBrightnessMax(void);
    void setLedBrightnessMax(int);
    
    uint8_t getVersion(void);
    
    
};
