#include"RTClib.h"

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
Ds3231SqwPinMode modes[] = { DS3231_OFF, DS3231_SquareWave1HZ, DS3231_SquareWave4kHz, DS3231_SquareWave8kHz, DS3231_SquareWave32kHz};

DateTime now;
void setup() {
  Serial.begin(57600);
  // put your setup code here, to run once:
 if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

}

void loop() {
   Ds3231SqwPinMode mode = rtc.readSqwPinMode();

  Serial.println(mode);
  now=rtc.now();
  Serial.print(now.hour());
  Serial.print(now.minute());
  Serial.println(now.second());
  rtc.writeSqwPinMode(DS3231_OFF);
delay(2000);
}
