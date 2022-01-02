//#include <LCD.h>
#include <LiquidCrystal_I2C.h>

const float R1 = 47000.0;
const float R2 = 4700.0;

const float R3 = 47000.0;
const float R4 = 4700.0;

#define ACS712 A1
#define SOL A0
#define BATT A2

#define LOW_SOL 10.0
#define LOW_BATT 5.9
#define FULL_BATT 6.5
#define MAX_SOL_CURR 2.2

#define RA 4
#define RB 5 
#define RC 6

#define RED 7
#define GREEN 8
#define I2C_ADDR 0x27
/*#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
*/
//LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
LiquidCrystal_I2C lcd(I2C_ADDR,16,2);

byte solar[8] = //icon for solar panel
{
        0b11111,0b10101,0b11111,0b10101,0b11111,0b10101,0b11111,0b00000
};
byte battery[8] =  //icon for battery
{
        0b01110,0b11011,0b10001,0b10001,0b10001,0b10001,0b10001,0b11111
};

byte curr[8] =  // icon for power
{
        0b00010,0b00100,0b01000,0b11111,0b00010,0b00100,0b01000,0b00000
};
float sol_volt = 0.0, sol_amp = 0.0, batt_volt = 0.0, sol_watt = 0.0;


void setup() 
{
  lcd.begin ();
 //// lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);

  lcd.createChar(1,solar);
  lcd.createChar(2, battery);
  lcd.createChar(3, curr);
  
  lcd.clear();
  
  lcd.home ();
  lcd.write(1);
  lcd.print(":");
 
  lcd.setCursor(0,1);
  lcd.write(2); 
  lcd.print(":");

  lcd.setCursor(7,0);
  lcd.write(3); 
  lcd.print(":");

  lcd.setCursor(7,1);
  lcd.print("P"); 
  lcd.print(":");

  pinMode(RA,OUTPUT);
  pinMode(RB,OUTPUT);
  pinMode(RC, OUTPUT);
  
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  
  digitalWrite(RA, HIGH);
  digitalWrite(RB, HIGH);
  digitalWrite(RC, HIGH);
}

void loop()
{ 
  
  
  sol_volt=analogRead(SOL);
  sol_volt=(sol_volt/1024.0)*4.5;
  sol_volt=(sol_volt*(R1+R2))/R2;
  
  batt_volt=analogRead(BATT);
  batt_volt=(batt_volt/1024.0)*4.5;
  batt_volt=(batt_volt*(R3+R4))/R4;
  
  for(int i = 0; i < 100; i++) 
  {
     sol_amp = sol_amp + (.0264 * analogRead(ACS712) -13.51);//for the 5A mode,  
      //current = current + (.049 * analogRead(A3) -25);// for 20A mode
      //current = current + (.742 * analogRead(A3) -37.8);// for 30A mode
   
 }
 //current = current*(-1) ;
 sol_amp = sol_amp/100;
 if(sol_amp<=0.1){ sol_amp=0; }
  
 sol_watt = (sol_volt)*(sol_amp);

 lcd.setCursor(2,0);
 lcd.print(sol_volt,1);

 lcd.setCursor(2,1);
 lcd.print(batt_volt,1);

 lcd.setCursor(9,0);
 lcd.print(sol_amp,1);

 lcd.setCursor(9,1);
 lcd.print(sol_watt,1);

 if((sol_volt > 8.5) && (batt_volt > 6.5))//batt charged and solar present, bypass solar and charging off
 {
  digitalWrite(RA, HIGH);//off
  digitalWrite(RB, LOW);//on
  digitalWrite(RC, HIGH);//off
 }

 if((sol_volt > 8.5) && (batt_volt < 6.5))//batt medium and solar present, charging on and bypass solar, buck on, boost off
 {
  digitalWrite(RA, HIGH);//off
  digitalWrite(RB, LOW);//on
  digitalWrite(RC, HIGH);//off
 }

 if((sol_volt < 8.5) && (batt_volt > 6.5))//batt charged and no solar, bypass battery, buck off , boost off
 {
  digitalWrite(RA, HIGH);//off
  digitalWrite(RB, LOW);//on
  digitalWrite(RC, LOW);//on
 }

 if((sol_volt < 8.5) && (batt_volt < 6.0))// battery discharged, no solar, bypass solar, buck off, boost off
 {
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(RC, LOW);
 }
}
