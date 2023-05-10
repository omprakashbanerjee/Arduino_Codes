#ifndef UTILS_H
#define UTILS_H

#define DEBUG
 #define STM32

/* PARAMETERS */
#define MAXSPEED 3000
#define ACCELERATION 3000
#define LONG_DURATION 800000UL //(500 * 16) * 1); // ==> 200 for the stepper's original steps/revolution, 16 is the microsteps and 1 is the number of turns
/* END PARAMETERS */

/* PINS */
#ifdef STM32
#define EN_PIN PB4     // LOW: Driver enabled. HIGH: Driver disabled
#define STEP_PIN PB3      // Step on rising edge
#define DIR_PIN PA15
#define LIMITSWITCH1_PIN PB15
#define LIMITSWITCH2_PIN PB14

// #define EN_PIN PB9     // LOW: Driver enabled. HIGH: Driver disabled
// #define STEP_PIN PB8      // Step on rising edge
// #define DIR_PIN PB5
// #define LIMITSWITCH1_PIN PB12
// #define LIMITSWITCH2_PIN PB13


#else
#define EN_PIN 13     // LOW: Driver enabled. HIGH: Driver disabled
#define STEP_PIN 7      // Step on rising edge
#define DIR_PIN 6
#define LIMITSWITCH1_PIN 3
#define LIMITSWITCH2_PIN 8
#endif
/* END PINS */

/* LIBRARY INCLUDES */
#include <TMC2208Stepper.h>
#include <AccelStepper.h>
/* END LIBRARY INCLUDES */

/* GLOBAL VARIABLES */
TMC2208Stepper driver = TMC2208Stepper(&Serial);
AccelStepper stepper(1, STEP_PIN, DIR_PIN);

enum Direction {
  OUTWARDS = -1,
  INWARDS = 1
};

enum State {
  MOVE = 1,
  STOP,
  IDLE
};

enum Command {
  COMMAND_MOVE_OUT = 1,
  COMMAND_MOVE_IN,
  COMMAND_STOP,
  COMMAND_IDLE
};

// STATE -----------------------
volatile State  motor_state        = STOP;
volatile Direction motor_direction = OUTWARDS;
// -----------------------------

long freespace = -1;
/* END GLOBAL VARIABLES */

#endif
