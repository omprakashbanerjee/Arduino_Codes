unsigned int var,led1=8,led2=9,led3=10;
void setup() {
pinMode(A0,INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() {
  var=analogRead(A0);
  if(var>400 && var<430){
  Serial.println(var);
  digitalWrite(led1,1);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  delay(300);
  digitalWrite(led1,0);
  
  }
  else if((var>230 && var<260)){
  Serial.println(var);
  digitalWrite(led1,0);
  digitalWrite(led2,1);
  digitalWrite(led3,0);
  delay(300);
  digitalWrite(led2,0);
  
  }
  else if((var>130 && var<160)){
  Serial.println(var);
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,1);
  delay(300);
  digitalWrite(led3,0);
  
  }
}
