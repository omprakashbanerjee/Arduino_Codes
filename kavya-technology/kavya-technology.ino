uint8_t red_led_A=5,blue_led_A=6;
uint8_t red_led_B=6,blue_led_B=7;
uint8_t torch=8;
uint8_t btn=12,btn_count=0,btn_val;
unsigned long now,prev=0,timer=100;
void setup() {
  pinMode(red_led_A,OUTPUT);
  pinMode(red_led_B,OUTPUT);
  
  pinMode(blue_led_A,OUTPUT);
  pinMode(blue_led_B,OUTPUT);
//  pinMode(torch,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  btn_val=digitalRead(btn);
  if(btn_val==1){
    delay(30);
    btn_val=digitalRead(btn);
      if(btn_val==0){
    btn_count++;
      }
  }
    
 if(btn_count==1){
         digitalWrite(torch,0);
          digitalWrite(blue_led_A,1);delay(100);
           digitalWrite(blue_led_A,0);
           digitalWrite(red_led_A,1);delay(100);
          digitalWrite(red_led_A,0);
    }
          
   else if(btn_count==2){
          digitalWrite(torch,0);
          digitalWrite(blue_led_B,1);delay(100);
           digitalWrite(blue_led_B,0);
           digitalWrite(red_led_B,1);delay(100);
          digitalWrite(red_led_B,0);
   }
          
     else if(btn_count==3){
          digitalWrite(torch,0);
           digitalWrite(blue_led_A,1);digitalWrite(blue_led_B,1);delay(100);
          digitalWrite(blue_led_A,0);digitalWrite(blue_led_B,0);
           digitalWrite(red_led_A,1);digitalWrite(red_led_B,1);delay(100);
           digitalWrite(red_led_A,0);digitalWrite(red_led_B,0);
     }
           
     else if(btn_count==4){
            digitalWrite(torch,1);
          digitalWrite(blue_led_A,0);
            digitalWrite(blue_led_B,0);
            digitalWrite(red_led_A,0);
            digitalWrite(red_led_B,0);
            delay(100);
           
     }
            
    else if(btn_count==0 || btn_count==4){
//            digitalWrite(torch,0);
            digitalWrite(blue_led_A,0);
            digitalWrite(blue_led_B,0);
            digitalWrite(red_led_A,0);
            digitalWrite(red_led_B,0);
            delay(100);
            btn_count=0;
          }
   }
