#include <PString.h>
 char buffer_tx[16];
 PString str(buffer_tx, sizeof(buffer_tx));

// Leer Encoder
// Conectar encoder a pines 3 y 4 digital
 int   encoder0Pos = 0;
 int   encoder0PinA = 3;
 int   encoder0PinB = 4;
 int   encoder0PinA_Actual = LOW;
 int   encoder0PinA_Ultimo = LOW;

void setup() { 
   pinMode(encoder0PinA,INPUT);
   pinMode(encoder0PinB,INPUT);
   Serial.begin(115200);
   Serial.print("Inicio: ");
   str.begin();
   str.println("EN000000");
   Serial.print(str);
 } 

 void loop() { 
   encoder0PinA_Actual = digitalRead(encoder0PinA);
   if ((encoder0PinA_Ultimo == LOW) && (encoder0PinA_Actual == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
     } else {
       encoder0Pos++;
     }
     str.begin();
     str.print("EN"); 
     str.print(encoder0Pos);
     str.print(";");
     Serial.println(str);
   } 
   encoder0PinA_Ultimo = encoder0PinA_Actual;
 } 
