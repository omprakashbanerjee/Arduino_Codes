#include <LCD5110_Graph.h>

LCD5110 myLCD(8,9,10,11,12);
extern unsigned char SmallFont[];
extern unsigned char TinyFont[];


void setup() {
 myLCD.InitLCD();
  myLCD.setFont(SmallFont);
  //randomSeed(analogRead(7));  // put your setup code here, to run once:
myLCD.clrScr();
  
}

void loop() { myLCD.update();
for (int i=0; i<8; i++)
  {
    myLCD.drawRoundRect(30, 10, 70, 0);
//myLCD.update();
  }
}
