#include<LiquidCrystal.h>
unsigned int led[]={7,8,9,10},btn=2,btn_val,pot=A0,i,val=0;
const int rs=12, en=13, d4=11, d5=10, d6=9, d7=8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
   lcd.begin(16, 2);
  pinMode(led[0],OUTPUT);
    pinMode(led[1],OUTPUT);
      pinMode(led[2],OUTPUT);
        pinMode(led[3],OUTPUT);
          pinMode(btn,INPUT);
    
}

void loop()
{lcd.setCursor(0,0);
          val=digitalRead(btn);
          if(val==1)
           { pattern1();}
          else
           {pattern2();  } 

      }
void pattern1()
{ for(i=0;i<4;i++)
  {digitalWrite(led[i],1);delay(1000);
  digitalWrite(led[i],0);delay(500);
  }
}
void pattern2()
{
  for(i=0;i<4;i++)  
digitalWrite(led[i],1);delay(200);
for(i=0;i<4;i++)
digitalWrite(led[i],0); delay(200);
}
