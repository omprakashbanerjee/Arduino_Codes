#include <Keypad.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
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
String a[4]={"m1","m2","m3","m4"};
String m1[3]={"om","ritu","sonu"};
String m2[2]={"aa","bb"};
String m3[1]={"lll"};
String m4[4]={"ab","cd","ef","gh"}; 
void setup()
{ 
  lcd.begin();
  lcd.clear();
   lcd.setCursor(4,0);
  lcd.print("OM PRAKASH");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  Display();
}
  
void loop()
{
  char keyvalue=getkeyvalue.getKey();
  if(keyvalue)
  switch(keyvalue)
   {
  case'1':lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("open valve");
          break;
 case '2': lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("close valve");
          break;
 case'3':lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("invalid");
          break;
 case '4': lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("invalide");
          break;
 default:lcd.clear();
          Display();break;
  }
}
void Display()
{ for(i=0;i<=3;i++)
 { 
  lcd.setCursor(pos,0);
  lcd.print(a[i]);
  pos=pos+3;
}
pos=0;
  
  }
