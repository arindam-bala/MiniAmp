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
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  ina219.begin();
}
//------------------------------------------------------
//Processing-Loop=>
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    ina219values();
    displaydata();
  }
}
//-------------------------------------------------------
//Function for Display-Data
void displaydata() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(loadvoltage);
  display.setCursor(35, 0);
  display.println("V");
  display.setCursor(50, 0);
  display.println(current_mA);
  display.setCursor(95, 0);
  display.println("mA");
  display.setCursor(0, 10);
  display.println(loadvoltage * current_mA);
  display.setCursor(65, 10);
  display.println("mW");
  display.setCursor(0, 20);
  display.println(energy);
  display.setCursor(65, 20);
  display.println("mWh");
  display.display();
}
//---------------------------------------------------------
//Function for Getting Values from INA219 Sensor
void ina219values() {
  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  energy = energy + loadvoltage * current_mA / 3600;
}
//---------------------------------------------------------
