#include <Arduino.h>
#include<Wire.h>

// Fan A
#define in1A 4
#define in2A 2
#define pwmA 3

// Fan B
#define in1B 7
#define in2B 8
#define pwmB 6

// Peltier
#define in1C 9
#define in2C 11
#define pwmC 10

// TMP100 I2C addresses
#define Addr48 0x48 //cooling side sensor
#define Addr49 0x49 //heating side sensor



// Fan Speed Values - Start at zero
int HeaterA_temp = 0;
int HeaterB_temp = 0;
int HeaterC_temp = 0;

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
  

  // Set Motor forward 
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);

  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);

  digitalWrite(in1C, HIGH);
  digitalWrite(in2C, LOW); 
  
  HeaterA_temp = 150;
  HeaterB_temp = 140;
  HeaterC_temp = 250;

  // Set the motor speeds
  analogWrite(pwmA,HeaterA_temp ); 
  analogWrite(pwmB,HeaterB_temp ); 
  analogWrite(pwmC,HeaterC_temp ); 

  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise Serial communication, set baud rate = 115200
  Serial.begin(115200);


  // Start I2C Transmission
  Wire.beginTransmission(Addr48);
  // Select configuration register
  Wire.write(0x01);
  // Set continuous conversion, comparator mode, 12-bit resolution
  Wire.write(0x60);
  // Stop I2C Transmission
  Wire.endTransmission();
  delay(300);  
  
   // Start I2C Transmission
  Wire.beginTransmission(Addr49);
  // Select configuration register
  Wire.write(0x01);
  // Set continuous conversion, comparator mode, 12-bit resolution
  Wire.write(0x60);
  // Stop I2C Transmission
  Wire.endTransmission();
  delay(300);  
   }

void loop()
{
 

   unsigned int data48[2];
  
  // Start I2C Transmission
  Wire.beginTransmission(Addr48);
  // Select data register
  Wire.write(0x00);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Request 2 bytes of data
  Wire.requestFrom(Addr48, 2);

  // Read 2 bytes of data
  // cTemp msb, cTemp lsb
  if(Wire.available() == 2)
  {
    data48[0] = Wire.read();
    data48[1] = Wire.read();
  }
    
  // Convert the data
  float cTemp48 = (((data48[0] * 256) + (data48[1] & 0xF0)) / 16) * 0.0625;
  
  // Output data to serial monitor
  Serial.print("Reading from cooling side : ");
  Serial.print(cTemp48);
  Serial.println(" C");
 
 delay(500);

  unsigned int data49[2];
  
  // Start I2C Transmission
  Wire.beginTransmission(Addr49);
  // Select data register
  Wire.write(0x00);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Request 2 bytes of data
  Wire.requestFrom(Addr49, 2);

  // Read 2 bytes of data
  // cTemp msb, cTemp lsb
  if(Wire.available() == 2)
  {
    data49[0] = Wire.read();
    data49[1] = Wire.read();
  }
    
  // Convert the data
  float cTemp49 = (((data49[0] * 256) + (data49[1] & 0xF0)) / 16) * 0.0625;
  
  // Output data to serial monitor
  Serial.print("Reading from Heating side : ");
  Serial.print(cTemp49);
  Serial.println(" C");
 
  delay(500);

  
}
