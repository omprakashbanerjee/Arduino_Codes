#include <IRremote.h>
const int RECV_PIN=4;//sensor pin
const int fan=8; //d8 for fan
const int light=10; //d10 for light
uint8_t toggle_fan=0,toggle_light=0;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
pinMode(light,OUTPUT);
pinMode(fan,OUTPUT);
}

void loop() {
  if(irrecv.decode(&results)){
//    print code in hex
Serial.println(results.value,HEX);
  switch(results.value){
    case 0x38C7D02F:if(toggle_light==0){
                     digitalWrite(light,1);
                     toggle_light=1;
                     }
                    else{
                    digitalWrite(light,0);
                    toggle_light=0;
                    }break;
    case 0X38C710EF:if(toggle_fan==0){
                     digitalWrite(fan,1);
                     toggle_fan=1;
                     }
                    else{
                    digitalWrite(fan,0);
                    toggle_fan=0;
                    }break;
    case 0x38C7C03F:if(toggle_light==0){
                     digitalWrite(light,1);
                     toggle_light=1;
                     }
                    else{
                    digitalWrite(light,0);
                    toggle_light=0;
                    }break;
    case 0x38C7906F:if(toggle_fan==0){
                     digitalWrite(fan,1);
                     toggle_fan=1;
                     }
                    else{
                    digitalWrite(fan,0);
                    toggle_fan=0;
                    }break;
    }
irrecv.resume();
  }
}
