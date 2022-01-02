#include<ESP8266WiFi.h>
#define ledPin D7
const char* ssid="OM PRAKASH BANERJEE";
const char* password="OMprakash1994";
WiFiServer server(80);
void setup() {
Serial.begin(115200);
delay(10);
pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW);
Serial.print("Conecting to ");
Serial.println(ssid);
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
Serial.println("WiFi connected");
server.begin();
Serial.print("server started and ip address is  http://");
Serial.println(WiFi.localIP());
}

void loop() {
 WiFiClient client=server.available();
 if(!client) return;
 while(!client.available()) delay(1);

 String request=client.readStringUntil('\r');
 Serial.println(request);
 client.flush();

 int value=LOW;

 if(request.indexOf("/LED=ON")!= -1)
 {
  digitalWrite(ledPin,HIGH);
  value=HIGH;
  }
  if(request.indexOf("/LED=OFF")!= -1)
 {
  digitalWrite(ledPin,LOW);
  value=LOW;
  }
 
  client.println("HTTP:/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("Led pin is now: ");
 
  if(value==HIGH)    client.println("on");
 
 else client.println("off");
 
 client.println("<br><br>");
 client.println("<a href=\"LED=ON\"><button>turn on</button></a>");
 client.println("<a href=\"LED=OFF\"><button>turn off</button></a></br>");
 client.println("</html>");
 delay(1);
 Serial.println("Client disconnected");
 Serial.println("");
}
