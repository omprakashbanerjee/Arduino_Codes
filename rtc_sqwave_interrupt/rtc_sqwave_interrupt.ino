#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

const byte rtcTimerIntPin = 2;

volatile byte flag = false;

void rtc_interrupt ()
{
  flag = true;
}  // end of rtc_interrupt

void setup () {

  Serial.begin(115200);

  while (!Serial); // for Leonardo/Micro/Zero

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // enable the 1 Hz output
  rtc.writeSqwPinMode (DS3231_SquareWave1Hz);

  // set up to handle interrupt from 1 Hz pin
  pinMode (LED_BUILTIN, OUTPUT);
  pinMode (rtcTimerIntPin, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (rtcTimerIntPin), rtc_interrupt, CHANGE);
}

void loop () {
  if (flag) {
    digitalWrite(LED_BUILTIN, HIGH);    // flash the led
    delay(100);                         // wait a little bit
    digitalWrite(LED_BUILTIN, LOW);     // turn off led
    flag =  false;                      // clear the flag until timer sets it again
  }
}
