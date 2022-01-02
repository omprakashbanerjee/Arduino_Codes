#include "RTClib.h"


#include <Keypad.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27,16,2);
uint8_t i,pos=0;
const byte ROWS = 4; 
const byte COLS = 4; 

char mykeypad[ROWS][COLS] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad getkeyvalue = Keypad(makeKeymap(mykeypad), rowPins, colPins, ROWS, COLS); 

char yr[4];
char date[2],mnth[2],hh[2],mm[2],ss[2];
void setup()
{ 
  lcd.begin();
  lcd.clear();
   lcd.setCursor(4,0);
  lcd.print("OM PRAKASH");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  settime();
}
  void loop(){}
void settime()
{
lcd.setCursor(0,0);
lcd.print("enter YEAR");
lcd.setCursor(0,1);
 
  for(i=0;i<3;i++)
  {  while(!getkeyvalue.getKey());
  char yr[i]=getkeyvalue.getKey();
 lcd.print(yr);
 }
}
