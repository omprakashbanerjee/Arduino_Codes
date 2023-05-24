
#include<Arduino.h>
#include"Motor_setup.h"

void limitswitch_ISR()
{ 
 stepper.setCurrentPosition(0);
 stepper.stop(); // Stop as fast as possible: sets new target
 stepper.runToPosition(); 

}
void driver_setup();
void setup() {
  // Set up serial communication for TMC2208 driver
  SERIAL_PORT.begin(115200);
  driver_setup();
  
  attachInterrupt(digitalPinToInterrupt(LIMITSWITCH_PIN0), limitswitch_ISR, RISING);
 // attachInterrupt(digitalPinToInterrupt(LIMITSWITCH_PIN1), limitswitch_ISR, RISING);
  
  
  // Set up TMC2208 driver
 stepper.moveTo(-XmaxPos);
 stepper.runToPosition();
//  stepper.moveTo(XmaxPos);
//  stepper.runToPosition();

//  stepper.moveTo(-YmaxPos);
//  stepper.runToPosition();
//  stepper.moveTo(YmaxPos);
//  stepper.runToPosition();

}

void loop() {
  // Move stepper motor forward and backward
 
//  stepper.moveTo(0);
//  stepper.runToPosition();

//Blocking calls

//  stepper.runToNewPosition(0);
//  stepper.runToNewPosition(500);
//  stepper.runToNewPosition(100);
//  stepper.runToNewPosition(120);



}
