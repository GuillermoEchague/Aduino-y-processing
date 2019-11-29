/*
 Fading con SSR
 
 Este ejemplo muestra la combinación de un SSR controlado mediante PWM.
 Lo que provoca disminuir o aumentar la corriente RMS en una ampolleta,
 este efecto dimer aumenta o disminuye el nivel de iluminación de forma
 proporcional. 
 */


int ledPin = 9;    // SSR conectado a pin 9
int salto = 1;
int retardo = 10;
  
void setup()  { 

} 

void loop()  { 
  // Encendido gradual con aumentos de x saltos:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue += salto) { 
    analogWrite(ledPin, fadeValue);         
    delay(retardo);                            
  } 

  // Apagado gradual con disminución de x saltos:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=salto) { 
    analogWrite(ledPin, fadeValue);         
    delay(retardo);                            
  } 
}


