#include <Arduino.h>
#include <SPI.h>

// Pins and Constants
#define CS PA4  // Chip or Slave select
#define BAUDRATE 115200
#define DELAY 2000
// End

void setup()
{
  SPI.begin();
  pinMode(CS,OUTPUT);//Slave Select
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV32);
  digitalWrite(CS,LOW);
 byte response = SPI.transfer(0x00);
 digitalWrite(CS,HIGH); 
  Serial.begin(BAUDRATE);
}

void loop()
{ 
digitalWrite(CS,LOW);
 byte response = SPI.transfer(0x10);
 digitalWrite(CS,HIGH); 
     Serial.print("I received: ");
     Serial.println(response ,DEC);  
     
delay(1000);
}