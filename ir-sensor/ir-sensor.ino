#include<LiquidCrystal_I2C.h>

#include<Wire.h>
uint8_t ir1=12,ir2=11,ir1_val1,ir2_val2,count=0;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.begin();
Serial.begin(9600);
pinMode(ir1,INPUT);  
pinMode(ir2,INPUT);
lcd.clear();  
lcd.setCursor(0,0);
lcd.print("count= ");
}

void loop() {
  ir1_val1=digitalRead(ir1);
 if(ir1_val1==0)
 {delay(100);
  ir2_val2=digitalRead(ir2);
  if(ir2_val2==0)
  { count++;
  lcd.setCursor(8,0);
    lcd.print(count);delay(500);
  }
 }
 else if(digitalRead(ir2)==0){
      if(count==0){
      count=0;
      lcd.setCursor(8,0);
     lcd.print(count);
      }
      else{
        count--;
      lcd.setCursor(8,0);
     lcd.print(count);delay(300);
 }
}
}
