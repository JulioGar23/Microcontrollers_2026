#include <WiFi.h>
#include <PubSubClient.h> 

#define WIFI_SSID "IZZI-9EB9"
#define WIFI_PASS "F0AF85519EB9"

// --- ThingsBoard Configuration 
#define TB_SERVER   "mqtt.thingsboard.cloud"
#define TB_PORT     1883
#define TB_TOKEN "5Snzt33iMuPu9x0vOLVS"
//#define TB_TOKEN "SsWpi2n5S6WYJUm3sOTh"
//#define TB_TOKEN    "0GhKbrdrUcb0vVgTvO87" 
//#define TB_TOKEN    "WKqDeQ0UoCd9Sfj34fMs" // Access Token

const int sensorPin = 4;

// --- Clients ---
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

// --- Delay to server ---
// Send data to server each 5 seconds (5000 ms)
long lastMsg = 0;
long msgFrequency = 5000;

void setup() {
  Serial.begin(115200); 
  pinMode(sensorPin, INPUT);
  setup_wifi();
  mqttClient.setServer(TB_SERVER, TB_PORT); //MQTT configuration
}


void setup_wifi() {         // Function of Wifi Setup
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n¡WiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void reconnect_mqtt() {       //MQTT reconnection
  while (!mqttClient.connected()) {
    Serial.print("Trying to reconnect to MQTT...");
    if (mqttClient.connect("MyClientESP32-Light", TB_TOKEN, NULL)) {
      Serial.println("¡Connected!");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" Trying in 5 seconds...");
      delay(5000);
    }
  }
}

void loop() {                             // If we lost Wifi, reconnect function.
  if (WiFi.status() != WL_CONNECTED) {
    setup_wifi();
  }

  if (!mqttClient.connected()) {          // If we lost MQTT, reconnect function.
    reconnect_mqtt();
  }
  
  mqttClient.loop();                      // This line keeps MQTT connection.

  // ----- Principal logic -----
  
  // 1. Send data with millis function. Better than delay. 
  long now = millis();
  if (now - lastMsg > msgFrequency) {
    lastMsg = now;

    // 2. Read sensor
    int lightValue = analogRead(sensorPin);
    Serial.print("Photorresistor Sensor Value:  ");
    Serial.println(lightValue);

    // 2. Create JSON message. 
    // We use "light" as telemetry "Key".
    char jsonPayload[100];
    snprintf(jsonPayload, 100, "{\"light\":%d}", lightValue);

    // 3. Publish the message
    Serial.print("Publishing in ThingsBoard: ");
    Serial.println(jsonPayload);
    mqttClient.publish("v1/devices/me/telemetry", jsonPayload);
  }
}
