#include <LiquidCrystal_I2C.h>
#include<Wire.h>  
LiquidCrystal_I2C lcd(0x27,16,2);
 
void setup(void) 
{
  lcd.begin();      
  lcd.setCursor(0, 0);
  lcd.print("Freq =");
  lcd.setCursor(0, 1);
  lcd.print("Peri =");
 
  // Timer1 module configuration
  TCCR1A = 0;
  TCCR1B = 2;   // enable Timer1 module with 1/8 prescaler ( 2 ticks every 1 us)
  TCNT1  = 0;   // Set Timer1 preload value to 0 (reset)
  TIMSK1 = 1;   // enable Timer1 overflow interrupt
 
  EIFR |= 1;  // clear INT0 flag
  attachInterrupt(0, timer1_get, FALLING);  // enable external interrupt (INT0)
}
 
uint16_t tmr1 = 0;
float period, frequency;
 
void timer1_get() {
  tmr1 = TCNT1;
  TCNT1  = 0;   // reset Timer1
}
 
ISR(TIMER1_OVF_vect) {  // Timer1 interrupt service routine (ISR)
  tmr1 = 0;
}
 
// main loop
void loop() 
{
  uint16_t value = tmr1;        // save current Timer1 value
  period = 8.0 * value/16000;   // calculate signal period in milliseconds  || 8.0 is Timer1 prescaler and 16000 = MCU_CLK/1000
   if(value == 0)              // calculate signal frequency which is = 1/period ; or = MCU_CLK/(Prescaler * Timer_Value)
   frequency = 0;               // aviod division by zero
  else
    frequency = 16000000.0/(8UL*value);
 
  lcd.setCursor(7, 0);
  lcd.print(frequency);
  lcd.print(" Hz  ");
  // print period
  lcd.setCursor(7, 1);
  lcd.print(period);
  lcd.print(" ms  ");
  delay(500);
 
}
