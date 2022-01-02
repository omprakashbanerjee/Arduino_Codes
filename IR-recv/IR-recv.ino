#include <IRremote.h>
const int RECV_PIN=4; //sensor pin
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
//    print code in hex
Serial.println(results.value);
irrecv.resume();
  }
}
