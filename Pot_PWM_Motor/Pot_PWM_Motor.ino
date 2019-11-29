
int lectura = 0;    //variable utilizada para la velocidad
int PotPin = A0;        // selecciona el pin de entrada para el potenciometro
int divisor = 8;
int velocidad = 0;


void setup(){ 
  // declara el pin 9 como salida:
  pinMode(9, OUTPUT);
   Serial.begin(9600);

} 

void loop()  { 
  // aplica valor de la variable velocidad al pin 9:
  lectura = analogRead(PotPin);
  velocidad = lectura/divisor;
  analogWrite(9, velocidad);
  Serial.println(velocidad);

                     
}
