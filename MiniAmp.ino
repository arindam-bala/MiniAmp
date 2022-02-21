//Libraries and Macros=>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_INA219.h>
#define OLED_RESET 4
//-----------------------------------------------------
//Objects=>
Adafruit_SSD1306 display(OLED_RESET);
Adafruit_INA219 ina219;
//-----------------------------------------------------
