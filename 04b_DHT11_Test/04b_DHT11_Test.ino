/*  Microcontrollers 2026
    J.A. García.Rodríguez
    WiFi Test for ESP32-S3.

  *This sketch test ESP32-S3 configuration with DHT11 humidity/temperature sensor 
  *REQUIRES the following Arduino libraries:
     - DHT Sensor Library by adafruit. Go to: Sketch -> Include library -> Manage Libraries -> Find DHT sensor library by Adafruit
*/

#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   

// NOTE: If using a board with 3.3V logic like an ESP32S3 connect DHT11 VCC to 3.3V. 


DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor.

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT11 test!"));
  dht.begin();
}

void loop() {
  delay(250);

  float h = dht.readHumidity();                 // Sensor readings take between 250 ms to 2 seconds (its a very slow sensor).
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {                   // Check if any reads failed and exit early (to try again).
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);                   // Compute heat index in Fahrenheit (the default)
  float hic = dht.computeHeatIndex(t, h, false);            // Compute heat index in Celsius (isFahreheit = false)

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}