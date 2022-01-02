uint8_t led=7;
uint8_t d1=8,val;
void setup() {Serial.begin(9600);
  pinMode(d1,INPUT);
  pinMode(led,OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
 val=digitalRead(d1);
  Serial.println(val);
  if(d1==1)
  {
    Serial.println(val);
    digitalWrite(led,1);
  delay(200);
  digitalWrite(led,0);
  }
  else{}
}
