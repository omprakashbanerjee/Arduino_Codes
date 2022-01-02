#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);


void setup()
{
  Serial.begin(9600);
  Serial.println("Stepper test!");
  // set the speed of the motor to 30 RPMs
//  stepper.setSpeed(40);
// Serial.println("Forward");
//  stepper.step(1.5*STEPS);
//  delay(1000);
//  Serial.println("Backward");
//  stepper.step(-1.5*STEPS);
//  delay(1000);

}

void loop()
{

 stepper.setSpeed(40);
 Serial.println("Forward");
  stepper.step(1.5*STEPS);
  delay(1000);
  Serial.println("Backward");
  stepper.step(-1.5*STEPS);
  delay(1000);
}
