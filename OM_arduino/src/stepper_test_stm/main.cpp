#include<Arduino.h>
#include <AccelStepper.h>
#include <TMC2208Stepper.h>

// Define stepper motor connections and settings

#define DIR_PIN PA15
#define STEP_PIN PB3
#define ENABLE_PIN PB4
#define maxPos 26500

// #define DIR_PIN PB5
// #define STEP_PIN PB8
// #define ENABLE_PIN PB9
// #define maxPos 40000


#define MICROSTEPS 16

// Define TMC2208 driver connections
#define SERIAL_PORT Serial1
#define DRIVER_ADDRESS 0b00
TMC2208Stepper driver(&SERIAL_PORT, DRIVER_ADDRESS);

// Create AccelStepper object
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  // Set up serial communication for TMC2208 driver
  SERIAL_PORT.begin(115200);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  
  // Set up TMC2208 driver
  digitalWrite(ENABLE_PIN, HIGH);
  driver.pdn_disable(1);              // Use PDN/UART pin for communication
  driver.mstep_reg_select(1);   // TRYING TO SET THE MICROSTEPS LIKE THIS, BUT TO NO AVAIL!!
  driver.microsteps(0);
  driver.I_scale_analog(0);           // Adjust current from the registers
  driver.rms_current(500);            // Set driver current 500mA
  driver.toff(0x2);  
  digitalWrite(ENABLE_PIN, LOW);
  
  // Set up AccelStepper object
  stepper.setMaxSpeed(5000);
  stepper.setAcceleration(500);
//   stepper.setEnablePin(ENABLE_PIN);
//   stepper.enableOutputs();
}

void loop() {
  // Move stepper motor forward and backward
 stepper.moveTo(maxPos);
 stepper.runToPosition();
 stepper.moveTo(0);
 stepper.runToPosition();


}
