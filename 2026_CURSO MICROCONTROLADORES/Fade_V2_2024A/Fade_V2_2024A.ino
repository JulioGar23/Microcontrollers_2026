//Fade Version 3
//Code by: Julio A. García-Rodríguez.
//

int led = 2;
int brillo = 0;
int incremento = 5;

void setup() {
  ledcAttach(led, 4000, 14);    // ledcAttach is a new command, since 2024.
                                // This function is used to setup LEDC pin with given frequency and resolution. 
                                // LEDC channel will be selected automatically. 
                                // Sintax: bool ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);
                                //         "pin" select LEDC pin.
                                //         "freq" select frequency of pwm.
                                //         "resolution" select resolution for LEDC channel. Range is 1-14 bits (1-20 bits for some versions of ESP32).

  // ledcAttach(0, 4000, 8);    // 4 kHz PWM, 8-bit resolution.
  // Documentation in https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/ledc.html
}

void loop() {
  ledcWrite(led, brillo);
  brillo = brillo + incremento;
  if (brillo <= 0 || brillo >= 16383) {  // if you have selected 8 bits resolution, change 3 to 2^8 = 256
    incremento = -incremento;
  }
  delay(10);
}
