uint8_t potPin=A0;
void setup() {
Serial.begin(9600);
}

void loop() {
  int value=analogRead(potPin);
  Serial.print("n0.val=");
  Serial.print(value);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.print("h0.val=");Serial.print(value);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  delay(200);
 
}
