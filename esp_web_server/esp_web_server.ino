#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "Pramila Banerjee";
const char* password = "lol lol lol";

ESP8266WebServer server(80);

void handleRoot()
{
  String message = "<html><body>\n";
  message += "<h1>Arduino Server by OM<h1>\n";
  message += "<p>A0 = ";
  message += analogRead(A0);

  message += (char)176;//for degree symbol
  message += "C";
  
  message += "</p>";
  message += "</html></body>\n";

  server.send(200, "text/html", message);
}


void connectToWiFi()
{
  Serial.print("\n\nConecting to...");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n!WiFi connected!");
  Serial.print("IP Adress :");
  Serial.println(WiFi.localIP());
  
}


void setup()
{
  Serial.begin(115200);

  connectToWiFi();

  server.on("/", handleRoot);

  server.begin();

  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient();
}
