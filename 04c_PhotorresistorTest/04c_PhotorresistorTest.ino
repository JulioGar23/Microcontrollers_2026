/*
  Microcontrollers 2026
  J.A. García.Rodríguez
  
  This Arduino code reads and displays the analog value from
  a photoresistance sensor connected to an ESP32-S3 Development 
  Board. It continuously measures the light intensity detected 
  by the sensor and outputs the readings to the serial monitor.

  Board: ESP32-S3 Development Board
  Component: Photoresistance Sensor Module
*/

// Define the pin numbers for the photoresistance sensor module
const int sensorPin = 4;

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate
}

void loop() {
  Serial.println(analogRead(sensorPin));  // Read the analog value of the sensor and print it to the serial monitor
  delay(1000);                            // Wait for 1000 milliseconds
}