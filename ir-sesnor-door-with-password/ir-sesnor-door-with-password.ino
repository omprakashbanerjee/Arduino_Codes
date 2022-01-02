#include<Servo.h>
Servo myservo;
#include <Keypad.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

unsigned int ir1=11,ir2=12,ir1_val1,ir2_val2,i,entry_count=0;

unsigned int wrong_count=0,count=0;                                               //keyboard part start
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

Keypad getkeyvalue = Keypad(makeKeymap(mykeypad), rowPins, colPins, ROWS, COLS);  //keyboard part end here
LiquidCrystal_I2C lcd(0x27,16,2); 


char pass[4]={'1','2','3','4'};       //passwoord defined here
char arr[16];               //another array for storing input password
uint8_t pos=0;

void setup(){
  myservo.attach(10);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
   myservo.write(20);
   home_screen();
  
 }

void home_screen()
{while(1){lcd.clear();
  count=0;wrong_count=0;pos=0;
   ir1_val1=digitalRead(ir1);
 if(ir1_val1==0){
  delay(100);
  ir2_val2=digitalRead(ir2);
  if(ir2_val2==0){entry_count++;
  if(entry_count==1){
    lcd.clear();
              lcd.setCursor(0,0);
             lcd.print("enter password");
              lcd.setCursor(0,1);
          password();
  }
 }
}
 else if(digitalRead(ir2)==0){delay(100); if(digitalRead(ir1)==0){
      if(entry_count==0){
      entry_count=0;
      lcd.clear();
      lcd.setCursor(0,0);
     lcd.print("intruder");delay(500);lcd.clear();
      }
      else{
        entry_count--;
        lcd.clear();
      lcd.setCursor(0,0);
     lcd.print("see you");delay(500);lcd.clear();
      }
   }
}
}
}
void loop(){}
void password(){while(1){
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
            lcd.print("    welcome    ");
            myservo.write(90);
            delay(3000);
            myservo.write(20);home_screen();
            }
            else if(wrong_count>0)
            { lcd.clear();
              lcd.setCursor(0,0);
            lcd.print("    wrong key   ");
              myservo.write(20);
              delay(500);home_screen();
            }
         }
         else{
          lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("error");
         delay(500);home_screen();
        }
 }
