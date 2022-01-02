uint8_t btn=8;
void setup() {
  Serial.begin(9600);
  pinMode(btn,INPUT);
  // put your setup code here, to run once:

}
void loop() {
uint8_t  btn_val=digitalRead(btn);

  if(btn_val==1)
  {
//    Serial.println("pressed");
  delay(30);
  btn_val=digitalRead(btn);
    if(btn_val==0)
      Serial.println("released");
  }
  else
  delay(100);
}
