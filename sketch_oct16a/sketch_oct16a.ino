#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
lcd.begin();
lcd.backlight();
// put your setup code here, to run once:

}

void loop() {
  lcd.setCursor(0,0);lcd.scrollDisplayLeft();
  
  lcd.print("om prakash banerjee");//delay(300);
  lcd.setCursor(0,1);
  lcd.scrollDisplayLeft();
   
  lcd.print("hello world how are you");
  delay(400);
   lcd.setCursor(0,0);
   lcd.scrollDisplayRight();
  
  lcd.print("om prakash banerjee");//delay(300);
  lcd.setCursor(0,1);
   
  lcd.print("hello world how are you");
  delay(400);
  // put your main code here, to run repeatedly:

}
