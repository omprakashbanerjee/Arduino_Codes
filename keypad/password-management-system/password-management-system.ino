#include <Keypad.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

unsigned int i,led1=11,alarm=12;

unsigned int wrong_count=0,count=0; 
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
LiquidCrystal_I2C lcd(0x27,16,2); 


char pass[4]={'1','2','3','4'};
char arr[16];
uint8_t pos=0;

void setup(){
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(alarm,OUTPUT);
  lcd.setCursor(0,0);
  home_display();
  
 }
 void home_display(){lcd.clear();
              lcd.setCursor(0,0);
              Serial.println("enter password");
              lcd.print("enter password");
              lcd.setCursor(0,1);
              count=0;wrong_count=0;pos=0;
              
            }

void loop()
{
   char keyvalue=getkeyvalue.getKey();
   if(keyvalue){
    switch(keyvalue){
   case '1':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '2':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '3':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '4':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '5':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '6':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '7':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '8':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '9':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '0':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '*':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case '#':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case 'A':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case 'B':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case 'C':arr[pos]=keyvalue;  Serial.print(keyvalue); lcd.setCursor(pos,1);pos++; lcd.print("*"); break;
   case 'D':check();break;
   default:break;
   }
}
}
void check(){
  if(sizeof(pass)==pos){
  for(i=0;i<pos;i++)
  { if(arr[i]==pass[i])
    count++;
    else wrong_count++;
   }
            if(count==4){
              lcd.clear();
              lcd.setCursor(0,0);
            lcd.print("    success    ");
            Serial.println("success");
            digitalWrite(led1,1);
            digitalWrite(alarm,0);
            delay(5000);
            digitalWrite(led1,0);
            home_display();
            }
            else if(wrong_count>0)
            { lcd.clear();
              lcd.setCursor(0,0);
            lcd.print("    failed   ");
              digitalWrite(alarm,1);
            digitalWrite(led1,0);
            Serial.println("failed");delay(5000);
            digitalWrite(alarm,0);
             home_display();
            }
         }
         else{
          lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("error");
         Serial.println("error");
         digitalWrite(alarm,1);
         digitalWrite(led1,0);
         delay(5000);
         digitalWrite(alarm,0);
          home_display();
        }
 }
