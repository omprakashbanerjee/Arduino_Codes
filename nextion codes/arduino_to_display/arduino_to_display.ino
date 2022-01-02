void setup() {
Serial.begin(9600);
}
 unsigned long current_time=0,prev_time=0;
  unsigned int interval=2000,i=10;
void loop() 
{
  
  current_time=millis();
  if(current_time - prev_time>=interval)
  { 
      Serial.print("j0.val=" + String(i));
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
      i++;
    prev_time=current_time;
  
  }
}
