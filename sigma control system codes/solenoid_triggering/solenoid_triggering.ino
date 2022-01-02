#define redWire 13
#define greenWire 3
#define button1 4
#define button2 5
bool triger_need;
unsigned long prevTime=0;
unsigned int interval2=100;
//uint8_t count=0;
byte state=1;
void trigger(int pin);
void setup() {
  Serial.begin(9600);
pinMode(greenWire,OUTPUT);
pinMode(redWire,OUTPUT);
pinMode(button1,INPUT_PULLUP);
pinMode(button2,INPUT_PULLUP);
}

void loop(void)
{
  if(digitalRead(button2)==0)
    {
      Serial.println("btn1 pressed");
      delay(30);
        if(digitalRead(button2)==1)
        {
          Serial.println("button1 released");
          trigger(redWire);
        }
    }
    if(millis()-prevTime>1000){
      digitalWrite(greenWire,state);
      prevTime=millis();
      state=!state;
    }
}
void trigger(int pin){
   Serial.println("inside trigger fn");
   unsigned long startTime=millis();
   digitalWrite(pin,1);
  while(millis()-startTime<35)
    {
      Serial.print(pin);
      Serial.println(" triggered"); 
      }
  digitalWrite(pin,0);
}
