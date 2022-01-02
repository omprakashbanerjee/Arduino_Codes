#include"MyLib.h"
void setup() {
  Serial.begin(9600);
  int i=3;
  int j=5;
  int result;
  result =MyLib.addem(i,j);
  Serial.print("result is ");
  Serial.println(result);
}

void loop() {
  // put your main code here, to run repeatedly:

}
