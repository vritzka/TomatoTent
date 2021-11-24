#ifndef ICONS_H
#define ICONS_H

#include "Particle.h"

/*
icons come from https://icons8.com/icon/set/light/color
converted with 
http://javl.github.io/image2cpp/
settigns:
Background color:   Black
Invert image colors	
*/


const uint8_t iconBulb_16x16 [] {
	0x00, 0x00, 0x01, 0x80, 0x07, 0xe0, 0x0c, 0x30, 0x18, 0x18, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 
	0x18, 0x18, 0x08, 0x10, 0x0c, 0x30, 0x07, 0xe0, 0x03, 0xc0, 0x03, 0xc0, 0x01, 0x80, 0x00, 0x00
};

const uint8_t iconWateringCan_24x24 [] {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x1f, 0xf0, 0x00, 
	0x38, 0x38, 0x00, 0x30, 0x18, 0x00, 0x70, 0x1c, 0x00, 0x60, 0x0c, 0x00, 0x7f, 0xec, 0x1c, 0x7f, 
	0xec, 0x1c, 0x00, 0x1c, 0x1e, 0x7f, 0xf8, 0x07, 0x7f, 0xf8, 0x07, 0xff, 0xf0, 0x03, 0xff, 0xe0, 
	0x03, 0xff, 0xe0, 0x01, 0xff, 0xe0, 0x00, 0xff, 0xe0, 0x00, 0xff, 0xe0, 0x00, 0x7f, 0xe0, 0x00, 
	0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t iconWifi_24x24 [] {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0x00, 0x03, 0xff, 0xc0, 0x0f, 0xff, 0xf0, 0x3f, 0x81, 0xfc, 0x3c, 0x00, 0x3c, 0x30, 0x7e, 
	0x0c, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x07, 0x81, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 
	0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char plant_filled_72x72 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 
	0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xe7, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x7f, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xfc, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x1f, 0xe0, 
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 
	0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 
	0xf0, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 
	0x00, 0x1f, 0xf8, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x1f, 0xf0, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x3f, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 
	0x81, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfc, 
	0x03, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0x81, 0xff, 0xfc, 0x07, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xc0, 
	0x3f, 0xfe, 0x0f, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xe0, 0x0f, 0xfe, 0x1f, 0xff, 0xff, 0xc0, 0x00, 
	0x1f, 0xfe, 0x03, 0xff, 0x1f, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0x81, 0xff, 0x1f, 0xfc, 0x3f, 
	0xf0, 0x00, 0x0f, 0xff, 0xe0, 0x7f, 0x1f, 0xc0, 0x03, 0xf8, 0x00, 0x0f, 0xff, 0xf8, 0x3f, 0x1f, 
	0x00, 0x03, 0xf8, 0x00, 0x0f, 0xff, 0xfe, 0x1e, 0x0c, 0x03, 0xe7, 0xf8, 0x00, 0x07, 0xff, 0xff, 
	0x0e, 0x08, 0x3f, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xff, 0x84, 0x00, 0xff, 0xff, 0xe0, 0x00, 0x07, 
	0xff, 0xff, 0xc4, 0x11, 0xff, 0xff, 0xe0, 0x00, 0x03, 0xff, 0xff, 0xe4, 0x33, 0xff, 0xff, 0xc0, 
	0x00, 0x03, 0xff, 0xff, 0xee, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x01, 0xff, 0xff, 0xfe, 0x7f, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xe7, 0x77, 0xff, 0xfe, 0x00, 0x00, 0x00, 0xff, 0xff, 0xe7, 
	0xf3, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xc3, 0xe3, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x1f, 
	0xff, 0x03, 0xe0, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x07, 0xfc, 0x03, 0xe0, 0x7f, 0x80, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char sun_36 [] PROGMEM = {
	0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x70, 0x00, 0x00, 0x02, 0x00, 0x60, 0x04, 0x00, 0x07, 0x00, 0x00, 0x0e, 0x00, 0x0f, 0x80, 
	0x00, 0x1f, 0x00, 0x07, 0x80, 0x00, 0x1e, 0x00, 0x03, 0x03, 0xfc, 0x0c, 0x00, 0x00, 0x0f, 0xff, 
	0x00, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0xe0, 
	0x00, 0x00, 0x7f, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xf0, 0x00, 
	0x00, 0xff, 0xff, 0xf0, 0x00, 0xf8, 0xff, 0xff, 0xf0, 0xf0, 0xf8, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 
	0xff, 0xff, 0xf0, 0xf0, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x7f, 
	0xff, 0xe0, 0x00, 0x00, 0x7f, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0x1f, 0xff, 
	0x80, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x03, 0x03, 0xfc, 0x0c, 0x00, 0x07, 0x80, 0x00, 0x1e, 
	0x00, 0x0f, 0x80, 0x00, 0x1f, 0x00, 0x07, 0x00, 0x00, 0x0e, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 
	0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 
	0x00, 0x70, 0x00, 0x00
};

const unsigned char moon_and_stars_36 [] PROGMEM = {
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 
	0x00, 0x1f, 0xc0, 0x00, 0x00, 0x04, 0x0f, 0x80, 0x00, 0x00, 0x1c, 0x07, 0x00, 0x00, 0x00, 0x7c, 
	0x02, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x04, 0x00, 0x03, 0xf8, 0x00, 
	0x0e, 0x00, 0x03, 0xf8, 0x00, 0x0e, 0x00, 0x07, 0xf8, 0x00, 0x0e, 0x00, 0x07, 0xf8, 0x00, 0x7f, 
	0xc0, 0x0f, 0xfc, 0x00, 0x7f, 0xc0, 0x0f, 0xfc, 0x00, 0x0e, 0x00, 0x0f, 0xfc, 0x00, 0x0e, 0x00, 
	0x0f, 0xfe, 0x00, 0x0e, 0x00, 0x0f, 0xff, 0x00, 0x04, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x0f, 
	0xff, 0x80, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xf8, 0x02, 0x00, 0x0f, 0xff, 
	0xff, 0xfe, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 
	0xfc, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x7f, 0xff, 0xe0, 
	0x00, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00
};

const unsigned char tomato_filled_50 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0xf0, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0xf7, 0xf0, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x00, 
	0x00, 0x00, 0x11, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x78, 0xff, 0xff, 0xfc, 0x40, 0x00, 0x01, 
	0xfc, 0x3f, 0xff, 0xfc, 0xf0, 0x00, 0x03, 0xfc, 0xff, 0xff, 0xe1, 0xf8, 0x00, 0x07, 0xf9, 0xff, 
	0xff, 0xe3, 0xfc, 0x00, 0x0f, 0xf9, 0xff, 0xff, 0xf1, 0xfe, 0x00, 0x1f, 0xf3, 0xff, 0xff, 0xf8, 
	0xff, 0x00, 0x1f, 0xc3, 0xff, 0xff, 0xfc, 0x3f, 0x00, 0x3f, 0xc7, 0xfd, 0xfd, 0xfe, 0x3f, 0x80, 
	0x3f, 0x8f, 0xf9, 0xfc, 0xfc, 0x3f, 0x80, 0x7f, 0xc0, 0xe1, 0xfc, 0x00, 0x7f, 0x80, 0x7f, 0xf0, 
	0x01, 0xfc, 0x01, 0xff, 0x80, 0x7f, 0xfe, 0x0c, 0xf9, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xfc, 0x79, 
	0xff, 0xff, 0xc0, 0xff, 0xff, 0xfe, 0x39, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0x13, 0xff, 0xff, 
	0xc0, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xc0, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xff, 0xff, 0xff, 
	0xff, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 
	0xff, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 
	0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00
};

const unsigned char fan_24 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x01, 0xff, 0x80, 0x07, 0xc3, 0xe0, 0x0e, 
	0x00, 0x70, 0x0c, 0x70, 0x30, 0x18, 0xf0, 0x18, 0x18, 0xf8, 0x18, 0x38, 0x78, 0x1c, 0x30, 0x20, 
	0x0c, 0x30, 0x1b, 0xcc, 0x30, 0x5b, 0xcc, 0x30, 0xe7, 0xcc, 0x39, 0xe3, 0xdc, 0x19, 0xe0, 0x18, 
	0x19, 0xe0, 0x18, 0x0c, 0x00, 0x30, 0x0e, 0x00, 0x70, 0x07, 0xc3, 0xe0, 0x01, 0xff, 0x80, 0x00, 
	0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char thermometer_36 [] PROGMEM = { 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 
0x03, 0xf0, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 
0xff, 0x80, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 
0x80, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0x80, 
0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 
0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 
0x03, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x03, 
0xf8, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x0f, 0xfe, 
0x00, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x00, 
0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 
0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00
};

const unsigned char wind_36 [] PROGMEM = { 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x01, 0xc7, 
0x01, 0xf0, 0x00, 0x00, 0x03, 0x83, 0xfc, 0x00, 0x00, 0x03, 0x87, 0x9e, 0x00, 0x00, 0x03, 0x86, 
0x07, 0x00, 0x00, 0x03, 0x80, 0x07, 0x00, 0x00, 0x07, 0x00, 0x03, 0x00, 0x0f, 0xfe, 0x00, 0x03, 
0x00, 0x0f, 0xfc, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 
0x00, 0x00, 0x00, 0x1e, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 
0xff, 0x80, 0x00, 0x0f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x60, 
0x00, 0x00, 0x00, 0x38, 0xe0, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00
};

const unsigned char hygrometer_30 [] PROGMEM = { 
0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x04, 0x60, 0x00, 0x20, 0x04, 0x20, 0x00, 0x70, 
0x04, 0x30, 0x00, 0xd0, 0x04, 0x20, 0x00, 0x98, 0x04, 0x30, 0x00, 0x98, 0x04, 0x20, 0x00, 0x70, 
0x04, 0x30, 0x00, 0x00, 0x05, 0x30, 0x08, 0x00, 0x05, 0x20, 0x0c, 0x00, 0x05, 0x30, 0x14, 0x00, 
0x05, 0x20, 0x32, 0x00, 0x05, 0x30, 0x22, 0x00, 0x05, 0x20, 0x22, 0x00, 0x05, 0x20, 0x36, 0x00, 
0x05, 0x20, 0x0c, 0x00, 0x19, 0x30, 0x00, 0x20, 0x31, 0x08, 0x00, 0x70, 0x21, 0x8c, 0x00, 0xd0, 
0x67, 0xc4, 0x00, 0x88, 0x67, 0xe4, 0x00, 0x88, 0x47, 0xe4, 0x01, 0x88, 0x67, 0xc4, 0x00, 0x88, 
0x23, 0xc4, 0x00, 0x70, 0x30, 0x08, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x0e, 0x70, 0x00, 0x00, 
0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char temperature_30 [] PROGMEM = { 
0x00, 0x07, 0x80, 0x00, 0x00, 0x08, 0x40, 0x00, 0x00, 0x18, 0x60, 0x00, 0x00, 0x10, 0x20, 0x00, 
0x00, 0x1e, 0x20, 0x00, 0x00, 0x10, 0x20, 0x00, 0x00, 0x1c, 0x20, 0x00, 0x00, 0x10, 0x20, 0x00, 
0x00, 0x1f, 0xe0, 0x00, 0x00, 0x18, 0x60, 0x00, 0x00, 0x10, 0x20, 0x00, 0x00, 0x1c, 0x20, 0x00, 
0x00, 0x10, 0x20, 0x00, 0x00, 0x1e, 0x20, 0x00, 0x00, 0x10, 0x20, 0x00, 0x00, 0x18, 0x20, 0x00, 
0x00, 0x18, 0x20, 0x00, 0x00, 0x10, 0x20, 0x00, 0x00, 0x1e, 0x20, 0x00, 0x00, 0x20, 0x10, 0x00, 
0x00, 0x40, 0x08, 0x00, 0x00, 0x40, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x80, 0x24, 0x00, 
0x00, 0x40, 0x08, 0x00, 0x00, 0x40, 0x28, 0x00, 0x00, 0x42, 0x88, 0x00, 0x00, 0x20, 0x10, 0x00, 
0x00, 0x18, 0x60, 0x00, 0x00, 0x07, 0x80, 0x00
};

const unsigned char atmospheric_pressure_30 [] PROGMEM = {
	0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 
	0x02, 0x04, 0x10, 0x04, 0x02, 0x04, 0x10, 0x3c, 0x02, 0x04, 0x10, 0x04, 0x02, 0x0c, 0x10, 0x04, 
	0x02, 0x0c, 0x10, 0x04, 0x02, 0x0c, 0x10, 0x0c, 0x02, 0x08, 0x10, 0x1c, 0x06, 0x08, 0x10, 0x04, 
	0x04, 0x08, 0x20, 0x04, 0x04, 0x18, 0x20, 0x04, 0x08, 0x10, 0x60, 0xfc, 0x08, 0x30, 0x40, 0xfc, 
	0x18, 0x20, 0xc0, 0x04, 0x10, 0x20, 0x80, 0x04, 0x10, 0x60, 0x80, 0x04, 0x10, 0x40, 0x80, 0x1c, 
	0x10, 0x40, 0x80, 0x0c, 0x10, 0x40, 0x80, 0x04, 0xfd, 0x52, 0xe0, 0x04, 0x78, 0xf3, 0xc0, 0x04, 
	0x30, 0x61, 0x80, 0x3c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 
	0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x01, 0xfc
};

const unsigned char arrow_down_24 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x00, 
	0x3c, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 
	0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 
	0x00, 0xff, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x18, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif