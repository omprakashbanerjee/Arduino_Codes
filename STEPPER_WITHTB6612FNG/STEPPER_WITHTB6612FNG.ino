#include <Arduino.h>
// Motor


#define in1A  4
#define in2A  5


#define in1B  6
#define in2B  7



// Motor Speed Values - Start at zero

int MotorSpeed1 = 0;
int MotorSpeed2= 0;
void setup()

{

  // Set all the motor control pins to outputs
 Serial.begin(9600);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
 

}

void loop() {
  Serial.println("forward");
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);

  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);

delay(2000);
Serial.println("backward");

  digitalWrite(in2A, HIGH);
  digitalWrite(in1A, LOW);

  digitalWrite(in2B, HIGH);
  digitalWrite(in1B, LOW);

delay(2000);
  
}
