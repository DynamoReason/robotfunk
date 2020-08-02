#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "";
const char *password = "";
ESP8266WebServer server(80);
void handleRoot() {
 server.send(200, "text/html", "Server on!");
}
void handleUp() {
 Serial.write(45);
 server.send(200, "text/html", "");
}
void handleDown() {
 Serial.write(46);
 server.send(200, "text/html", "");
}
void handleLeft() {
 Serial.write(47);
 server.send(200, "text/html", "");
}
void handleRight() {
  Serial.write(48);
  server.send(200, "text/html", "");
}
void handleNotFound(){
  server.send(404, "text/plain", "404: Not found");
}
void setup() {
 delay(3000);
 Serial.begin(115200);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
 }

 server.on("/", HTTP_GET, handleRoot);     
 server.on("/up", HTTP_GET, handleUp); 
 server.on("/down", HTTP_GET, handleDown);
 server.on("/left", HTTP_GET, handleLeft);
 server.on("/right", HTTP_GET, handleRight);
 server.onNotFound(handleNotFound);
 server.begin();

}
void loop() {
 server.handleClient();
} 
