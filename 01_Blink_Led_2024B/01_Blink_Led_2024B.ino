//Code by: Julio A. García-Rodríguez.

int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);     //configuration through pinMode function.
  digitalWrite(LED, LOW);   //initial state. 
}

void loop() {
  delay(2000);
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
}
