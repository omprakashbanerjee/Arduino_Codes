#include<Arduino.h>
#define PIEZO PA0 // the analog pin connected to the sensor
//#define LED_BUILTIN  PC13 // pin connected to LED
#define THRESHOLD 100
void setup()
{
  Serial.begin(115200);
pinMode(LED_BUILTIN,OUTPUT);   // this function is used to declare led connected pin as output
}
void loop()
{
int value = analogRead(PIEZO);  // function to read analog voltage from sensor
if (value >= THRESHOLD)                    // function to check voltage level from sensor
{
//  Serial.print(value);
//  Serial.println(" knocked");
digitalWrite(LED_BUILTIN,LOW);
delay(1000); // to make the LED visible
}
else 
digitalWrite(LED_BUILTIN,HIGH);
}