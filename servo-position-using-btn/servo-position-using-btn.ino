#include<Servo.h>
Servo myservo;
unsigned int btn=8,val,pos=0; 
void setup() {
  myservo.attach(3);
  pinMode(btn,INPUT);
  // put your setup code here, to run once:

}

void loop()
{val=digitalRead(btn);
  if((val==1)&&(pos<180))
      {pos=pos+20;
        myservo.write(pos);
      delay(100);
      }
      else if((val==1)&&(pos==180))
      {pos=0;
        myservo.write(pos);
      }
}
