/*below code takes just 166 bytes
 * #include<avr/io.h>
#include<util/delay.h>
int main(void)
{
DDRB |=(1<<PB4)|(1<<PB5);

while(1){
PORTB ^= (1<<PB4)|(1<<PB5);
_delay_ms(1000);
}
}
*/
//now this code below takes 606 bytes
void setup(){
  DDRB |=(1<<PB4)|(1<<PB5);
  }
  void loop()
  {
 PORTB ^= (1<<PB4)|(1<<PB5);
delay(1000);
  }
