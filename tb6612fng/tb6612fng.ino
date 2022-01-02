#include <Arduino.h>
// Motor

#define pwmA 5
#define in1A  6
#define in2A  7
#define c1A 2
#define c2A 3

#define in1B  8
#define in2B  9
#define pwmB 10
#define c1B 11
#define c2B 12



// Motor Speed Values - Start at zero

int MotorSpeed1 = 0;
int MotorSpeed2= 0;
void setup()

{

  // Set all the motor control pins to outputs
 Serial.begin(9600);
  pinMode(pwmA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(c1A,INPUT);
  pinMode(c2A,INPUT);

  pinMode(pwmB, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(c1B,INPUT);
  pinMode(c2B,INPUT);
   // Set Motor forward 
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);

  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);


  digitalWrite(c1A, LOW);
  digitalWrite(c2A, LOW);

  digitalWrite(c1B, LOW);
  digitalWrite(c2B, LOW);
  MotorSpeed1 =200;
  MotorSpeed2= 100;
  // Set the motor speeds


  analogWrite(pwmA, MotorSpeed1); 
  analogWrite(pwmB, MotorSpeed2);

}

void loop() {
  
Serial.print(digitalRead(c1A));
Serial.println(digitalRead(c2A));

 
Serial.print(digitalRead(c1B));
Serial.println(digitalRead(c2B));
       
  
}
