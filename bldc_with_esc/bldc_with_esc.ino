#include<Servo.h>
Servo myservo;

void setup() {
Serial.begin(9600);
myservo.attach(3);
myservo.write(1000);
delay(3000);
}

void loop() {
  int val=90;
  Serial.println(val);
  myservo.write(val);
}
