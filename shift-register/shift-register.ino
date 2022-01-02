unsigned long currentTime,previousTime=0;
unsigned int eventDuration=1000;
unsigned int dataPin=4,CP=3,latchPin=2; 
void setup() {
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(CP,OUTPUT);
Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
    digitalWrite(latchPin,0);
    shiftOut(dataPin,CP,LSBFIRST,5);
    digitalWrite(latchPin,1);
delay(1000);

}
