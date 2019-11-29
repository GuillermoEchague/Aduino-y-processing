// Leer Encoder
// Conectar encoder a pines 3 y 4 digital

 int encoder0Pos = 0;
 int encoder0PinA = 3;
 int encoder0PinB = 4;
 int encoder0PinA_Actual = LOW;
 int encoder0PinA_Ultimo = LOW;
 int numero_vueltas = 8;
 
 void setup() { 
   pinMode(encoder0PinA,INPUT);
   pinMode(encoder0PinB,INPUT);
   Serial.begin(115200);
 } 

 void loop() { 
   encoder0PinA_Actual = digitalRead(encoder0PinA);
   if ((encoder0PinA_Ultimo == LOW) && (encoder0PinA_Actual == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       //encoder0Pos--;
       Serial.print('-'); 
     } else {
       //encoder0Pos++;
       Serial.print('+');
     } 
   } 
   encoder0PinA_Ultimo = encoder0PinA_Actual;
 } 

