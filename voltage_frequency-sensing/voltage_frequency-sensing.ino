#include "EmonLib.h"
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

EnergyMonitor emon1;
EnergyMonitor emon2;

const int relay1 = 9;
const int relay2 = 10;
const int relay3 = 8;
/*
uint16_t tmr1 = 0;
float period, frequency;

 void timer1_get() {
  tmr1 = TCNT1;
  TCNT1  = 0;   // reset Timer1
}
 
ISR(TIMER1_OVF_vect) {  // Timer1 interrupt service routine (ISR)
  tmr1 = 0;
}
 
*/
void setup()
{  
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  emon1.voltage(A0, 234.26, 1.7);
  emon2.voltage(A1, 234.26, 1.7);

  lcd.begin();     
 lcd.backlight();
 /* // Timer1 module configuration
  TCCR1A = 0;
  TCCR1B = 2;   // enable Timer1 module with 1/8 prescaler ( 2 ticks every 1 us)
  TCNT1  = 0;   // Set Timer1 preload value to 0 (reset)
  TIMSK1 = 1;   // enable Timer1 overflow interrupt
 
  EIFR |= 1;  // clear INT0 flag
  attachInterrupt(0, timer1_get, FALLING);  // enable external interrupt (INT0)

  
}
*/
void loop()
{
  emon1.calcVI(20,2000);
  emon1.serialprint();

  emon2.calcVI(20,2000);
  emon2.serialprint();
  
  float supplyVoltage1   = emon1.Vrms;             //extract Vrms into Variable
  float supplyVoltage2   = emon2.Vrms;
  
/*  uint16_t value = tmr1;        // save current Timer1 value
  period = 8.0 * value/16000;   // calculate signal period in milliseconds  || 8.0 is Timer1 prescaler and 16000 = MCU_CLK/1000
   if(value == 0)              // calculate signal frequency which is = 1/period ; or = MCU_CLK/(Prescaler * Timer_Value)
   frequency = 0;               // aviod division by zero
  else
    frequency = 16000000.0/(8UL*value);
*/
lcd.setCursor(0, 0);
  lcd.print("V1= ");
  lcd.setCursor(0, 1);
  lcd.print("V2= ");
  delay(500);
 

  if((supplyVoltage1 < 190.0 && supplyVoltage1 >243.0) && (supplyVoltage2 >190.0 && supplyVoltage2 < 243.0))
// primary out of range but secondary is inside the range then select secondary
  {
    digitalWrite(relay1, 0);  //to cut the connection of the relay1 ,means relay will switch from NC to NO
    digitalWrite(relay2, 0);  /*to make the connection on the relay2, relay2 will switch from NC to NO
    for relay2 our connection will be through NO ,so  when relay goes to NO then only line2 will be activated, for relay2 at NC there is nothing connected
                                        
    */
     digitalWrite(relay3, 0); //relay3 is master relay it needs a low signal to be in NO position then only any of the supply will be working
    lcd.setCursor(5,0);
    lcd.print(supplyVoltage1);
    lcd.setCursor(5,1);
    lcd.print(supplyVoltage2);
    lcd.setCursor(11,0);lcd.print("V2 on");
    delay(3000);// to check after each 3 seconds when switching is done
  }

  else if((supplyVoltage1 > 190.0 && supplyVoltage1 <243.0) && (supplyVoltage2 >190.0 && supplyVoltage2 < 243.0))
//both supplies are stable chose primary
  {   
    digitalWrite(relay1, 1);  //to keep the relay1 at NC position(line1)
     digitalWrite(relay2, 1);  //to keep the relay2 at NC position(neutral 1)
  digitalWrite(relay3, 0);//to keep the master relay at NO position
  lcd.setCursor(5,0);
    lcd.print(supplyVoltage1);
    lcd.setCursor(5,1);
    lcd.print(supplyVoltage2);
    lcd.setCursor(11,0);lcd.print("V1 on");
  }
  else if(supplyVoltage1 < 190.0 && supplyVoltage2 < 190.0)
    {  digitalWrite(relay1,1); //to keep the relay1 at NO position
       digitalWrite(relay2,1); //to keep the relay2 at NC position
    digitalWrite(relay3,1);
    lcd.setCursor(0,0);
    lcd.print("line unstable");
    lcd.setCursor(0,1);
    lcd.print("machine s/w off");
    delay(1000);   //to check the line stability after each 1 seconds
    }


  
}  
