unsigned int led[]={7,8,9,10},btn=2,pot_val,pot=A0,i,val;
void setup() {
  pinMode(led[0],OUTPUT);
    pinMode(led[1],OUTPUT);
      pinMode(led[2],OUTPUT);
        pinMode(led[3],OUTPUT);
          pinMode(btn,INPUT);
          pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop()
{
    pot_val=analogRead(pot);
    Serial.println(pot_val);
    if(pot_val>100 && pot_val<200)
         { val=digitalRead(btn);
          if(val==1)
           { pattern1();}
          else
           {pattern2();  } 
         }  
 for(i=0;i<4;i++)  
digitalWrite(led[i],1);delay(200);
for(i=0;i<4;i++)
digitalWrite(led[i],0); delay(200);
      }
void pattern1()
{ for(i=0;i<4;i++)
  {digitalWrite(led[i],1);delay(1000);
  digitalWrite(led[i],0);delay(200);
  }
}
void pattern2()
{
 for(i=0;i<4;i++)
 {digitalWrite(led[i],1);delay(2000);
  digitalWrite(led[i],0);//delay(2000);
  }
}
