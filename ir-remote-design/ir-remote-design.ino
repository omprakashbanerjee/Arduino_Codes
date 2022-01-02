/*this program is to design ir remote using arduino
attach the ir led to arduino uno pin 3 only not other pins
as interrupt is only available in pin3

*/
#include<IRremote.h>
const int switchPin=7;
int buttonState=0;
IRsend irsend; //create irsend object
void setup() {
  pinMode(switchPin,INPUT);
}

void loop() {
  //set buttonstate depending upon the switch position
  buttonState=digitalRead(switchPin);
  //if button is presssed send power command
  if(buttonState=HIGH){
    irsend.sendNEC(0xFEA857,32); //CHANGE this hex code according to required remote or appliance
    }
    delay(200);//for debouncing the push button
}
