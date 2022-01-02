#include <Keypad.h>
//#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define column 16
#define line 2
#define I2C_ADDR 0x27 //I2C adress, you should use the code to scan the adress first (0x27) here
/*
#define BACKLIGHT_PIN 3 // Declaring LCD Pins
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
*/
LiquidCrystal_I2C lcd(I2C_ADDR,column,line);

int interval = 1000;


unsigned long previousMillis = 0;
unsigned long currentMillis;  

int ledState = LOW; 

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};  //connect to the column pinouts of the keypad




Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup()
{
  pinMode(13, OUTPUT);
  lcd.begin ();
//  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  //lcd.setBacklight(HIGH); //Lighting backlight
  lcd.home ();  
  pinMode(2, INPUT);
                   
}




void loop()
{
   char key = kpd.getKey();
  
   if(key == 'A'){
   lcd.clear();
   interval = GetNumber();
   blnk();
   }

   else
   {
    lcd.home();
    lcd.print(interval);
    blnk();
   }
   
}




void blnk(){
   currentMillis = millis();
   if (currentMillis - previousMillis >= interval) 
   {
    previousMillis = currentMillis;
   if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(13, ledState);
   }
   
   
} 

int GetNumber()
{
   int num = 0;
   char key = kpd.getKey();
   while(key != '#')
   {
      switch (key)
      {
         case NO_KEY:
            break;

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
            lcd.print(key);
            num = num * 10 + (key - '0');
            break;

         case '*':
            num = 0;
            lcd.clear();
            break;
      }

      key = kpd.getKey();
   }

   return num;
}
