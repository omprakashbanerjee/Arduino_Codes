#include<LiquidCrystal_I2C.h>
#include<Wire.h>
//LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
 LiquidCrystal_I2C lcd(0x27,16,2);
void setup(void) {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);      
  lcd.setCursor(0, 0);
  lcd.print("RMS Voltage:");
 analogReference(INTERNAL);  // set ADC positive reference voltage to 1.1V (internal)
}
 
// get maximum reading value
uint16_t get_max() 
{ lcd.clear();
  uint16_t max_v = 0;
  for(uint8_t i = 0; i < 100; i++) 
  {
    uint16_t r = analogRead(A3);  // read from analog channel 3 (A3)
    if(max_v < r) max_v = r;
    delayMicroseconds(200);
  }
  return max_v;
}
 
void loop() {
 
  char buf[10];
  // get amplitude (maximum - or peak value)
  uint32_t v = get_max();
  // get actual voltage (ADC voltage reference = 1.1V)
  v = v *1100/1023;
  // calculate the RMS value ( = peak/√2 )
  v =v/ sqrt(2)-557;
 
  sprintf(buf, "%03u Volts", v);
  lcd.setCursor(0, 1);
  lcd.print(buf);
  Serial.println(buf);
 
  delay(100);
 
}
