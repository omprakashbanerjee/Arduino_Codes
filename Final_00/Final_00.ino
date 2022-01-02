#include "EmonLib.h"

EnergyMonitor emon1;
EnergyMonitor emon2;

const int relay1 = 9;
const int relay2 = 10;

uint16_t tmr1 = 0;
float period, frequency;

 void timer1_get() {
  tmr1 = TCNT1;
  TCNT1  = 0;   // reset Timer1
}
 
ISR(TIMER1_OVF_vect) {  // Timer1 interrupt service routine (ISR)
  tmr1 = 0;
}
 

void setup()
{  
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
  emon1.voltage(A0, 234.26, 1.7);
  emon2.voltage(A1, 234.26, 1.7);

  lcd.begin();     
 lcd.backlight();
  // Timer1 module configuration
  TCCR1A = 0;
  TCCR1B = 2;   // enable Timer1 module with 1/8 prescaler ( 2 ticks every 1 us)
  TCNT1  = 0;   // Set Timer1 preload value to 0 (reset)
  TIMSK1 = 1;   // enable Timer1 overflow interrupt
 
  EIFR |= 1;  // clear INT0 flag
  attachInterrupt(0, timer1_get, FALLING);  // enable external interrupt (INT0)

  
}

void loop()
{
  emon1.calcVI(20,2000);
  emon1.serialprint();

  emon2.calcVI(20,2000);
  emon2.serialprint();
  
  float supplyVoltage1   = emon1.Vrms;             //extract Vrms into Variable
  float supplyVoltage2   = emon2.Vrms;
  
  uint16_t value = tmr1;        // save current Timer1 value
  period = 8.0 * value/16000;   // calculate signal period in milliseconds  || 8.0 is Timer1 prescaler and 16000 = MCU_CLK/1000
   if(value == 0)              // calculate signal frequency which is = 1/period ; or = MCU_CLK/(Prescaler * Timer_Value)
   frequency = 0;               // aviod division by zero
  else
    frequency = 16000000.0/(8UL*value);

lcd.setCursor(0, 0);
  lcd.print("volt= ");
  lcd.setCursor(0, 1);
  lcd.print("Freq= ");
  lcd.setCursor(7, 1);
  lcd.print(frequency);
  lcd.print(" Hz  ");
  delay(500);
 

  if(supplyVoltage1 < 190.0 && (supplyVoltage2 >200 ||supplyVoltage2 < 240.0))
  {
    if(frequency>=46.0)
    {lcd.setCursor(7,0);
    lcd.print(supplyVoltage1);
    digitalWrite(relay1, 1);  //to switch relay NC to NO position
    delay(3000);
    }
  }

  else if(supplyVoltage1 > 190.0 && (supplyVoltage2 >200 || supplyVoltage2 < 240.0))

  {
    digitalWrite(relay1, 0);  //to keep the relay to NO position
  }
    else if(supplyVoltage1 < 190.0 && supplyVoltage2 < 190.0))
    {lcd.clear();
       digitalWrite(relay1,0); //to keep the relay to NO position
    lcd.setCursor(0,0);
    lcd.print("line unstable");
    lcd.setCursor(0,1);
    lcd.print("machine switched off");
     
    }


  
}  
