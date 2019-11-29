// Basic H-Bridge Motor Driver Control  
// Author:          Nickolas Andersen
// Original Date:   06/14/2010
//                            Version 1
// Very modified version of "DC Motor Control Using an H-Bridge" from ITP Physical Computing
// http://itp.nyu.edu/physcomp/Labs/DCMotorControl

/*
  High Level Operation:
  User:     Uses serial terminal, PS2 gamepad to send commands.
  Arduino:  Accepts serial commands, PS2 gamepad commands. 
  Arduino:  Controls the SN75441 Dual H-Bridge Motor Driver IC.
*/

// The switchPin allows or disallows motor control.
// The motor's "EN" pin on and set with a value. (on a PWM pin.)
// Motor1A/Motor2A (and Motor3A/4A) can be set HIGH or LOW each so that polarity (spin direction) is set.

// Global Variables
  const int switchPin = 2;    // switch input

  const int motorEN12 = 9;    
  const int motor1A   = 3;
  const int motor2A   = 4;

  const int motorEN34 = 10;
  const int motor3A   = 11;
  const int motor4A   = 12;

  const int ledPin = 13;      // LED

  char SerialValue;

  int speedvalueA = 0 ;  
  int speedvalueB = 0 ;  


void setup() {

  Serial.begin(57600);
  pinMode(switchPin, INPUT); // set the switch as an input:

  // Set Motor pins as output
  pinMode(motorEN12, OUTPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);

  pinMode(motorEN34, OUTPUT);
  pinMode(motor3A, OUTPUT);
  pinMode(motor4A, OUTPUT);

  pinMode(ledPin, OUTPUT);
}


void loop()
  {
  if (Serial.available() > 0)  { Check4SerialCOMMANDS() ; }

  if (digitalRead(switchPin) == HIGH)
    {
    analogWrite(motorEN12, speedvalueA);
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor2A, LOW);
    
    analogWrite(motorEN34, speedvalueB);
    digitalWrite(motor3A, HIGH);
    digitalWrite(motor4A, LOW);
    }
  else
    {
    digitalWrite(motorEN12, LOW);
    digitalWrite(motorEN34, LOW);
    digitalWrite(motor1A, LOW);  
    digitalWrite(motor2A, LOW);  
    digitalWrite(motor3A, LOW);  
    digitalWrite(motor4A, LOW);  
    }
  }
  
  void Check4SerialCOMMANDS()
  {
  SerialValue = Serial.read() ;   // Do a serial data read.
    if (  (SerialValue==('0') or (SerialValue==(char(0)))))    {  speedvalueA = 0;   Serial.print("A="); Serial.print(speedvalueA); Serial.println(" "); return; }  
    if (  (SerialValue==('1') or (SerialValue==(char(1)))))    {  speedvalueA = 51;  Serial.print("A="); Serial.print(speedvalueA); Serial.println(" "); return; }  
    if (  (SerialValue==('2') or (SerialValue==(char(2)))))    {  speedvalueA = 102; Serial.print("A="); Serial.print(speedvalueA); Serial.println(" "); return; }  
    if (  (SerialValue==('3') or (SerialValue==(char(3)))))    {  speedvalueA = 153; Serial.print("A="); Serial.print(speedvalueA); Serial.println(" "); return; }  
    if (  (SerialValue==('4') or (SerialValue==(char(4)))))    {  speedvalueA = 204; Serial.print("A="); Serial.print(speedvalueA); Serial.println(" "); return; }  
    if (  (SerialValue==('5') or (SerialValue==(char(5)))))    {  speedvalueA = 255; Serial.print("A="); Serial.print(speedvalueA); Serial.println(" "); return; }  
    
    if (  (SerialValue==('p') or (SerialValue==(char('p')))))  {  speedvalueB = 0;   Serial.print("B="); Serial.print(speedvalueB); Serial.println(" "); return; }  
    if (  (SerialValue==('q') or (SerialValue==(char('q')))))  {  speedvalueB = 51;  Serial.print("B="); Serial.print(speedvalueB); Serial.println(" "); return; }  
    if (  (SerialValue==('w') or (SerialValue==(char('w')))))  {  speedvalueB = 102; Serial.print("B="); Serial.print(speedvalueB); Serial.println(" "); return; }  
    if (  (SerialValue==('e') or (SerialValue==(char('e')))))  {  speedvalueB = 153; Serial.print("B="); Serial.print(speedvalueB); Serial.println(" "); return; }  
    if (  (SerialValue==('r') or (SerialValue==(char('r')))))  {  speedvalueB = 204; Serial.print("B="); Serial.print(speedvalueB); Serial.println(" "); return; }  
    if (  (SerialValue==('t') or (SerialValue==(char('t')))))  {  speedvalueB = 255; Serial.print("B="); Serial.print(speedvalueB); Serial.println(" "); return; }  
  }

/*
  -------------------------------------------
   DESCRIPCIÓN DE CONEXIONES
  -------------------------------------------
  SN754410 Pinout:Function/Pin Function/Pin
  1,2EN (1)    (16) Vcc1
  1A    (2)    (15) 4A
  1Y    (3)    (14) 4Y
  GND   (4)    (13) GND
  GND   (5)    (12) GND
  2Y    (6)    (11) 3Y
  2A    (7)    (10) 3A
  Vcc2  (8)    (9)  3,4EN 
  
  Main Circuit Wiring:  
  SN754410 to Arduino Hookups:
  SN754410 1,2EN to  Arduino 9
  SN754410 1A to Arduino 3
  SN754410 1Y to Motor +
  SN754410 GND to Circuit Ground
  SN754410 GND to Circuit Ground 
  SN754410 2Y to Motor -
  SN754410 2A to Arduino 4
  SN754410 Vcc2 to External Battery 
  SN754410 3,4EN to Arduino 10
  SN754410 3A to Arduino 11
  SN754410 3Y to Motor + 
  SN754410 GND to Circuit Ground
  SN754410 GND to Circuit Ground
  SN754410 4Y to Motor -
  SN754410 4A to Arduino12
  SN754410 Vcc1 to Arduino 
*/
