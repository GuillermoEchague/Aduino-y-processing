
/**
* ControlP5 Toggle
* find a list of public methods available for the Toggle Controller
* at the bottom of this sketch.
* by Andreas Schlegel, 2011
* www.sojamo.de/libraries/controlp5
**/

import processing.serial.*;
import controlP5.*;

ControlP5 cp5;
Serial miPuerto;  // Crea objecto para uso del puerto serial
boolean toggleValue = false;

void setup() {
  size(300,200);
  cp5 = new ControlP5(this);
  
  cp5.addToggle("Encender1")   // Crea un togle button
     .setPosition(60,90)
     .setSize(50,20); 
     
  String ListaPuertos = Serial.list()[0];    // Crea string en el cual serán leidos los puertos disponibles
  miPuerto = new Serial(this, ListaPuertos, 9600);
}
  

void draw() {
  background(0);
  ellipse(210,100,100,100);
  
  if(toggleValue==true){
    fill(255,255,255);
    miPuerto.write(255);            // envía un 1 por el puerto serial

  } else {
    fill(64,64,64);
    miPuerto.write(0);            // envía un 0 por el puerto serial
  }

}

