#include<SoftwareSerial.h>
SoftwareSerial gsm(9,10);  //Rx, Tx

unsigned int val,btn=8,btn_status,led=7;
void setup(){
  gsm.begin(9600);
  Serial.begin(9600);
  pinMode(btn,INPUT);
  
  pinMode(led,OUTPUT);
  delay(100);
}

void loop(){
  int val=digitalRead(btn);
  if(val==1){
   btn_status=1;
   while(btn_status==1){
 digitalWrite(led,1);
 delay(1000);
 digitalWrite  (led,0); 
 
  Serial.println("AT+CMGF=1");
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+917980669491\"\r");
 // delay(100);
  gsm.println("h");
  Serial.println("Message sent to 7980669491");
  delay(1000);
  gsm.println((char)26);
  delay(2000);
  val=0;
}
val=0;
btn_status=0;
}
else{}

}
