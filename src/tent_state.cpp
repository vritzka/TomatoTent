#include "tent_state.h"

TentState::TentState()
{
    EEPROM.get(0, eeprom);
    EEPROM.get(sizeof(eeprom), eeprom2);
}

void TentState::begin()
{
    Particle.variable("isDay", eeprom.isDay);
    Particle.variable("dayCounter", eeprom.dayCounter);
    Particle.variable("fanAutoMode", eeprom.fanAutoMode);
    Particle.variable("minutesInPhotoperiod", eeprom.minutesInPhotoperiod);
    Particle.variable("dayDuration", eeprom.dayDuration);
}

char TentState::getMode()
{
    return eeprom.mode;
}

int TentState::getDayCount()
{
    return eeprom.dayCounter;
}

bool TentState::isDay()
{
    return eeprom.isDay;
}

int TentState::getMinutesInPhotoperiod()
{
    return eeprom.minutesInPhotoperiod;
}

int TentState::getDayDuration()
{
    return eeprom.dayDuration;
}

void TentState::setDayDuration(int dayDuration)
{
    eeprom.dayDuration = dayDuration;
    save();
}

void TentState::setMode(char mode)
{
    eeprom.mode = mode;
    save();
}

void TentState::setDayCount(int dayCount)
{
    eeprom.dayCounter = dayCount;
    save();
}

void TentState::setIsDay(bool isDay)
{
    eeprom.isDay = isDay;
    save();
}

void TentState::setMinutesInPhotoperiod(int minutesInPhotoperiod)
{
    eeprom.minutesInPhotoperiod = minutesInPhotoperiod;
    save();
}

bool TentState::getFanAutoMode()
{
    return eeprom.fanAutoMode;
}

void TentState::setFanAutoMode(bool fanAutoMode)
{
    eeprom.fanAutoMode = fanAutoMode;
    save();
}

char TentState::getTempUnit()
{
    return eeprom.tempUnit;
}

void TentState::setTempUnit(char tempUnit)
{
    eeprom.tempUnit = tempUnit;
    save();
}

void TentState::setWifiStatus(bool status)
{
    eeprom.wifiStatus = status;
    save();
}

bool TentState::getWifiStatus()
{
    return eeprom.wifiStatus;
}

float TentState::getFanSpeed()
{
    return eeprom.fanSpeed;
}

void TentState::setFanSpeed(float fanSpeed)
{
    eeprom.fanSpeed = fanSpeed;
    save();
}

uint8_t TentState::getFanSpeedMin()
{
    return eeprom2.fanSpeedMin;
}

void TentState::setFanSpeedMin(float fanSpeedMin)
{
    eeprom2.fanSpeedMin = fanSpeedMin;
    save();
}

uint8_t TentState::getFanSpeedMax()
{
    return eeprom2.fanSpeedMax;
}

void TentState::setFanSpeedMax(float fanSpeedMax)
{
    eeprom2.fanSpeedMax = fanSpeedMax;
    save();
}

float TentState::getTargetTemperature()
{
    return eeprom2.targetTemperature;
}

void TentState::setTargetTemperature(float targetTemperature)
{
    eeprom2.targetTemperature = targetTemperature;
    save();
}

float TentState::getTargetHumidity()
{
    return eeprom2.targetHumidity;
}

void TentState::setTargetHumidity(float targetHumidity)
{
    eeprom2.targetHumidity = targetHumidity;
    save();
}

uint8_t TentState::getLedBrightnessMax()
{
    return eeprom2.ledBrightnessMax;
}

void TentState::setLedBrightnessMax(int brightness)
{
    eeprom2.ledBrightnessMax = brightness;
    save();
}

bool TentState::getClimateAutoMode()
{
    return eeprom2.climateAutoMode;
}

void TentState::setClimateAutoMode(bool climateAutoMode)
{
    eeprom2.climateAutoMode = climateAutoMode;
    save();
}

uint8_t TentState::getVersion(void)
{
    return eeprom2.version;
}

void TentState::save()
{
    EEPROM.put(0, eeprom);
    EEPROM.put(sizeof(eeprom), eeprom2);
}
