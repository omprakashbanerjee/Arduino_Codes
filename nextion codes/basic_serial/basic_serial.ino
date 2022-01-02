void setup() {
  Serial.begin(9600);
  
}
unsigned long current_time=0,prev_time=0;
  unsigned int interval=1000,i=0;


void loop() {
  if(Serial.available())
  {
    String data_recvd="";
    delay(30);
    while(Serial.available())
    {
      data_recvd +=char(Serial.read());
    }
    SendData(data_recvd);
  }
 current_time=millis();
  if(current_time - prev_time>=interval)
  { if(i<=89)
    {
        Serial.print("j0.val=" + String(i));
        Serial.write(0xff);
        Serial.write(0xff);
        Serial.write(0xff);
        i++;
    }
     else i=10;
   prev_time=current_time;
   }
 
}

void SendData(String data_recvd)
{
  Serial.println(data_recvd);
  Serial.println(data_recvd.toInt());
}
