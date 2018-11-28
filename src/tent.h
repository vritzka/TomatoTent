#ifndef TENT_H
#define TENT_H

#include <Particle.h>

class Tent {
  
  double step;
  double difference_min_max;
  
  public:
         unsigned long lastTime;
        int brightness;
        Timer *tp;
        Timer *tp1;
  
  Tent();

    void check_temperature();
    void draw_temperature_home();
    void check_humidity();
    void draw_humidity_home();
    void check_waterlevel();
    void draw_waterlevel_home();
    void check_fan();  
    void checkStats();
    int growLight(String brightness);
    
    void displayLightLow(void);
    void displayLightOff(void);
    bool displayLightHigh();
  
   // void drawTime();
   
};
#endif
