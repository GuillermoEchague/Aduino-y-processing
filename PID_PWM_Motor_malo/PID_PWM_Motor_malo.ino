#include <PID_v1.h>

int lectura = 0;    //variable utilizada para la velocidad
int divisor = 8;
int visor = 1;

double Setpoint, TacoGen, Velocidad;
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=10, consKi=0.05, consKd=0.25;

PID myPID(&TacoGen, &Velocidad, &Setpoint,consKp, consKi, consKd, DIRECT);


void setup(){ 
  // declara el pin A0 como entrada analogica:
  pinMode(9, OUTPUT);
  TacoGen = analogRead(0);
  myPID.SetMode(AUTOMATIC);
  // declara el pin 9 como salida:

   Serial.begin(9600);
   Setpoint = 150;
} 

void loop()  { 

  TacoGen = analogRead(0);
  double gap = abs(Setpoint-TacoGen); //distance away from setpoint
  
  if(gap<10)
  {  //we're close to setpoint, use conservative tuning parameters
    myPID.SetTunings(consKp, consKi, consKd);
  }
  else
  {
     //we're far from setpoint, use aggressive tuning parameters
     myPID.SetTunings(aggKp, aggKi, aggKd);
  }
  
  myPID.Compute();
  analogWrite(9, Velocidad);
  
  visor = 1*Velocidad;
  if (Velocidad > 0){
  Serial.print(Velocidad);
  Serial.println("");
  }

                     
}
