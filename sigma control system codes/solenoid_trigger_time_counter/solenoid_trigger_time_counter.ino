#include<LiquidCrystal_I2C.h>
#define columns 16
#define lines 4
#define I2C_ADDR 0x27
LiquidCrystal_I2C lcd(I2C_ADDR,columns,lines);
#define redWire 2
#define greenWire 3
//#define button1 4
//#define button2 5
bool trigger_need=true;
unsigned long currentTime=0,prevTime=0;
uint8_t count_on=15;
uint8_t count_off=10;
uint8_t count;
//byte state=1;
int pin=redWire;
void trigger(int pin);
void setup() {
  //Serial.begin(9600);
  lcd.begin();lcd.clear();
pinMode(greenWire,OUTPUT);
pinMode(redWire,OUTPUT);
//pinMode(button1,INPUT_PULLUP);
//pinMode(button2,INPUT_PULLUP);
}

void loop(void)
{
 if(trigger_need){
  if(pin==greenWire) {  pin=redWire;lcd.home();   lcd.print("OFF");   count=count_off;}
  else { pin=greenWire; lcd.home();lcd.print("ON ");count=count_on;}
  trigger(pin);
 }
 else
 {
    currentTime=millis();
    if(currentTime-prevTime>=1000)
    { lcd.setCursor(5,0);
      lcd.print(count); 
      count--;
      if(count==0) trigger_need=true;
      prevTime=currentTime;
     }
 }
}
void trigger(int pin){
//   lcd.setCursor(-4,3);
   unsigned long startTime=millis();
   digitalWrite(pin,1);
  while(millis()-startTime<35)
    {
//      Serial.print(pin);
//      Serial.println(" triggered"); 
      }
  digitalWrite(pin,0);trigger_need=false;
}
