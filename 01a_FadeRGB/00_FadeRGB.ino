void setup() {
  // No initialization needed for RGB LED
}

void loop() {
  for (int r = 0; r <= 255; r++) {
    rgbLedWrite(RGB_BUILTIN, r, 0, 0); // fade rojo
    delay(10);
  }

  for (int r = 255; r >= 0; r--) {
    rgbLedWrite(RGB_BUILTIN, r, 0, 0);
    delay(10);
  }

  for (int g = 0; g <= 255; g++) {
    rgbLedWrite(RGB_BUILTIN, 0, g, 0); // fade rojo
    delay(10);
  }

  for (int g = 255; g >= 0; g--) {
    rgbLedWrite(RGB_BUILTIN, 0, g, 0);
    delay(10);
  }

  for (int b = 0; b <= 255; b++) {
    rgbLedWrite(RGB_BUILTIN, 0, 0, b); // fade rojo
    delay(10);
  }

  for (int b = 255; b >= 0; b--) {
    rgbLedWrite(RGB_BUILTIN, 0, 0, b);
    delay(10);
  }
}