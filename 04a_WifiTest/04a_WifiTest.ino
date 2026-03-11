/*  Microcontrollers 2026
    J.A. García.Rodríguez
    WiFi Test for ESP32-S3.

 * This sketch test ESP32-S3 Wifi conectivity through the SSID and password. When the Dev-Board is correctly connected to the the Wifi  
 * prints a local IP address. You can access this local IP and verify the message send by the ESP32-S3
*/

#include <WiFi.h>             
#include <WebServer.h>

WebServer server(80);

void setup() {
  Serial.begin(115200);
  const char* ssid     = "IZZI-9EB9";                        // Wifi
  const char* password = "F0AF85519EB9";                     // Password
  
  Serial.println("Start Wifi Conectivity");
  WiFi.disconnect();
  
  Serial.print("Connecting to  ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi Successfully Conected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", message);
  server.begin();
}
void loop() {
  server.handleClient();
  delay(100);
}

void message()  
{
  server.send(200, "text/html", "<h2> This message is from the ESP32-S3. <br> MARCH 2026 MICROCONTROLLERS ITCG-UDG  </h2>");
}
