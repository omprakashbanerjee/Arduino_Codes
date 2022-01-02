#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup()
{
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
  lcd.clear();
 	lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("blank - message");
  //for third and fourth row position value should be  subtracted by4
  lcd.setCursor(-4,2);
  lcd.print("Hello, world!");
 lcd.setCursor(-4,3);
 lcd.print("omprakash banerG");
  
}

void loop()
{
	// Do nothing here...
}
