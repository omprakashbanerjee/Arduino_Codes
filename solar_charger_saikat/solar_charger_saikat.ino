//#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 //I2C adress, you should use the code to scan the adress first (0x27) here
/*
#define BACKLIGHT_PIN 3 // Declaring LCD Pins
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
*/
LiquidCrystal_I2C lcd(I2C_ADDR,16,2);


const int adc_chan1 = A0;
const int adc_chan2 = A1;
const int green = 11;
const int red = 12;

const int load_relay = 5;
const int charge_relay = 4;

unsigned long previousMillis = -5000; 
const long interval = 5000;

const float R1 = 10000;
const float R2 = 2200;
const float R3 = 10000;
const float R4 = 2200;

float sol_volt, batt_volt, sol_watt;
float vo1, vo2;


int adc_sol_volt;
int adc_batt_volt;




void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(4, 1);
  digitalWrite(5, 0);

  lcd.begin ();
//  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH); 
  lcd.home ();
  lcd.print("charge controller");
  delay(2000);
  lcd.clear();
}


void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
  previousMillis = currentMillis;

  lcd.clear();
  adc_sol_volt = analogRead(adc_chan1);
  vo1 = ((adc_sol_volt/1024.0)*4.80);
  sol_volt = (vo1*(R1+R2))/R2;
  lcd.home();
  lcd.print("sol:");
  lcd.print(sol_volt);
  lcd.print("V");
  
  adc_batt_volt = analogRead(adc_chan2);
  vo2 = ((adc_batt_volt/1024.0)*4.8);
  batt_volt = (vo2*(R3+R4))/R4;
  batt_volt = batt_volt - 0.39;
  lcd.setCursor(0,1);
  lcd.print("batt volt:");
  lcd.print(batt_volt);
  lcd.print("V");
  
  unsigned int x=0;
  float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,Acs=0.0;
  for (int x = 0; x < 150; x++)
  { 
    AcsValue = analogRead(A2);        
    Samples = Samples + AcsValue;  
    delay (3); 
  }

  AvgAcs=Samples/150.0;
  Acs = (2.35 - (AvgAcs * (4.69 / 1024.0)) )/0.066;
  if(Acs <= 0.6){ Acs = 0; }
  lcd.setCursor(0,2);
  lcd.print("sol curr:");
  lcd.print(Acs);
  lcd.setCursor(0,14);
  lcd.print("A");
  
  
  sol_watt = ( Acs * sol_volt );
  lcd.setCursor(0,3);
  lcd.print("sol watt:");
  lcd.println(sol_watt);
  lcd.print("W");

  
    if(batt_volt >= 6.0 && batt_volt <= 6.2)
    {
      
      digitalWrite(red, 1);
      digitalWrite(green, 0);
      digitalWrite(charge_relay, 0);//on
      digitalWrite(load_relay, 0);//off
      //lcd.clear();
      lcd.setCursor(13,0);
      lcd.print("Load OFF");
      
    }
    if(batt_volt >= 6.3 && batt_volt <= 6.8)
    {
      digitalWrite(red, 0);
      digitalWrite(green, 1);
      digitalWrite(charge_relay, 1);//off
      digitalWrite(load_relay, 1);//on
      lcd.setCursor(13,0);
      //lcd.clear();
      lcd.print("Load ON");
    }
  }
  
    
  
  
}
