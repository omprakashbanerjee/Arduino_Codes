uint8_t S_out=3;
void setup() {
  
pinMode(S_out,OUTPUT);
}
void loop() {
  analogWrite(S_out,254);
   delay(20000);
   analogWrite(S_out,191);
   delay(20000);
   analogWrite(S_out,127);
   delay(20000);
   analogWrite(S_out,63);
   delay(20000);
   analogWrite(S_out,10);
   delay(20000);
  analogWrite(S_out,0);
   delay(3000);
}
