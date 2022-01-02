#include <Q2HX711.h>
#include <LiquidCrystal.h>
//in case i2c lcd please uncomment lcdi2c header and make comment lcd4bit
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,16,2);
//here pin connection  is according to lcd uno shield
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte hx711_data_pin = A3;
const byte hx711_clock_pin = A2;

Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);

float weight=0,avg_reading=3;
int i;
float y1 = 50.0; // calibrated mass to be added
long x1 = 0L;
long x0 = 0L;
float avg_size = 40.0; // amount of averages for each mass measurement
bool noWeight=true;
void setup() {
//  Serial.begin(9600);                 // prepare serial port
  lcd.begin(16,2);                         //Init the LCD4bit
  //lcd.begin();                    //initialize lcd i2c
  
  delay(500);                        // allow load cell and hx711 to settle

  
  // tare procedure
  for (int ii=0;ii<int(avg_size);ii++)
  {
    delay(5);
    x0+=hx711.read();
  }
  x0/=long(avg_size);
 
  //Serial.println("Add Calibrated Mass");
  lcd.clear();
  delay(1000); // calibration procedure (mass should be added equal to y1)
  while(noWeight){
    if (hx711.read()<x0+10000)
    {
      noWeight=true;
    //  Serial.println("please place calibrated mass");
      lcd.setCursor(0,0);
      lcd.print(" Add Calibrated ");
  lcd.setCursor(0,1);
  lcd.print("    50g load    ");
    } 
    else 
    {
      noWeight=false;
      delay(2000);
      //Serial.println("thanks please wait");
      lcd.setCursor(0,0);
      lcd.print(" Thanks please ");
      lcd.setCursor(0,1);
      lcd.print("    Wait...    ");
      
      for (int jj=0;jj<int(avg_size);jj++)
      {
        delay(5);
        x1+=hx711.read();
      }
      x1/=long(avg_size);
      break;
    }
  }
  //Serial.println("Calibration Complete");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Calibration   ");
  lcd.setCursor(0,1);
  lcd.print("    Complete    ");
  delay(10);
//  lcd.clear();
 
}


void loop() {
       long reading = 0;
      for (int jj=0;jj<int(avg_size);jj++)
      {
        reading+=hx711.read();
      }
      reading/=long(avg_size);
    
      float ratio_1 = (float) (reading-x0);
      float ratio_2 = (float) (x1-x0);
      float ratio = ratio_1/ratio_2;
      float weight=(y1*ratio);

 if(weight>1000.0)
 {
  weight=weight/1000.0;
 // Serial.print(weight);
 //   Serial.println(" kg");
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Weight=");
  
    lcd.setCursor(7,0);
    lcd.print(weight);
    lcd.print(" kg"); 
  }
  else if(weight<=1.00)
  { //weight=0;
   // Serial.print(weight);
   // Serial.println(" g");
   lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Weight=");
  
    lcd.setCursor(7,0);
    lcd.print((int)weight);
    lcd.print("g"); 
  }
  else
  {
   //Serial.print(weight);
   // Serial.println(" g");
   lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Weight=");
  
    lcd.setCursor(7,0);
    lcd.print(weight);
    lcd.print(" g");
  }
}
