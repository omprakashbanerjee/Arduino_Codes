#include <Keypad.h>
unsigned int i; 
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

void setup(){
  Serial.begin(9600);
 
  Serial.println("enter array elements");
 }
char *arr;
char pass[]="1234";
uint8_t pos=0;
void loop()
{
   char keyvalue=getkeyvalue.getKey();
   if(keyvalue){
    while(i<10 && keyvalue!='D'){
    arr[i]=keyvalue;Serial.print(" ");Serial.print(arr[i]);
    pos++;
   }
   }
   else if(keyvalue=='D'){
    arr[pos]='\0';
    Serial.print("sizeof the array is now = ");
    Serial.println(sizeof(arr));
    for(i=0;i<sizeof(arr)/sizeof(char);i++){
      Serial.print(" ");
      Serial.print(arr[i]);
    }
}
}
