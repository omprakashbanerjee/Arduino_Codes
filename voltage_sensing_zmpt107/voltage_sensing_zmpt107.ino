#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
  {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(A0,INPUT);
  lcd.clear();
}
uint8_t i,val,count,temp[100];

void loop(){
  for(i=0;i<=100;i++){
  val=analogRead(A0);
  
  Serial.println(val);
  if(val>=180 || val<=255){
  temp[i]=val;count++;
  delay(18);
  }
  else if(val<180)
  
  }
  delay(1000);
}
