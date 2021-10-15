#ifndef SHT30_H
#define SHT30_H

#include "spark_wiring_i2c.h"
#include "spark_wiring_usbserial.h"
#include "spark_wiring_constants.h"
#include "spark_wiring.h"

class SHT30 {
public:
    bool setAddress(int a0);
    bool update();
    double temperature;
    double humidity;
    double vpd;

private:
    int address = 0x44;
    int buffer[6] = { 0, 0, 0, 0, 0, 0 };

    bool crc8(uint8_t msb, uint8_t lsb, uint8_t crc);
};
#endif