# Intelligent Mini Home Grow Box.

Follow along on [Youtube](https://www.youtube.com/channel/UCD5GP1HyjBYer6KlEnlQQVA?sub_confirmation=1)


Credits:
[Tomato icons created by VectorPortal - Flaticon](https://www.flaticon.com/free-icons/tomato)


## Wiring

ESP32 pin     | ESP32-H2 pin
------------- |-------------
   GND        |    G
   GPI40      |    TX
   GPI41      |    RX
   GPI04      |    RST
   GPIO42     |    GPIO9 (BOOT)


ESP32 pin     | Function
------------- |-------------
   GPIO20     |   Fan PWM
   GPIO19     |   LED Dimmer PWM      
   GPIO01     |   I2C SDA (sensors)
   GPIO02     |   I2C SCL (sensors)

## Documentation

- [Display Module Datasheet](https://github.com/vritzka/TomatoTent/blob/v2/docs/WT32S3-07Datasheet-V1.5EN.pdf)  
- [AW9523 Pin Extender Datasheet](https://github.com/vritzka/TomatoTent/blob/v2/docs/AW9523%2BEnglish%2BDatasheet.pdf)
- [ESP32H2 Devboard Documentation](https://docs.espressif.com/projects/espressif-esp-dev-kits/en/latest/esp32h2/esp32-h2-devkitm-1/user_guide.html)
- [ESP Zigbee gateway](https://github.com/espressif/esp-zigbee-sdk/tree/main/examples/esp_zigbee_gateway)
- [Openthread RCP](https://github.com/espressif/esp-idf/tree/master/examples/openthread/ot_rcp) 

                    
