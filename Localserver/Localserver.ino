#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "IECT"; 
const char* password =  "iectelectronics"; 
 
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);  
  Serial.println("hello");
  
  while (WiFi.status() != WL_CONNECTED) {  
      delay(500);
      Serial.println("Waiting to connect...");
  }
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
  
  server.on("/", handle_index); 
  
  server.begin(); 
  Serial.println("Server listening");
}

void loop() {
  server.handleClient(); 
}

void handle_index() {
  
  server.send(200, "text/plain", "Hello! This is an index page.");
}
