/*
  Blink
 */

int retardo = 10000;

void setup() {                
  // Inicializa pin 9 digital como salida
  // SSR está conectado a pin 9:
  pinMode(9, OUTPUT);     
}

void loop() {
  digitalWrite(9, HIGH);   // Activación pin 9, activación SSR
  delay(retardo);          // Esperar 1 seg.
  digitalWrite(9, LOW);    // Desactivar pin 9
  delay(retardo);          // Esperar 1 seg.
}
