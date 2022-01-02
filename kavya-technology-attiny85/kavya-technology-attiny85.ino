byte red_led_A=2,blue_led_A=1;
byte red_led_B=3,blue_led_B=4;
byte btn=0;
unsigned long currentTime=0,prevTime=0;
unsigned int interval1=30,interval2=100;
byte btn_count=0,btn_val;
byte state=0;
void setup() {
  //Serial.begin(9600);
  pinMode(red_led_A,OUTPUT);
  pinMode(red_led_B,OUTPUT);
  
  pinMode(blue_led_A,OUTPUT);
  pinMode(blue_led_B,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  btn_val=digitalRead(btn);
  if(btn_val==1)
  {
   currentTime=millis();
   prevTime=0;
   if(currentTime-prevTime>=interval1)
   {
  btn_val=digitalRead(btn);
    if(btn_val==0)
    { btn_count++;
     // Serial.println("counted");
    }
    prevTime=currentTime;
  }
 }
switch(btn_count){
  case 1:  //Serial.println("1");
          pattern1();
          break;
  case 2: // Serial.println("2");
          pattern2();
          break;
  case 3: // Serial.println("3");
          pattern3();
         break;
  case 4: // Serial.println("4-->0");
          pattern4();
          break;
  default: pattern4(); 
          break;
   }
}
   void pattern1()
   {
          if(currentTime-prevTime>=interval2)
   {  
        digitalWrite(blue_led_A,state);
         digitalWrite(red_led_A, !state);
         state = !state;
         prevTime=currentTime;
    }
   }
   void pattern2()
      { if(currentTime-prevTime>=interval2)
         {  digitalWrite(blue_led_B,state);
          digitalWrite(red_led_B, !state);
         state = !state;
         prevTime=currentTime;
        } 
     }
   void pattern3()
       {   
         if(currentTime-prevTime>=interval2)
         {
          digitalWrite(blue_led_A,state);
          digitalWrite(blue_led_B,state);
          digitalWrite(red_led_A,!state);
          digitalWrite(red_led_B,!state);
          state= !state;
          prevTime= currentTime;
        }
       }
   void pattern4() {
            digitalWrite(blue_led_A,0);
            digitalWrite(blue_led_B,0);
            digitalWrite(red_led_A,0);
            digitalWrite(red_led_B,0);
        }
