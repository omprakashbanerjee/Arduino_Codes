int ledPin=3;
int btnPin=2;
int toggleState;
int lastButtonState=1;
long unsigned int lastPress;
volatile int buttonFlag;
int debounceTime=20;
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(btnPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),ISR_button, CHANGE);
}

void loop() {
  if((millis()-lastPress)>debounceTime && buttonFlag)
  {
    lastPress=millis();//update lastPress
  if(digitalRead(btnPin)== 0 && lastButtonState == 1)
  {
    toggleState=!toggleState;
    digitalWrite(ledPin,toggleState);
    lastButtonState=0;//record the lastButtonState
    }
    else if(digitalRead(btnPin)==1 && lastButtonState== 0)
    {
     lastButtonState=1; 
      }
      buttonFlag=0;
    }
}
void ISR_button(){
  buttonFlag=1;
  }
