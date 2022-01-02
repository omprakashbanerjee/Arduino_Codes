#include "Nextion.h"
#include <Servo.h>

Servo myservo;

uint8_t val=0;
NexSlider h0 = NexSlider(0, 8, "h0");
NexButton btn_up   = NexButton(0, 10, "b5");
NexButton btn_down = NexButton(0, 11, "b6");
NexButton btn20 = NexButton(0, 4, "b0");
NexButton btn45 = NexButton(0, 5, "b1");
NexButton btn90 = NexButton(0, 6, "b2");
NexButton btn135 = NexButton(0, 7, "b3");
NexButton btn160 = NexButton(0, 9, "b4");
//NexButton btn_down = NexButton(0, 3, "btn_down");
NexTouch *nex_listen_list[] = 
{
  &btn_up,&btn_down,&btn20,&btn45,&btn90,&btn135,&btn160,
    NULL
};

void btn20PopCallback(void *ptr)
{
  val=20;
  myservo.write(val);Serial.println("servo20");
}
void btn45PopCallback(void *ptr)
{ val=45;
  myservo.write(val);Serial.println("servo45");
}
void btn90PopCallback(void *ptr)
{ val=90;
  myservo.write(val);Serial.println("servo90");
}
void btn135PopCallback(void *ptr)
{ val=135;
  myservo.write(val);Serial.println("servo135");
}
void btn160PopCallback(void *ptr)
{ val=160;
  myservo.write(val);Serial.println("servo160");
}
void buttonUpPopCallback(void *ptr)
{
    //uint32_t number = 0;
    //dbSerialPrintln("buttonUpPopCallback");
if(val<=160)
{
 val=val+10;  myservo.write(val);
 }
else if(val>160)
{
  if(val<=168)
  {
    val=val+2;  myservo.write(val);Serial.println("servo++");
    }
}
}
void buttonDownPopCallback(void *ptr)
{
    //uint32_t number = 0;
    //dbSerialPrintln("buttonDownPopCallback");
  if(val>=30)
{
  val=val-10;
  myservo.write(val);
  Serial.println("servo--");
}
}

void h0PopCallback(void *ptr)
//{ uint32_t number = 0;
//    char temp[10] = {0};
//    
//    dbSerialPrintln("h0PopCallback");
//
//    h0.getValue(&number);
//    utoa(number, temp, 10);
//    t0.setText(temp);
    String data_recvd="";
    data_recvd +=char(Serial.read());
    myservo.write(val);
}


void setup(void)
{ Serial.begin(9600);
    myservo.attach(9);
    nexInit();
    btn20.attachPop(btn20PopCallback,&btn20);
    btn45.attachPop(btn45PopCallback,&btn45);
    btn90.attachPop(btn90PopCallback,&btn90);
    btn135.attachPop(btn135PopCallback,&btn135); 
    btn160.attachPop(btn160PopCallback,&btn160);
    btn_up.attachPop(buttonUpPopCallback,&btn_up);
    btn_down.attachPop(buttonDownPopCallback,&btn_down);
    
    h0.attachPop(h0PopCallback,&h0);
   
}

void loop(void)
{
    nexLoop(nex_listen_list);
}
