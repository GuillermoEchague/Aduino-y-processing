//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int buzzer = 9;  //Declara Pin del buzzer
int tono = 0;    //Declara Pin del potenciómetro
 
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
  // No se configuran parámetros inciales, pero se debe 
  //  colocar el encabezado de la función setup()
}
 
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{           //  cuando este energizado el Arduino
 
  //Variable entera donde se almacena el valor del potenciómetro
  int sensor = analogRead(tono);
 
  //Variable donde se escala la frecuencia de 100 a 5000Hz
  int frecuencia = map(sensor,0,1023,100,5000);
 
  //Variable entera para guardar el tiempo deseado en ms
  int duracion = 250;
 
  //Funcion tone(), que recibe:
  //  1ra posición: Pin del elemento sonoro
  //  2da posición: Frecuencia deseada en Hz
  //  3ra posición: Duración del tono
  tone(buzzer, frecuencia, duracion);
 
  //Retardo
  delay(100);
}

