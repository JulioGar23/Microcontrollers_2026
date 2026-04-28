//Code by: Julio A. García-Rodríguez.

int LED_PRUEBA = 2;

void setup() {
  pinMode(LED_PRUEBA, OUTPUT);     //configuration through pinMode function.
  digitalWrite(LED_PRUEBA, LOW);   //initial state. 
}

void loop() {
  digitalWrite(LED_PRUEBA, HIGH);
  delay(6000);
  digitalWrite(LED_PRUEBA, LOW);
  delay(3000);
}
