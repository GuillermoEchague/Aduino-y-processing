/**
  Ejemplo que muestra el uso del puerto serial para enviar comandos
 */


import processing.serial.*;

Serial miPuerto;  // Crea objecto para uso del puerto serial

void setup() 
{
  size(200, 200);    // Crea ventada de programa de tamaño 200x200 pixeles
  String ListaPuertos = Serial.list()[0];    // Crea string en el cual serán leidos los puertos disponibles
  miPuerto = new Serial(this, ListaPuertos, 9600);
}

void draw() {
  background(255);                // Color de fondo de la ventana
  rect(50, 50, 100, 100);         // Crea un cuadrado en el punto (50,50) de lado 100x100

  if (mouseSobreCuadrado() == true) {  // Si el mouse está sobre el cuadrado,
    fill(204);                    // cambia color y 
    miPuerto.write(255);            // envía un 1 por el puerto serial
  } 
  else {                          // Si el mouse se sale del cuadrado,
    fill(0);                      // cambia color y
    miPuerto.write(0);            // envía un 0 por el puerto serial
  }
}


// Función que testea si mouse está sobre cuadrado
boolean mouseSobreCuadrado() {    
  return ((mouseX >= 50) && (mouseX <= 150) && (mouseY >= 50) && (mouseY <= 150));
}

