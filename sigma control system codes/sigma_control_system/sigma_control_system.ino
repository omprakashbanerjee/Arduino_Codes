#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

#define columns 16
#define lines 2
#define I2C_ADDR 0x27
#define led1 2
#define led2 13
LiquidCrystal_I2C lcd(I2C_ADDR,columns,lines);
DateTime now;
RTC_DS3231 rtc;
char key;
int yr = 0;
int mnth = 0;
int dt = 0;
int CycleStartHour=15;
int CycleStartMinute=57;
int CycleStartSec=57;

int hh = 0;
int mm = 0;
int ss = 0;

int OnTime = 500UL;
int OffTime=1000UL;

unsigned long previousMillis = 0;
unsigned long currentMillis; 

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

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void  set_On_Off_time(void);
void showDate(void);
void showTime(void);
void showDay(void);
void settime(void);
void setdate(void);
void setCycleStartTime(void);
void setup(){
  Serial.begin(9600); //Serial used
  lcd.begin();
  //lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
 // lcd.noBacklight(); //Lighting backlight
  //lcd.home ();   
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  

  if (! rtc.begin()) 
  {
    lcd.println("Couldn't find RTC");
    while (1);
  }

//  if (rtc.lostPower()) 
//  {
//    lcd.println("RTC lost power");
//    
//  } 

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
      case 'A': setCycleStartTime(); break;
      case '1':
            settime();
            break;
      case '2':
            setdate();
            break;
      case 'B':
            set_On_Off_time();
            break;
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
  if(now.hour()==CycleStartHour && now.minute()==CycleStartMinute && now.second()==CycleStartSec)
  {
  startCycle();
  }
}

void set_On_Off_time(){
 lcd.clear();
 lcd.home();
 lcd.print("set Ontime:");
 OnTime=GetNumber();
            
 lcd.clear();
 lcd.home();
 lcd.print("set Offtime:");
 OffTime=GetNumber();
 lcd.clear();   
}
void setCycleStartTime(){
  lcd.clear();
   lcd.home();
   lcd.print("start_hour:");
   CycleStartHour = GetNumber();

   lcd.clear();
   lcd.home();
   lcd.print("start_min:");
   CycleStartMinute = GetNumber();

   lcd.clear();
   lcd.home();
   lcd.print("start_sec:");
   CycleStartSec = GetNumber();
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
void startCycle(){
   digitalWrite(13,1);
    do{
      now = rtc.now();
  showDate();
  showTime();
    Serial.println("inside cycle");
    char key=kpd.getKey();
   } while(key != 'D');
}
