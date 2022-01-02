unsigned int i,in1=10,in2=11,btn1=7,btn2=8,val1,val2;
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
{
    if(digitalRead(btn1)==1)
    {
       for(i=0;i<=255;i++)
        {analogWrite(in1,i);
         digitalWrite(in2,0);
         delay(i);
        }delay(2000);
    }
   
   else if(digitalRead(btn2)==1)
    {
       for(i=255;i>0;i--)
        {analogWrite(in1,i);
         digitalWrite(in2,0);
         delay(i);
        }//delay(2000);
    }
    else
    {
      digitalWrite(in1,0);
      digitalWrite(in2,0);
    }
}
