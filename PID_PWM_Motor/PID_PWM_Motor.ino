#include <PID_v1.h>
#include <Metro.h>

Metro Delta = Metro(1); // Objeto de timer
double TacoGen = 0;     // Variable para sensar Taco-Generador
double PWM_Motor = 0;   // Variable de control del Motor
double Referencia;      // Punto de Operación
double Control;         // Variable de Control
double Salida;          // Variable para guardar Salida
double Error;           // Variable para guardar el Error
double Kp = 0.50;        // Control proporcional
double Ki = 5.00;          // Control integral
double Kd = 0.05;          // Control derivativo

// Se especican variables y sintonizacion inicial
PID controlPID(&Salida, &Control, &Referencia, Kp, Ki, Kd, DIRECT);

void setup(){ 
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  Serial.flush();
  Referencia = 215;
  TacoGen = analogRead(0)/4;
  controlPID.SetMode(AUTOMATIC);
  controlPID.SetTunings(Kp, Ki, Kd);
  controlPID.SetOutputLimits(-255, 255);
} 

void loop(){
  if (Delta.check() == 1){
    TacoGen = analogRead(0)/4;
    Salida   = TacoGen;
    controlPID.Compute();
    Error   = Referencia - Salida;
    PWM_Motor = Salida + Control;
    if (PWM_Motor > 255){
      PWM_Motor = 255;
    }
    analogWrite(9, PWM_Motor); 
    //Esto es para simular la adquisición de datos
    //TacoGen = PWM_Motor;  

    // Visualizar salida
    Serial.print("Referencia Control Salida Error PWM:\t");
    PrintFloat(Referencia,2);
    PrintFloat(Control,2);
    PrintFloat(Salida,2);
    PrintFloat(Error,2);
    PrintFloat(PWM_Motor,2);
    Serial.println("");
    } else{
    Delta.interval(150);
  }
}
  
  
/************************************************************
Esta función transforma un numero float en una cadena string
para luego imprimirla en el puerto serial.
************************************************************/
void PrintFloat(float num, int finlinea){
   char text[16];
   dtostrf(num, 2, 5, text);
   switch (finlinea){
     case 0:
       Serial.print(text);
       break;
     case 1:
       Serial.println(text);
       break;
     case 2:
       Serial.print(text);
       Serial.print(" ");
       break;
     case 3:
       Serial.print(text);
       Serial.print("\t");
       break;
   }
 } 
/*************************************************************/

                     
