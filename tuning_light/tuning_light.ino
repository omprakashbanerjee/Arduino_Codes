unsigned int led[]={7,8,9,10},count=0,btn=5,i;
void pattern1();
void pattern2();
void pattern3();
void pattern4();

void setup() {
  pinMode(led[0],OUTPUT);
  pinMode(led[1],OUTPUT);
  pinMode(led[2],OUTPUT);
  pinMode(led[3],OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  if(count=digitalRead(btn))
  switch(count){
    case 1:pattern1();break;
    case 2:pattern2();break;
    case 3:pattern3();break;
    case 4:pattern4();break;
  }
}
void pattern1(){
                for(;;)
                  {
                     digitalWrite(led[i],1);delay(100);
                     digitalWrite(led[i],0);delay(100);
                   }
void pattern2(){
    for(;;)
    {
    digitalWrite(led[i],1);
    digitalWrite(led[i+1],1);delay(100);
    digitalWrite(led[i],0);
    digitalWrite(led[i+1],0);
    delay(100);
    }
}
void pattern3()
{
 for(;;)
 {
   digitalWrite(led[i],1);
    digitalWrite(led[i+2],1);delay(100);
    digitalWrite(led[i],0);
    digitalWrite(led[i+2],0);
    delay(100);
 }
}
void pattern4()
{
 for(;;)
 {
   digitalWrite(led[i],1);
    digitalWrite(led[i+3],1);delay(100);
    digitalWrite(led[i],0);
    digitalWrite(led[i+3],0);
    delay(100);
 }
}
