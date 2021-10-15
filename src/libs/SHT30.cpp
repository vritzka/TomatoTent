#include "SHT30.h"
#include "math.h"

bool SHT30::setAddress(int a0)
{
    if (a0 == 1) {
        address = address | 1;
    }

    Wire.begin();
    Wire.beginTransmission(address);
    byte status = Wire.endTransmission();
    if (status != 0) {
        Serial.println("Init failed");
        return false;
    } else {
        return true;
    }
}

bool SHT30::update()
{
    Wire.beginTransmission(address);
    Wire.write(0x2c);
    Wire.write(0x06);
    byte status = Wire.endTransmission();
    if (status != 0) {
        temperature = 998;
        humidity = 0;
        vpd = 0;
        return false;
    }
    delay(10);
    Wire.requestFrom(address, 6);
    delay(50);
    buffer[0] = Wire.read();
    buffer[1] = Wire.read();
    buffer[2] = Wire.read();
    buffer[3] = Wire.read();
    buffer[4] = Wire.read();
    buffer[5] = Wire.read();
    if (crc8(buffer[0], buffer[1], buffer[2])) {
        temperature = (buffer[0] * 256 + buffer[1]) * 0.00267033 - 45;
    } else {
        temperature = 997;
    }
    if (crc8(buffer[3], buffer[4], buffer[5])) {
        humidity = (buffer[3] * 256 + buffer[4]) * 0.0015259;
    } else {
        humidity = 0;
    }

    if(temperature != 997 && humidity != 0) {
        float es = 0.61078 * exp(17.2694 * temperature / (temperature + 238.3));
        float ae = humidity / 100 * es;
        vpd = es - ae;  //kPa
    } else {
        vpd = 0;   
    }


    return true;
}

bool SHT30::crc8(uint8_t msb, uint8_t lsb, uint8_t crc)
{
    uint8_t computed = 0xFF;
    uint8_t i;

    computed ^= msb;
    for (i = 0; i < 8; i++)
        computed = computed & 0x80 ? (computed << 1) ^ 0x31 : computed << 1;

    computed ^= lsb;
    for (i = 0; i < 8; i++)
        computed = computed & 0x80 ? (computed << 1) ^ 0x31 : computed << 1;

    return crc == computed;
}
