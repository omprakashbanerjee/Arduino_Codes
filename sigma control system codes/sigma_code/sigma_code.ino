#include<EEPROM.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#define redWire 2
#define greenWire 3
#define columns 16
#define lines 4
#define I2C_ADDR 0x27
#define lcd_power 12
LiquidCrystal_I2C lcd(I2C_ADDR,columns,lines);
DateTime now;
RTC_DS3231 rtc;
char key;
int yr = 0;
int mnth = 0;
int dt = 0;
int hh = 0;
int mm = 0;
int ss = 0;


uint8_t CycleStartHour;
uint8_t CycleStartMinute;
uint8_t CycleStartSec;
bool trigger_need=true;
bool alarm_not_triggered=true;
int pin=redWire;

uint16_t savedPassword;
uint16_t OnTimeMIN,OnTimeHR,OffTimeHR,OffTimeMIN;
uint16_t OnTime ;
uint16_t OffTime;
uint16_t CurrentOntime;
uint16_t CurrentOfftime;
uint16_t count;
unsigned long currentTime=0,prevTime=0;
uint8_t MSB,LSB;

uint8_t previousMillis = 0;
uint8_t currentMillis; 

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {11,10,9,8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7,6,5,4}; //connect to the column pinouts of the keypad

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void  set_On_Off_time(void);
void showDate();
void startCycle();
void showTime();
void showDay();
void settime();
void setdate();
void setCycleStartTime();
int GetNumber();
void trigger(int pin);
void alarmcheck();


void setup(){
  lcd.begin();
  lcd.home ();   
  pinMode(greenWire,OUTPUT);
  pinMode(redWire,OUTPUT);
  pinMode(lcd_power,OUTPUT);
EEPROM.get(26,MSB);
EEPROM.get(25,LSB);
uint16_t savedPassword=(MSB<<8)|LSB;

EEPROM.get(10,CycleStartHour);
EEPROM.get(12,CycleStartMinute);
EEPROM.get(14,CycleStartSec);

EEPROM.get(6,MSB);
EEPROM.get(5,LSB);
uint16_t CurrentOfftime=(MSB<<8)|LSB;

EEPROM.get(1,MSB);
EEPROM.get(0,LSB);
uint16_t CurrentOntime=(MSB<<8)|LSB;

  lcd.print("SIGMA");
  lcd.setCursor(4,1);
  lcd.print("CONTROL");
  lcd.setCursor(4,2);
  lcd.print("SYSTEM");
 delay(2000);lcd.clear();
  if (! rtc.begin()) 
  {
    lcd.println("Couldn't find RTC");
    while (1);
  }
}

void loop()
  {
  key = kpd.getKey();
  if(key)
  { 
    switch(key)
    {
      case NO_KEY:
                  break;
      case 'A': if(checkPassword()){setCycleStartTime(); break;}
        else break;
      case '1':if(checkPassword()){settime();break;}
              else break;
      case '2':if(checkPassword()){setdate();break;}
            else break;
      case 'B':if(checkPassword()){set_On_Off_time(); break;}
            else break;
       case 'C':if(checkPassword()) {changePassword();break;}
          else break;     
      case 'D':lcd.clear();
            now = rtc.now();
            showDate();
            showTime();
            break;  
   }
  }

  now = rtc.now();
  showDate();
  showTime();
 if(alarm_not_triggered) alarmcheck();
 
if(trigger_need){
  if(pin==greenWire) {  pin=redWire;lcd.setCursor(-4,2);    lcd.print("OFF");   count=CurrentOfftime;}
  else { pin=greenWire; lcd.setCursor(-4,2);  lcd.print("ON ");   count=CurrentOntime;}
  trigger(pin);
 }
 else
 {
    currentTime=millis();
    if(currentTime-prevTime>=1000)
    { lcd.setCursor(1,2);
      lcd.print(count);lcd.print(" ");count--;
      if(count==0) 
      { 
        trigger_need=true;
      }
      prevTime=currentTime;
     }
 }
currentMillis=millis()/1000;
if(currentMillis-previousMillis>=10)
 {
  uint8_t battery=analogRead(A0)/10;
  lcd.setCursor(-4,3); lcd.print(battery);lcd.print(" % battery");
  previousMillis=currentMillis;
 }
}
void changePassword(){
      lcd.home();lcd.print("new password");
      lcd.setCursor(0,1);  
      savedPassword=(uint16_t)GetNumber();lcd.clear();
      EEPROM.update(25,savedPassword);
      EEPROM.update(26,savedPassword>>8);
}

bool checkPassword(){
lcd.clear();
lcd.home();lcd.print("enter password:");
lcd.setCursor(-4,2);
  uint16_t enteredPassword=(uint16_t)GetNumber();
  if(enteredPassword==savedPassword) return true;
  else {lcd.clear();return false;}

}
void alarmcheck(){
  if(now.hour()==CycleStartHour && now.minute()==CycleStartMinute && now.second()==CycleStartSec)
  { alarm_not_triggered=false;
    trigger_need=true;
    CurrentOntime=OnTime;
     EEPROM.update(0,CurrentOntime);
      EEPROM.update(1,CurrentOntime>>8);
    
    CurrentOfftime=OffTime;
     EEPROM.update(5,CurrentOfftime);
      EEPROM.update(6,CurrentOfftime>>8);
    
    pin=redWire;
  }
  else alarm_not_triggered=true;
}

void set_On_Off_time(){
 lcd.clear();
 lcd.home();
 lcd.print("Ontime_Hour:");
 OnTimeHR=(uint16_t)GetNumber();

  lcd.clear();
 lcd.home();
 lcd.print("Ontime_min:");
 OnTimeMIN=(uint16_t)GetNumber();

  lcd.clear();
 lcd.home();
 lcd.print("Ontime_sec:");
 OnTime=(OnTimeHR*60*60)+(OnTimeMIN*60)+(uint16_t)GetNumber();
            
 lcd.clear();
 lcd.home();
 lcd.print("Offtime_Hour:");
 OffTimeHR=60*60*(uint16_t)GetNumber();
 lcd.clear();   
 
 lcd.home();
 lcd.print("Offtime_min:");
 OffTimeMIN=60*(uint16_t)GetNumber();
 lcd.clear();   

 lcd.home();
 lcd.print("Offtime_sec:");
 OffTime=(uint16_t)GetNumber()+ OffTimeMIN + OffTimeHR;
 lcd.clear();   
}

void setCycleStartTime(){
  lcd.clear();
   lcd.home();
   lcd.print("start_hour:");
   CycleStartHour =(uint8_t) GetNumber(); EEPROM.update(10,CycleStartHour);

   lcd.clear();
   lcd.home();
   lcd.print("start_min:");
   CycleStartMinute =(uint8_t) GetNumber(); EEPROM.update(12,CycleStartMinute);

   lcd.clear();
   lcd.home();
   lcd.print("start_sec:");
   CycleStartSec = (uint8_t)GetNumber(); EEPROM.update(14,CycleStartSec);
   lcd.clear();
}

int GetNumber(){
   int num = 0;
   char key = kpd.getKey();
   while(key != 'D')
   {
      switch (key)
      {
         case NO_KEY:
            break;

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
            //lcd.home();
            lcd.print(key);
            num = num * 10 + (key - '0');
            break;

         case '*':
            num = 0;
            lcd.clear();
            lcd.home();
            break;
      }

      key = kpd.getKey();
   }

   return num;
}

void showDate(){
  lcd.setCursor(0,0);
  //lcd.print("Date:");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());
 }

 void showTime(){
  lcd.setCursor(0,1);
  //lcd.print("Time:> ");
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());
  lcd.print("    ");
} 

void setdate(){ 
  lcd.clear();
  lcd.home();
  lcd.print("set year: ");
  yr = GetNumber();                
  lcd.clear();
  lcd.home();
  lcd.print("set month: ");
  mnth = GetNumber();
  lcd.clear();
  lcd.home();
  lcd.print("set date: ");
  dt = GetNumber();
  lcd.clear();
  rtc.adjust(DateTime(yr, mnth, dt, now.hour(),now.minute(),now.second()));
}

void settime(){
    lcd.clear();
  lcd.home();
  lcd.print("set hour: ");
  hh = GetNumber();                 
  lcd.clear();
  lcd.home();
  lcd.print("set min: ");
  mm = GetNumber();
  lcd.clear();
  lcd.home();
  lcd.print("set sec: ");
  ss = GetNumber();
  lcd.clear();
  rtc.adjust(DateTime(now.year(),now.month(),now.day(), hh, mm, ss));
}

void trigger(int pin){
 
   unsigned long startTime=millis();
   digitalWrite(pin,1);
  while(millis()-startTime<35)
    { }
  digitalWrite(pin,0);trigger_need=false;
}
