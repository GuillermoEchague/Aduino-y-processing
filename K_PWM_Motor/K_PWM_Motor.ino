#include <PID_v1.h>
#include <Metro.h>

Metro Delta = Metro(100); // Objeto de timer
float TacoGen = 0;     // Variable para sensar Taco-Generador
float PWM_Motor = 0;   // Variable de control del Motor
float SetPoint = 250;  // Punto de Operación
float Input;           // Variable para guardar Entrada
float Output;          // Variable para guardar Salida
float Error = 0;       // Variable para calcular Error
float Kp = 0.5;        // Control proporcional

void setup(){ 
  pinMode(9, OUTPUT);
  TacoGen = analogRead(0)/4;
  Serial.begin(9600);
  Serial.flush();
} 

void loop(){
  if (Delta.check() == 1){
    TacoGen = analogRead(0)/4;
    Output  = TacoGen;
    Input   = SetPoint;
    Error   = SetPoint - Output;
    PWM_Motor = Input + Kp*Error;
    analogWrite(9, PWM_Motor); 
    //Esto es para simular la adquisición de datos
    //TacoGen = PWM_Motor;  

    // Visualizar salida
    Serial.print("Entrada  Salida  Error  PWM:\t");
    PrintFloat(Input,2);
    PrintFloat(Output,2);
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
       Serial.print("  ");
       break;
     case 3:
       Serial.print(text);
       Serial.print("\t");
       break;
   }
 } 
/*************************************************************/

                     
