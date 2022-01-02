void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

}

void loop() {
  int i=0;
  digitalWrite(2,1);////1p first off
  digitalWrite(3,0);///
  digitalWrite(4,0);/////2p first on
  digitalWrite(5,1);///
  digitalWrite(6,1);///3p first off
  digitalWrite(7,0);///
  delay(3.33);
  digitalWrite(2,0);////1p on
  digitalWrite(3,1);///
  digitalWrite(4,1);/////2p off
  digitalWrite(5,0);///
    delay(45.3);
 
  digitalWrite(2,1);////1p off
  digitalWrite(3,0);///
  digitalWrite(6,0);//3p on
  digitalWrite(7,1);///
  delay(3.33);
  digitalWrite(4,0);/////2p on
  digitalWrite(5,1);///
  digitalWrite(6,1);///3p off
  digitalWrite(7,0);///
  delay(3.33);
  digitalWrite(2,0);////1p on
  digitalWrite(3,1);///
  digitalWrite(4,1);/////2p off
  digitalWrite(5,0);///
    delay(45.3);
/*int i=0;  
  digitalWrite(2,0);////1p first on
  digitalWrite(3,1);///
  digitalWrite(4,1);/////2p first off
  digitalWrite(5,0);///
  digitalWrite(6,1);////3p first off
  digitalWrite(7,0);///
  delay(0.03);
  digitalWrite(4,0);///2p on
  digitalWrite(5,1);
  delay(0.03);
  digitalWrite(6,0);///3p on
  digitalWrite(7,1);
  while(i==0){
  delay(0.02);
  digitalWrite(2,1);////1p off
  digitalWrite(3,0);
  delay(0.02);
  digitalWrite(2,0);////1p on
  digitalWrite(3,1);
  delay(0.01);
  digitalWrite(4,1);////2p off
  digitalWrite(5,0);
  delay(0.02);
  digitalWrite(4,0);///2p on
  digitalWrite(5,1);
  delay(0.01);
  digitalWrite(6,1);////3p off
  digitalWrite(7,0);
  delay(0.02);
  digitalWrite(6,0);///3p on
  digitalWrite(7,1);
}
*/
/*int i=0;  
  digitalWrite(2,0);////1p first on
  digitalWrite(3,1);///
  digitalWrite(4,1);/////2p first off
  digitalWrite(5,0);///
  digitalWrite(6,1);////3p first off
  digitalWrite(7,0);///
  delay(0.033);
  digitalWrite(4,0);///2p on
  digitalWrite(5,1);
  while(i==0){
  delay(0.0166);
  digitalWrite(2,1);////1p off
  digitalWrite(3,0);
  delay(0.0166);
  digitalWrite(6,0);///3p on
  digitalWrite(7,1);
  delay(0.0166);
  digitalWrite(4,1);////2p off
  digitalWrite(5,0);
  delay(0.0166);
  digitalWrite(2,0);////1p on
  digitalWrite(3,1);
  delay(0.0166);
  digitalWrite(6,1);////3p off
  digitalWrite(7,0);
  delay(0.0166);
  digitalWrite(4,0);///2p on
  digitalWrite(5,1);
}*/
  
  }
