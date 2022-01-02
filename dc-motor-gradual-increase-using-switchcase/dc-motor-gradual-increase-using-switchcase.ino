unsigned int i,in1=3,in2=5,btn1=7,btn2=8,val1,val2;
uint8_t count=0;
void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  // put your setup code here, to run once:

}

void loop() 
{val1=digitalRead(btn1);
if(val1==1)
count++;
   switch(count){
    case 1:speed1();break;
    case 2:speed2();break;
    default :off();break;
   }
}
void off()
{ 
  for(i=0;i<=1;i++)
   { digitalWrite(in1,0);
      digitalWrite(in2,0);
    }
}
void speed1()
{
   for(i=0;i<=255;i++)
        {analogWrite(in1,i);
         digitalWrite(in2,0);
         delay(i);
        }delay(2000);
}
void speed2()
{
 for(i=255;i>0;i--)
        {analogWrite(in1,i);
         digitalWrite(in2,0);
         delay(i);
        }
}
