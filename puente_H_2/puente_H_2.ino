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
  const int motorEN12 = 9;    
  const int motor1A   = 3;
  const int motor2A   = 4;
  const int ledPin = 13;      // LED
  const int sensorPin = A0;    // select the input pin for the potentiometer
  
  int speedvalueA = 0 ;  
  int speedvalueB = 0 ;  
  int sensorValue = 0;


void setup() {

  Serial.begin(9600);
  // Set Motor pins as output
  pinMode(motorEN12, OUTPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor2A, LOW);
}


void loop()
  {
    sensorValue = analogRead(sensorPin);  
    Serial.println(sensorValue);
    analogWrite(motorEN12, sensorValue);


 }
  
 
