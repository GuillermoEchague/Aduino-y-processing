import processing.serial.*;

Serial PuertoSerial;  // Crea objecto para uso del puerto serial
PImage auto;
int ByteRecibido=0;
int Posicion=0;
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
  text("Posición: ", 0, 30);
  text(Posicion, 100, 30);
  println(Posicion);

  
  if (PuertoSerial.available() >0) {
    ByteRecibido = PuertoSerial.read();
    if ((ByteRecibido) == '-'){
      Posicion = Posicion-1;
    }
    
    if ((ByteRecibido) == '+'){
      Posicion = Posicion+1;
    }
    
    if(Posicion > 640){
      Posicion = 640;
    }
    
    if(Posicion < 0){
      Posicion = 0;
    }



  }
}
