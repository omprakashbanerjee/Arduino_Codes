#include <Arduino.h>
// Motor

#define pwmA 5
#define in1A  6
#define in2A  7
#define c1A 2
#define c2A 3


// Motor Speed Values - Start at zero

int MotorSpeed1 = 0;
void setup()

{

  // Set all the motor control pins to outputs
 Serial.begin(9600);
  pinMode(pwmA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(c1A,INPUT);
  pinMode(c2A,INPUT);
}

void loop() {

   // Set Motor forward 
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);


  digitalWrite(c1A, LOW);
  digitalWrite(c2A, LOW);
  MotorSpeed1 =40;

  // Set the motor speeds


Serial.print(digitalRead(c1A));
Serial.println(digitalRead(c2A));
   
  
}
