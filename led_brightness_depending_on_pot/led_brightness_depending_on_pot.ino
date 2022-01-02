int pot_val,POT=A0;
uint8_t S_out=3;
void setup() {
pinMode(POT,INPUT);  
pinMode(S_out,OUTPUT);
}

void loop() {
 pot_val=map(analogRead(POT),0,1023,0,255);
 analogWrite(S_out,pot_val);
 

}
