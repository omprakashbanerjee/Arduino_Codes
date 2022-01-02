#include <Stepper.h>
const float steps_per_rev=32;
const  float gear_red=64;
const float steps_per_out_rev=steps_per_rev*gear_red;
int steps_req;
Stepper steppermotor(steps_per_rev,8,10,9,11);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
 /* steppermotor.setSpeed(1);
  steps_req=4;
  steppermotor.step(steps_req);
  delay(2000);
  */
  steppermotor.setSpeed(500);
//  steps_req=steps_per_out_rev/2;
  steppermotor.step(100);
  delay(1000);
/*
  steps_req=-steps_per_out_rev/2;
  steppermotor.setSpeed(500);
  steps_req=4;
  steppermotor.step(-2048);
  delay(2000);
*/
}
