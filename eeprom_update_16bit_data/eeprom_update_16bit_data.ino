/*all lowerbit(LSB) data is saved at lower address bytes
 * and higher(MSB) bit data is stored at higher data address
 * 
 * password adress 25,26
ontime address    0,1
offtime address   5,6
hour address      10
min address       12
sec adress        14
*/
#include <EEPROM.h>
uint8_t MSB,LSB;
uint16_t CurrentOntime=10,offtime;
uint16_t CurrentOfftime=5,ontime;
uint16_t savedPassword=1234,pwd;
uint8_t CycleStartHour=12,hh;
uint8_t CycleStartMinute=10,mm;
uint8_t CycleStartSec=10,ss;
void  setup()
{
// Serial.begin(9600);
//Serial.println("updating eeprom data");

 //Serial.print("savedPassword is=");Serial.println(savedPassword);
      EEPROM.update(25,savedPassword);
      EEPROM.update(26,savedPassword>>8);
      delay(1000);
 //Serial.print("CurrentOntime is=");Serial.println(CurrentOntime);
        EEPROM.update(0,CurrentOntime);
        EEPROM.update(1,CurrentOntime>>8);
     delay(1000);   
 //Serial.print("CurrentOfftime is=");Serial.println(CurrentOfftime);
       EEPROM.update(5,CurrentOfftime);
       EEPROM.update(6,CurrentOfftime>>8);
     delay(1000);  
//Serial.print("CycleStartHour is=");Serial.println(CycleStartHour);
 //Serial.print("CycleStartMinute is=");Serial.println(CycleStartMinute);
 //Serial.print("CycleStartSec is=");Serial.println(CycleStartSec);
       
       EEPROM.update(10,CycleStartHour);
       EEPROM.update(12,CycleStartMinute);
       EEPROM.update(14,CycleStartSec);

//    Serial.println("printing saved data")  ; // EEPROM.get(address,var);//var is the variable in which we want to store the data
//       delay(1000);
//EEPROM.get(26,MSB);
//EEPROM.get(25,LSB);
//uint16_t pwd=(MSB<<8)|LSB;
//Serial.print("savedPassword is=");Serial.println(pwd);
//delay(1000);
//EEPROM.get(1,MSB);
//EEPROM.get(0,LSB);
//uint16_t ontime=(MSB<<8)|LSB; Serial.print("ontime is=");Serial.println(ontime);
//delay(1000);
//EEPROM.get(6,MSB);
//EEPROM.get(5,LSB);
//uint16_t offtime=(MSB<<8)|LSB; Serial.print("offtime is=");Serial.println(offtime);
//delay(1000);
//EEPROM.get(10,hh);
//Serial.print("hour is=");Serial.println(hh);
//delay(1000);
//EEPROM.get(12,mm);
//Serial.print("minute is=");Serial.println(mm);
//delay(1000);
//EEPROM.get(14,ss);
//Serial.print("sec is=");Serial.println(ss);

}
void loop(){}
