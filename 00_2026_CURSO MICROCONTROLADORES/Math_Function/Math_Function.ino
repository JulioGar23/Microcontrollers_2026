
// Microcontrollers Workshop 
// 02 Program - Calculator

float angulo = 0.0; 

void setup() {
  Serial.begin(115200);
}

void loop() {
  float seno = sin(angulo);
  float coseno = cos(angulo);         // Valores de las funciones

                                // Para graficar varias líneas, sepáralas con una COMA o un ESPACIO.
  Serial.print(seno);           // Se envian datos al Serial Plotter
  Serial.print(" ");            // Espacio separador para la segunda variable
  Serial.println(coseno);       // El println indica el final del punto actual

  angulo += 0.05;               // Se incrementa el ángulo para que la onda avance.

  
  if (angulo > 6.28) {          // Si el ángulo es muy grande, lo reiniciamos para evitar errores de precisión
    angulo = 0; 
  }

  delay(5);                    // Velocidad de la animacion.
}
