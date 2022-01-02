#include<Servo.h>

//Servo myservo;
void setup() {
  Serial.begin(9600);
 // myservo.attach(9);
  
}
int val;
//String data_recvd="hello";
void loop() {
if(Serial.available())
{
 val=Serial.read();
}
Serial.println(val);
 delay(200);
}
