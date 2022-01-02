#include<Filters.h>             //This library does a huge work check its .cpp file
#include <LiquidCrystal_I2C.h>    //LCD ic library
#include "EmonLib.h"
//#include <LCD.h>
#define ACS_Pin A3              //ACS712 data pin

/*#define I2C_ADDR 0x27 //I2C adress, you should use the code to scan the adress first (0x27) here
#define BACKLIGHT_PIN 3 // Declaring LCD Pins
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
*/
//LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin); //Declaring the lcd
LiquidCrystal_I2C lcd(0x27,16,2);
EnergyMonitor emon1;
EnergyMonitor emon2;

float testFrequency = 50.0;                     // test signal frequency (Hz)
float windowLength = 40.0/testFrequency;     // how long to average the signal, for statistist

float intercept = 0; // to be adjusted based on calibration testing
float slope = 0.0752; // to be adjusted based on calibration testing
                      //Please check the ACS712 Tutorial video by SurtrTech to see how to get them because it depends on your sensor, or look below
//float slope = 
float Amps_TRMS=0.0; 
float ACS_Value;

const int relay1 = 9;  
const int relay2 = 10; 
const int relay3 = 11;

 
 
float primary =0.0;
float secondary = 0.0;


unsigned long printPeriod = 2000; 
unsigned long previousMillis = 0;



void setup() {
  Serial.begin(9600);
  lcd.begin();
  //lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  //lcd.setBacklight(HIGH); //Lighting backlight
  //lcd.home ();
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(ACS_Pin, INPUT);
  
  emon1.voltage(A1, 212.26, 1.7);
  emon2.voltage(A2, 212.26, 1.7);
}

void loop() {
  
RunningStatistics inputStats;                 // create statistics to look at the raw test signal
      
  inputStats.setWindowSecs( windowLength );

  
      
  while( true ) {   
    ACS_Value = analogRead(ACS_Pin);
    Serial.println(ACS_Value);
    inputStats.input(ACS_Value);  // log to Stats function
    
     
         
      
    if((unsigned long)(millis() - previousMillis) >= printPeriod) 
    { //every second we do the calculation
      previousMillis = millis();   // update time
      emon1.calcVI(10,500);
      //emon1.serialprint();

      emon2.calcVI(10,500);
      //emon2.serialprint();
      primary   = emon1.Vrms; 
      secondary = emon2.Vrms; 

      Amps_TRMS = intercept + slope * inputStats.sigma();  //Calibrate the values
      Serial.println(inputStats.sigma());
      if( Amps_TRMS <= 0.15 )
      {
        Amps_TRMS = 0;
      }
      
      
      lcd.clear();               //clear the lcd and print in a certain position
      
      

      lcd.setCursor(0,0);
      lcd.print("V1:");
      lcd.print(primary,0);
      lcd.print("V");
      lcd.setCursor(9,0);
      lcd.print("V2:");
      lcd.print(secondary,0);
      lcd.print("V");
  
      lcd.setCursor(0,1);
      lcd.print("I:");
      lcd.print(Amps_TRMS,2);
      lcd.print("A");


      if( primary > 200 && primary < 245 )
  //if primary inside the range
  {
    digitalWrite(relay1, LOW);//off
    digitalWrite(relay2, LOW);//off
    digitalWrite(relay3, HIGH);//on//master relay is ON
    
    //primary supply is connected to the load
     lcd.setCursor(11,1);     //(column, row)
     lcd.println("V1 ON");
         
  }
    else if( (primary < 200 || primary >240)  && (secondary > 200 && secondary < 245))
    //primary is out of range and secondary is ok
    {
      digitalWrite(relay1, HIGH);//on
      digitalWrite(relay2, HIGH);//on
      //secondary supply is connected to load
      digitalWrite(relay3, HIGH);//on//master relay is ON
      
      //secondary supply is connected to load
      lcd.setCursor(11,1);     //(column, row)
      lcd.println("V2 ON");
    }
    else if((primary <200 || primary > 245 ) && (secondary < 200 || secondary > 245))
    //if primary and secondary both are out of range
    {
      digitalWrite(relay1, LOW);//off
      digitalWrite(relay2, LOW);//off
      //primary supply is connected to load
      digitalWrite(relay3, LOW);//off
      //master relay is OFF so load is off
      
      
      lcd.setCursor(12,1);     //(column, row)
      lcd.println(" OFF");
          
    }
    }
  }
  
}

/* About the slope and intercept
 * First you need to know that all the TRMS calucations are done by functions from the library, it's the 
 * "inputStats.sigma()" value
 * At first you can display that "inputStats.sigma()" as your TRMS value, then try to measure using it when the 
 * input is 0.00A
 * If the measured value is 0 like I got you can keep the intercept as 0, otherwise you'll need to add or substract 
 * to make that value equal to 0
 * In other words " remove the offset"
 * Then turn on the power to a known value, for example use a bulb or a led that ou know its power and you already know your voltage, so a little math you'll get the theoritical amps
 * you divide that theory value by the measured value and here you got the slope, now place them or modify them
 */
