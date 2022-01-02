//#include <Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include "MAX30100_PulseOximeter.h"
 
#define inputInterval     500
 
PulseOximeter sensor;
uint32_t previousReadingTime = 0;
// 
//void onBeatDetected()
//{
// lcd.print("Beat!");
//}
 
void setup()
{
  lcd.begin();
    //Serial.begin(115200);
    lcd.print("Initializing...");
  delay(2000);
    // Initialize the PulseOximeter instance
    // Failures are generally due to an improper I2C wiring, missing power supply
    // or wrong target chip
    if (!sensor.begin()) {
      lcd.setCursor(0,0);
        lcd.print("SENSOR NOT READY");
        for(;;);
    } else {
      lcd.clear();
      lcd.setCursor(0,0);
        lcd.print("STARTING");
    }
     sensor.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
 
    // Register a callback for the beat detection
//    sensor.setOnBeatDetectedCallback(onBeatDetected);
}
 
void loop()
{
    // Make sure to call update as fast as possible
    sensor.update();
    if (millis() - previousReadingTime > inputInterval) {
        lcd.setCursor(0,0);
      
        lcd.print("Heart rate:");
        lcd.print(sensor.getHeartRate());
        lcd.setCursor(0,1);
        lcd.print("SpO2:");
         lcd.setCursor(12,1);
        lcd.print(sensor.getSpO2());
        lcd.print("%");
 
        previousReadingTime = millis();
    }
}
