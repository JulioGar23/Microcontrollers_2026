
// Microcontrollers Workshop 
// 02 Program - Calculator 


void setup() {
  Serial.begin(115200);
  delay(1000); 
  Serial.println("\n--- BIENVENIDO A LA CALCULADORA ESP32 ---");
  imprimirMenu();
}

void loop() {
  if (Serial.available() > 0) {
    Serial.println("Introduce el primer número:");     // Pedir el primer número
    while (Serial.available() == 0);                  // Esperar a que el usuario escriba
    float num1 = Serial.parseFloat();
    limpiarBuffer();
    Serial.print("Número 1: "); Serial.println(num1);

    Serial.println("Introduce el segundo número:");     // Pedir el segundo número
    while (Serial.available() == 0);
    float num2 = Serial.parseFloat();
    limpiarBuffer();
    Serial.print("Número 2: "); Serial.println(num2);

    Serial.println("Elige operación: (+, -, *, /)");     // Pedir la operación
    while (Serial.available() == 0);
    char operacion = Serial.read();
    limpiarBuffer();

    Serial.print("Resultado: ");                        // Procesar resultado
    switch (operacion) {
      case '+':
        Serial.println(num1 + num2);
        break;
      case '-':
        Serial.println(num1 - num2);
        break;
      case '*':
        Serial.println(num1 * num2);
        break;
      case '/':
        Serial.println(num1 / num2);
        break;
      default:
        Serial.println("Operación no válida.");
        break;
    }

    Serial.println("---------------------------------------");
    delay(2000);
    imprimirMenu();
  }
}

// Función para limpiar el buffer 
void limpiarBuffer() {
  while (Serial.available() > 0) {
    Serial.read(); 
  }
}

void imprimirMenu() {
  Serial.println("\nListo para una nueva operación.");
  Serial.println("Escribe cualquier cosa para comenzar...");
}
