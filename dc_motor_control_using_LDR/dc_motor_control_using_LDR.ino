//program to control dc motor with LDR
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

uint8_t motor1=10,  motor2=11,  LDR=A0, LDR_val, btn=2, btn_val;


void setup() {
  Serial.begin();
  lcd.begin();
  lcd.backlight();
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(LDR,INPUT);
pinMode(btn,INPUT);
lcd.clear();
lcd.setCursor(0,0);
}

void loop() {
  LDR_val=analogRead(A0);
  if(LDR_val>400)
  {
    analogWrite(motor1,127);
    digitalWrite(motor2,0);
  }
  else if(LDR_val>600)
  {
    digitalWrite(motor1,1);
    digitalWrite(motor2,0);
  }
  
}
