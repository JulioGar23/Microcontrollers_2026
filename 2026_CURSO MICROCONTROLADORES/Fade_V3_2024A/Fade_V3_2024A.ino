// Fade Version 3
// Code by: Julio A. García-Rodríguez.
// 16/04/2024 - Program for IIOT

int led = 2;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  ledcAttachPin(led, 0);       // ledcAttachPin(GPIO, channel)
  ledcSetup(0, 1000, 8);     // ledcSetup(ledChannel, freq, resolution);
}

void loop() {
  ledcWrite(0, brightness);   // ledcWrite(channel, dutycycle)
  brightness = brightness + fadeAmount;
  
  if (brightness <= 0 || brightness >= 255)   // if you have selected 8 bits resolution, change 3 to 2^8 = 256
  {  
    fadeAmount = -fadeAmount;
  }
  delay(20);
}
