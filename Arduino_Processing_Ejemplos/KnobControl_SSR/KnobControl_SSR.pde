

/**
* ControlP5 Toggle
* find a list of public methods available for the Toggle Controller
* at the bottom of this sketch.
* by Andreas Schlegel, 2011
* www.sojamo.de/libraries/controlp5
**/

import processing.serial.*;
import guicomponents.*;


Serial miPuerto;  // Crea objecto para uso del puerto serial
GKnob knob0;
int valor = 0;

void setup() {
  size(300,200);   
  String ListaPuertos = Serial.list()[0];    // Crea string en el cual serán leidos los puertos disponibles
  miPuerto = new Serial(this, ListaPuertos, 9600);
  knob0 = new GKnob(this, 30, 50, 100, 110, 60);
  knob0.setLimits(0, 0, 255);
  knob0.setControlMode(GKnob.CTRL_ANGULAR);
  knob0.setBezelWidth(10);
}

void draw() {
  background(0);
  ellipse(210,100,100,100);
  fill(valor);
  
  if (knob0.isValueChanging()) {
    valor = knob0.getValue();
    miPuerto.write(valor);            // envía el valor por el puerto serial
  }
}

