
// #include<Arduino.h>
// #include <AccelStepper.h>
// #include <TMC2208Stepper.h>

// // Define stepper motor connections and settings
// #define DIR_PIN PB5
// #define STEP_PIN PB6
// #define ENABLE_PIN PB7
// #define MICROSTEPS 16

// // Define TMC2208 driver connections
// #define SERIAL_PORT Serial1
// #define DRIVER_ADDRESS 0b00
// TMC2208Stepper driver(&SERIAL_PORT, DRIVER_ADDRESS);

// // Create AccelStepper object
// AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

// void setup() {
//   // Set up serial communication for TMC2208 driver
//   SERIAL_PORT.begin(115200);
  
//   // Set up TMC2208 driver
//   driver.begin();
//   driver.toff(3);           // Set off time to 3us
//   driver.rms_current(500);  // Set motor current to 500mA RMS
//   driver.microsteps(MICROSTEPS); // Set microSTEPg to 16
//   driver.en_pwm_mode(true); // Use spreadCycle instead of stealthChop
  
//   // Set up AccelStepper object
//   stepper.setMaxSpeed(1000);
//   stepper.setAcceleration(500);
//   stepper.setEnablePin(ENABLE_PIN);
//   stepper.enableOutputs();
// }

// void loop() {
//   // Move stepper motor forward and backward
//   stepper.moveTo(1000);
//   stepper.runToPosition();
//   stepper.moveTo(0);
//   stepper.runToPosition();
// }

//Include the Arduino Stepper Library
#include<Arduino.h>
#include <AccelStepper.h>
#define STM32

#ifdef STM32
#define DIR  PB9
#define STEP PB8
#else
#define DIR  5
#define STEP  6
#endif

#define motorInterfaceType 1
AccelStepper plateStepper(motorInterfaceType, STEP, DIR);

void setup() {
  Serial.begin(9600);
  plateStepper.setMaxSpeed(2000);
  plateStepper.setAcceleration(30);

}

void loop () {


  plateStepper.setSpeed(200);
  plateStepper.runSpeed();

}