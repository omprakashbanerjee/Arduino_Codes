#include<LiquidCrystal_I2C.h>
#include<Wire.h>
 LiquidCrystal_I2C lcd(0x27,16,2);
int b;
float x,y=0,a;
void setup()
{
  
   lcd.begin();
   lcd.backlight();
pinMode(A0,INPUT); 
Serial.begin(9600);
lcd.setCursor(0,0);
lcd.print("analog i/p " ) ;
lcd.setCursor(0,1);
lcd.print("AC voltage ");
}
void loop()
{
  b=analogRead(A0);
  x=(b* 0.304177);
delay(100);
if(y!=x)
{
lcd.setCursor(12,0);
lcd.print(b) ;

Serial.print(" analaog input " ) ; Serial.print(b) ;

a=x/sqrt(2);
Serial.print(" ac voltage= ") ; Serial.print(a) ; 
Serial.println();

lcd.setCursor(12,1);
lcd.print(a) ;
y=x;
}
else
delay(100);
}
