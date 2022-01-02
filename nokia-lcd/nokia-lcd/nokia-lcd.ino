#include <LCD5110_Graph.h>

LCD5110 myLCD(8,9,10,11,12);

void setup() {
 myLCD.InitLCD();
//  myLCD.setFont(SmallFont);
  //randomSeed(analogRead(7));  // put your setup code here, to run once:
myGLCD.clrScr();
  
}

void loop() {myLCD.print("LCD5110_Graph", CENTER, 0);
  
  // put your main code here, to run repeatedly:

}
