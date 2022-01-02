#include <Keypad.h>
unsigned int i,in1=10,in2=11;


const byte ROWS = 4; 
const byte COLS = 4; 

char mykeypad[ROWS][COLS] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad getkeyvalue = Keypad(makeKeymap(mykeypad), rowPins, colPins, ROWS, COLS); 

void setup()
{  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
 // pinMode(btn1,INPUT);
 // pinMode(btn2,INPUT);
  digitalWrite(in1,0);
  digitalWrite(in2,0);

  Serial.begin(9600);
}
  
void loop()
{
  char keyvalue = getkeyvalue.getKey();
if(keyvalue=='1')//without this if, program goes into infinite loop
{switch(keyvalue)
  {case '1':digitalWrite(in1,1);
            digitalWrite(in2,0);Serial.println(keyvalue);break;
            
   case '0':analogWrite(in1,127);
            digitalWrite(in2,0);Serial.println(keyvalue);break;
   default: digitalWrite(in1,0);
             digitalWrite(in2,0); 
             Serial.println(keyvalue);break;
             
   
    
  }
}
}
