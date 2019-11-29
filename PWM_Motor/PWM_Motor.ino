
double velocidad = 305;    //variable utilizada para la velocidad

void setup()  { 
  // declara el pin 9 como salida:
  pinMode(9, OUTPUT);
} 

void loop()  { 
  // aplica valor de la variable velocidad al pin 9:
  analogWrite(9, velocidad);    
                     
}
