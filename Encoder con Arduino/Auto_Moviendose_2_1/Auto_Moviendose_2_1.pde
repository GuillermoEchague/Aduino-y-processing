import processing.serial.*;

Serial PuertoSerial;  // Crea objecto para uso del puerto serial
PImage auto;
int ByteRecibido=0;
float Posicion;
PFont fuente;

void setup(){
size(640,200);
background(255);
println(Serial.list());
String ListaPuertos = Serial.list()[0];    // Crea string en el cual serán leidos los puertos disponibles
PuertoSerial = new Serial(this, ListaPuertos, 115200);
auto = loadImage("auto.png");
fuente = loadFont("ArialMT-24.vlw");
textFont(fuente,24);
}

void draw(){
  fill(255,255,255);
  rect(0,0,width,height);
  image(auto, Posicion, 100, 95,40);
  fill(0,0,255);
  Posicion = leerSerial();
  println(Posicion); 
  text("Posición: ", 0, 30);
  text(int(Posicion), 100, 30);    
}


float leerSerial(){
  char rx_char;
  char[] rx_char_array = {'0','0','0','0','0','0','0','0','0','0','0','0'};
  String rx_string;

  if(PuertoSerial.available() > 0){
    rx_char = char(PuertoSerial.read());
    if (rx_char == 'E'){
      rx_char = char(PuertoSerial.read());
      if (rx_char == 'N'){
        int i = 1;
        rx_char = char(PuertoSerial.read());
         while ((rx_char != ';') && (i < 11)){
           rx_char_array[i] = rx_char;
           rx_char = char(PuertoSerial.read());
           i++;
         }
         PuertoSerial.clear();
         rx_char_array[i] = '.';
        rx_string = new String(rx_char_array);
        if (float(rx_string)!= Float.NaN){
        Posicion = float(rx_string);
        }
      }
    }
  } 
  return Posicion;
}


