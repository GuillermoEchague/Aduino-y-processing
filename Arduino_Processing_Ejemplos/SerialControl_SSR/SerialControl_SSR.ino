/*

 */

int Valor;

void setup() {
  Serial.begin(9600);           // Inicializar serial.
  pinMode(9, OUTPUT);           // Pin 9 como salida. 
}

void loop() {
  if (Serial.available()){
    Valor = Serial.read();
    Serial.flush();
    analogWrite(9, Valor);    // Activación pin 9, activar SSR
  }
}

