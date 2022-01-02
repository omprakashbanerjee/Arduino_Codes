int val,led=10,in1=5,in2=6;
void setup() {
  Serial.begin(9600);// put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
digitalWrite(in1,0);
digitalWrite(in2,0);
}

void loop() {
  //if(Serial.read(val) //here 0 is not a numeric value.we can evn pass 0 as input
  
    
    if(Serial.available()>0){
val=Serial.read();
   if(val==49){
              digitalWrite(led,1);//press 1 for rotate
              Serial.println(val);
              digitalWrite(in1,1);
              digitalWrite(in2,0);
              }
     else if(val==50){
              analogWrite(led,100);
              Serial.println(val);//press2 for reverse rotate
              digitalWrite(in1,0);
              digitalWrite(in2,1);
              }
     else if(val== 48)
             {digitalWrite(led,0);
             Serial.println(val);//press 0 to stop
              digitalWrite(in1,0);
              digitalWrite(in2,0);
              }
     else
              {digitalWrite(led,0);Serial.println(val);//press 0 to stop
              digitalWrite(in1,0);
              digitalWrite(in2,0);
              }
      }
}
