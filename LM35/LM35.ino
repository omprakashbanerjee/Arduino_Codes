
uint8_t LM35=A0;
float val;

void setup() {
  Serial.begin(9600);
pinMode(LM35,INPUT);  // put your setup code here, to run once:

}

void loop() {
val=analogRead(LM35)*500/1024;  // put your main code here, to run repeatedly:
Serial.println(val);
}
