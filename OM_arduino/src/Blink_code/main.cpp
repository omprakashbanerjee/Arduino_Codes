#include<Arduino.h>

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(PB15,INPUT);
}

void loop(){
    if(digitalRead(PB15))
    digitalWrite(LED_BUILTIN,LOW);
  //  delay(100);
  else
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
}
    