/*  
    Microcontrollers 2026
    J.A. García.Rodríguez
    04.041 - ESP32-S3 Digital Input with Button Example

    This sketch demonstrates reading a pushbutton input and driving an LED.

    When the button is pressed, the LED turns on.
    When released, the LED turns off.

    Board: ESP32-S3 DevKit (e.g. DevKitC-1 N16R8)

    Components
    ----------
    - LED + resistor (e.g. 330Ω)
    - Pushbutton + 10kΩ pull-down resistor (or use internal pull-down)

    Connections
    -----------
    ESP32-S3 DevKit | Component
    --------------------------
    GND             | LED cathode
    GPIO4           | LED anode via resistor
    GND             | Pushbutton ground pin
    GPIO5           | Pushbutton signal pin (with 10kΩ pull-down to GND)
*/



// a) Reading a push button.

const byte LED_GPIO = 4;       // output LED pin
const byte BUTTON_GPIO = 5;    // input button pin

int buttonState = 0;

void setup() {
  pinMode(LED_GPIO, OUTPUT);
  pinMode(BUTTON_GPIO, INPUT_PULLDOWN);
}

void loop() {
  buttonState = digitalRead(BUTTON_GPIO);

  if (buttonState == HIGH) {
    digitalWrite(LED_GPIO, HIGH);
  } else {
    digitalWrite(LED_GPIO, LOW);
  }
}



//b) Reading a push button with delay to OFF
/*
const byte LED_GPIO = 4;       
const byte BUTTON_GPIO = 5;    

int buttonState = 0;

void setup() {
  pinMode(LED_GPIO, OUTPUT);
  pinMode(BUTTON_GPIO, INPUT_PULLDOWN);
}

void loop() {
  buttonState = digitalRead(BUTTON_GPIO);

  if (buttonState == HIGH) {
    digitalWrite(LED_GPIO, HIGH);
    delay(3000);
    digitalWrite(LED_GPIO, LOW);
  }
}*/

 
//c) Toggle Function.
/*
const byte LED_GPIO = 4;
const byte BUTTON_GPIO = 5;

bool ledState = false;
bool lastButtonState = LOW;

void setup() {
  pinMode(LED_GPIO, OUTPUT);
  pinMode(BUTTON_GPIO, INPUT_PULLDOWN);
  digitalWrite(LED_GPIO, LOW);
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_GPIO);

  if (lastButtonState == LOW && currentButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(LED_GPIO, ledState);
  }
  lastButtonState = currentButtonState;
}*/


// d) Blinking while button is 	pressed.
/*
const byte LED_GPIO = 4;
const byte BUTTON_GPIO = 5;

void setup() {
  pinMode(LED_GPIO, OUTPUT);
  pinMode(BUTTON_GPIO, INPUT_PULLDOWN);
}

void loop() {
  if (digitalRead(BUTTON_GPIO) == HIGH) {
    digitalWrite(LED_GPIO, HIGH);
    delay(50);
    digitalWrite(LED_GPIO, LOW);
    delay(50);
  } else {
    digitalWrite(LED_GPIO, LOW);
  }
}
*/

/*
//e) Long pulsation and short 	pulsation.
const byte LED_GPIO = 4;
const byte BUTTON_GPIO = 5;

unsigned long pressTime = 0;
bool lastButtonState = LOW;

void setup() {
  pinMode(LED_GPIO, OUTPUT);
  pinMode(BUTTON_GPIO, INPUT_PULLDOWN);
  digitalWrite(LED_GPIO, LOW);
}

void loop() {
   bool currentButtonState = digitalRead(BUTTON_GPIO);
  
  if (lastButtonState == LOW && currentButtonState == HIGH) {
    pressTime = millis();
  }

  if (lastButtonState == HIGH && currentButtonState == LOW && pressTime > 0) {
    unsigned long duration = millis() - pressTime;
    pressTime = 0;

    if (duration < 2000) {
      digitalWrite(LED_GPIO, HIGH);
      delay(250);
      digitalWrite(LED_GPIO, LOW);
      delay(250);
      digitalWrite(LED_GPIO, HIGH);
      delay(250);
      digitalWrite(LED_GPIO, LOW);
      delay(250);
    } else {
      digitalWrite(LED_GPIO, HIGH);
    }
  }
  lastButtonState = currentButtonState;
}*/



 //f) Push Button modes for 	each pulsation
const byte LED_GPIO = 4;
const byte BUTTON_GPIO = 5;

int mode = 0;
bool lastButton = LOW;

void setup() {
  pinMode(LED_GPIO, OUTPUT);
  pinMode(BUTTON_GPIO, INPUT_PULLDOWN);
}

void loop() {
  bool currentButton = digitalRead(BUTTON_GPIO);

  if (lastButton == HIGH && currentButton == LOW) {
    mode = (mode + 1) % 4;
  }

  switch (mode) {
    case 0: digitalWrite(LED_GPIO, LOW); break;
    case 1: digitalWrite(LED_GPIO, HIGH); break;
    case 2:
      digitalWrite(LED_GPIO, millis() / 800 % 2);
      break;
    case 3:
      digitalWrite(LED_GPIO, millis() / 200 % 2);
      break;
  }

  lastButton = currentButton;
}



