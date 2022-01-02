#include <doxygen.h>
#include <NexButton.h>
#include <NexConfig.h>
#include <NexCrop.h>
#include <NexGauge.h>
#include <NexHardware.h>
#include <NexHotspot.h>
#include <NexObject.h>
#include <NexPage.h>
#include <NexPicture.h>
#include <NexProgressBar.h>
#include <NexSlider.h>
#include <NexText.h>
#include <Nextion.h>
#include <NexTouch.h>
#include <NexWaveform.h>
#include<DHT.h>
DHT dht_sensor(5,DHT11);
#define datapin 5
void setup() {
Serial.begin(9600); // put your setup code here, to run once:
dht_sensor.begin();
nexInit();
}
unsigned int current_time=0,prev_time=0,interval=2000;
uint8_t pot,potpin=A0;
  void loop() {
    current_time=millis();
    if(current_time-prev_time>=interval)
      {
      float temp=dht_sensor.readTemperature();
      float humidity=dht_sensor.readHumidity();
//     Serial.print("temp= ");Serial.print(t); Serial.println(" *C");
//      Serial.print("humidity= "); Serial.print(h);  Serial.println(" %");
      String command ="temp.txt=\""+String(temp,1)+"\"";
      Serial.print(command);
      Serial.write(0xff); Serial.write(0xff);  Serial.write(0xff);
      String command2="humid.txt=\""+String(humidity,2)+"\"";
      Serial.print(command2);
      Serial.write(0xff); Serial.write(0xff); Serial.write(0xff);
//     
      //delay(2000);
    prev_time=current_time;
      }
      pot=analogRead(potpin);
      Serial.print("n0.val="); 
      Serial.print(pot);
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
       Serial.print("click h0,1");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
  }
