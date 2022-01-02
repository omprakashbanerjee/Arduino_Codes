#include<LiquidCrystal_I2C.h>
#define columns 16
#define lines 2
#define I2C_ADDR 0x27
LiquidCrystal_I2C lcd(I2C_ADDR,columns,lines);
uint8_t  hr=9,mi=50,sec=15;
void setup() { 
  lcd.begin();
  lcd.home();
  char date[10] = "hh:mm:ss";
for(int i=0;i<=10;i++)
{} }

void loop() {

}
