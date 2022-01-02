#include <avr/wdt.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<Servo.h>
Servo myservo;
int val,val1,in1=8,in2=9;
uint8_t pos=0;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);// put your setup code here, to run once:
pinMode(in2,OUTPUT);
pinMode(in1,OUTPUT);
myservo.attach(3);//attach to only pwm pins
digitalWrite(in1,0);
digitalWrite(in2,0);



}

void loop() {
  lcd.setCursor(0,0);
lcd.print("press 1 for dc motor");
lcd.setCursor(0,1);
lcd.print("press 2 for servo");
delay(2000);
lcd.clear();
    
    if(Serial.available()>0)
    {lcd.setCursor(0,0);
    val=Serial.read();
    switch(val)
    { case 48:lcd.print("off");
              delay(100);
              digitalWrite(in1,0);
              digitalWrite(in2,0);
              myservo.write(0);
              lcd.clear();
              Serial.println(val);
              break;
      case 49:{lcd.print("dc motor running");
              Serial.println(val);
              myservo.write(0);
              digitalWrite(in1,1);
              digitalWrite(in2,0);
              lcd.clear();
               }break;
     case 50:do{Serial.println(val);
              digitalWrite(in1,0);
              digitalWrite(in2,0);//press2 for servo
             lcd.print("servo running");
             lcd.setCursor(0,1);
             for(pos=20;pos<=180;pos++)
             {myservo.write(pos);
             delay(10);
             }
             lcd.clear();
             lcd.print("running clockwise");
             for(pos=180;pos>=20;pos--)
             {myservo.write(pos);
             delay(10);
             }
             lcd.clear();
             }while(Serial.available()==0);
               break;
      default:digitalWrite(in1,0);
              digitalWrite(in2,0);
              myservo.write(0);
              break;
                    
          }
    }
lcd.setCursor(0,0);
lcd.print("no data received");
delay(500);
lcd.clear();
delay(500); 

}
