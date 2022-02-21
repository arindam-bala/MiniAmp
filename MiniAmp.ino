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
//Global Variables=>
unsigned long previousMillis = 0;
unsigned long interval = 100;
float shuntvoltage = 0;
float busvoltage = 0;
float current_mA = 0;
float loadvoltage = 0;
float energy = 0;
//-----------------------------------------------------
//System-Setup=>
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  ina219.begin();
}
