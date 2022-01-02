#include<Wire.h>

// Fan A
#define in1A 4
#define in2A 2
#define pwmA 3

// Fan B
#define in1B 7
#define in2B 8
#define pwmB 6




// Fan Speed Values - Start at zero
int HeaterA_temp = 0;
int HeaterB_temp = 0;

void setup() 
{
  // Set all the heater control pins to outputs
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(pwmA, OUTPUT);


  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(pwmB, OUTPUT);

  pinMode(in1C, OUTPUT);
  pinMode(in2C, OUTPUT);
  pinMode(pwmC, OUTPUT);
   HeaterA_temp = 150;
  HeaterB_temp = 150;
 

   }

void loop()
{
 // Set Motor forward 
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);

  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
   
 

  // Set the motor speeds
  analogWrite(pwmA,HeaterA_temp ); 
  analogWrite(pwmB,HeaterB_temp ); 
  


  
  
}
