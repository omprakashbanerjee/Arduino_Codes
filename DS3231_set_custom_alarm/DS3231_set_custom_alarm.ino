/* Example implementation of an alarm using DS3231
 *
 * VCC and GND of RTC should be connected to some power source
 * SDA, SCL of RTC should be connected to SDA, SCL of arduino
 * SQW should be connected to CLOCK_INTERRUPT_PIN
 * CLOCK_INTERRUPT_PIN needs to work with interrupts
 */

#include <RTClib.h>
// #include <Wire.h>

RTC_DS3231 rtc;
DateTime now;
// the pin that is connected to SQW
#define CLOCK_INTERRUPT_PIN 2
uint8_t hh=21,mm=53,ss=0;
byte state=0;
void setup() {
    Serial.begin(9600);
    pinMode(13,OUTPUT);

    // initializing the rtc
    if(!rtc.begin()) {
        Serial.println("Couldn't find RTC!");
        Serial.flush();
        abort();
    }
    
    //if(rtc.lostPower()) {
        // this will adjust to the date and time at compilation
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   // }
    
    //we don't need the 32K Pin, so disable it
    rtc.disable32K();
    
    // Making it so, that the alarm will trigger an interrupt
    pinMode(CLOCK_INTERRUPT_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(CLOCK_INTERRUPT_PIN), onAlarm, RISING);
    
    // set alarm 1, 2 flag to false (so alarm 1, 2 didn't happen so far)
    // if not done, this easily leads to problems, as both register aren't reset on reboot/recompile
    rtc.clearAlarm(1);
    rtc.clearAlarm(2);
    
    // stop oscillating signals at SQW Pin
    // otherwise setAlarm1 will fail
    rtc.writeSqwPinMode(DS3231_OFF);
    
    // turn off alarm 2 (in case it isn't off already)
    // again, this isn't done at reboot, so a previously set alarm could easily go overlooked
    rtc.disableAlarm(2);
    
    // schedule an alarm 10 seconds in the future
//    if(!rtc.setAlarm1(rtc.now() + TimeSpan(1),DS3231_A1_Minute ))
//            {// this mode triggers the alarm when the seconds match. See Doxygen for other options
//        Serial.println("Error, alarm wasn't set!");
//    }else {
//        Serial.println("Alarm will happen in 10 seconds!");  
//    }
}

void loop() {
    // print current time
    char date[10] = "hh:mm:ss";
    rtc.now().toString(date);
    Serial.println(date);
//    Serial.print("temp =");
//    Serial.println(rtc.getTemperature());
//    // the value at SQW-Pin (because of pullup 1 means no alarm)
//    Serial.print(" SQW: ");
//    Serial.println(digitalRead(5));
//    // whether a alarm happened happened
//    Serial.print(" Alarm1: ");
//    Serial.println(rtc.alarmFired(1));
//   // using setAlarm1, the next alarm could now be configurated
//    if(rtc.alarmFired(1)) {
//        rtc.clearAlarm(1);
//        Serial.println("Alarm cleared");
//    }
   if(now.hour()==hh)
   {
    if(now.minute()==mm)
    {
      if(now.second()==ss)
       {
            rtc.writeSqwPinMode(DS3231_SquareWave1HZ);
            delay(500);
             rtc.writeSqwPinMode(DS3231_OFF);
          //  onAlarm();
        }
     }
   }
//    delay(1000);
}
//byte state=1;
void onAlarm() {
    state=!state;
    digitalWrite(13,state);
    
}

/*static uint8_t read_i2c_register(uint8_t addr, uint8_t reg) {
    Wire.beginTransmission(addr);
    Wire.write((byte)reg);
    Wire.endTransmission();

    Wire.requestFrom(addr, (byte)1);
    return Wire.read();
}*/
