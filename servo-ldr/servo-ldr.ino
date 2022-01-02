#include<Servo.h>
Servo myservo;
unsigned int btn=8,val_ldr1,val_ldr2,val_ldr3,val_ldr4,pos=0,ldr1=A0,ldr2=A1,ldr3=A2,ldr4=A3; 
void setup() {Serial.begin(9600);
  myservo.attach(3);
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  pinMode(ldr3,INPUT);
  pinMode(ldr4,INPUT);
  // put your setup code here, to run once:

}

void loop()
{val_ldr1=analogRead(ldr1);
Serial.print("ldr1 value=");
Serial.println(val_ldr1);
delay(100);

val_ldr2=analogRead(ldr2);
Serial.print("ldr2 value=");
Serial.println(val_ldr2);

delay(100);
val_ldr3=analogRead(ldr3);
Serial.print("ldr3 value=");
Serial.println(val_ldr3);

delay(100);
val_ldr4=analogRead(ldr4);
Serial.print("ldr4 value=");
Serial.println(val_ldr4);
delay(100);
if(val_ldr1>400)
myservo.write(150);

else if(val_ldr2>400)
myservo.write(110);

else if(val_ldr3>400)
myservo.write(90);

else if(val_ldr4>400)
myservo.write(50);

else
myservo.write(20);
}
