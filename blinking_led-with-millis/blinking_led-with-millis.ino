uint8_t led=13,led2=6;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  
}
uint8_t ledToggle=0,ledToggle2=0;
unsigned long currentTime1;
unsigned long previousTime1=0;
unsigned long currentTime2;
unsigned long previousTime2=0;
const long interval1=1000, interval2=2000;
void loop() {
  currentTime1=millis();

  if(currentTime1-previousTime1>=interval1)
  {
    if(ledToggle==0)
    {
      digitalWrite(led,1);
      ledToggle=1;
      
    }
    else
    {
    digitalWrite(led,0);
    ledToggle=0;
    }
    previousTime1=currentTime1;
    currentTime2=millis();
    if(currentTime2-previousTime2>=interval2)
    {
      if(ledToggle2==0)
      { digitalWrite(led2,1);
      ledToggle2=1;
      }
      else
      {
        digitalWrite(led2,0);
        ledToggle2=0;
      } 
  previousTime2=currentTime2;
    }
  }  
}
