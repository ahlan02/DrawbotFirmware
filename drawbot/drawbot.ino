#include <Servo.h>
#include <Wire.h>

#include "BNO055_support.h"
#include "imu_drawbot.h"
#include "parse_drawbot.h"
#include "servo_drawbot.h"
// include stepper.h

#define SERVOPIN 5

// structs for initialization
Servo penServo;
struct bno055_t imuDevice;

// struct for bluetooth commands
commandStruct command;

// offset of IMU angle from 0 degrees
signed short imuOffset = 0;

float rotateOffset;

// Define pin connections & motor's steps per revolution
const int dirPin1 = 12;
const int stepPin1 = 13;
const int dirPin2 = 10;
const int stepPin2 = 11;
const int dirPin3 = 8;
const int stepPin3 = 9;
const int dirPin4 = 6;
const int stepPin4 = 7;
const int stepsPerRevolution = 200;



void forwardDrive(int stepsPerRevolution){	// Set motor direction counterclockwise
	digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  digitalWrite(dirPin3, LOW);
  digitalWrite(dirPin4, HIGH);

	// Spin motor quickly
	for(int x = 0; x < stepsPerRevolution; x++)
	{
		digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    digitalWrite(stepPin3, HIGH);
    digitalWrite(stepPin4, HIGH);

		delayMicroseconds(2000);
		digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    digitalWrite(stepPin3, LOW);
    digitalWrite(stepPin4, LOW);
		delayMicroseconds(2000);
	}
  
}

void backwardDrive(int stepsPerRevolution){
  // Set motor direction clockwise
	digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);
  digitalWrite(dirPin3, HIGH);
  digitalWrite(dirPin4, LOW);

	// Spin motor slowly
	for(int x = 0; x < stepsPerRevolution; x++)
	{
		digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    digitalWrite(stepPin3, HIGH);
    digitalWrite(stepPin4, HIGH);

		delayMicroseconds(2000);
		digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    digitalWrite(stepPin3, LOW);
    digitalWrite(stepPin4, LOW);
		delayMicroseconds(2000);
	}

}

void RotateLeft(float deg){
  float deg2;
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, LOW);
  digitalWrite(dirPin3, LOW);
  digitalWrite(dirPin4, LOW);

  while(-5 < deg2 < 5){  
    for(int i = 0; i < stepsPerRevolution;i++){  
      digitalWrite(stepPin1, HIGH);
      digitalWrite(stepPin2, HIGH);
      digitalWrite(stepPin3, HIGH);
      digitalWrite(stepPin4, HIGH);

      delayMicroseconds(4000);
      digitalWrite(stepPin1, LOW);
      digitalWrite(stepPin2, LOW);
      digitalWrite(stepPin3, LOW);
      digitalWrite(stepPin4, LOW);
      delayMicroseconds(4000);
      deg2 = getOrientationOffset(imuOffset, deg);
    Serial.print("Facing Degree: ");
    Serial.println(deg2);
    }
	}

}

void RotateRight(float deg){
  float deg2;
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);
  digitalWrite(dirPin3, HIGH);
  digitalWrite(dirPin4, HIGH);

  while(-5 < deg2 < 5){ 
      for(int i = 0; i < stepsPerRevolution;i++){
        digitalWrite(stepPin1, HIGH);
        digitalWrite(stepPin2, HIGH);
        digitalWrite(stepPin3, HIGH);
        digitalWrite(stepPin4, HIGH);

        delayMicroseconds(4000);
        digitalWrite(stepPin1, LOW);
        digitalWrite(stepPin2, LOW);
        digitalWrite(stepPin3, LOW);
        digitalWrite(stepPin4, LOW);
        delayMicroseconds(4000);
        deg2 = getOrientationOffset(imuOffset, deg);
        Serial.print("Facing Degree: ");
        Serial.println(deg2);
    }
    deg2 += 0.25;
    Serial.print(deg2);
	}
  
}


void setup()
{
	// Declare pins as Outputs
	pinMode(stepPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
	pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  Serial.begin(9600);
  Serial2.begin(9600);

  // initialize servo pin
  penServo.attach(SERVOPIN);

  // initialize IMU
  initIMU(&imuDevice);

  delay(100);
  // offset IMU output
  imuOffset = getIMUOffset();
}
void loop()
{
  Serial.println("STARTING");

  delay(100);
  getCommandStruct(&command);

  Serial.print("Pen State: ");
  Serial.println(command.penState);

  Serial.print("Magnitude: ");
  Serial.println(command.steps);

  Serial.print("Rotation: ");
  Serial.println(command.rotation);

  // raise/lift pen first, maybe lift before rotating
  if(command.penState == 1){
    dropPen(&penServo);
  }else{
    raisePen(&penServo);
  }

  // get struct > pen > rotation > stepper (w/ rotation) > repeat ...
  // rotateOffset = getOrientationOffset(imuOffset, command.rotation);
  // while(!(-5 < rotateOffset < 5)){
  //   if(rotateOffset > 0){
  //     RotateRight(0.25);
  //   }else{
  //     RotateLeft(-0.25);
  //   }
  // }

  RotateRight(command.rotation);  

  forwardDrive(200*command.steps);


  // //forwardDrive(200);
  // RotateRight(5);
  // //backwardDrive(200);
  // //RotateLeft(-5);
  // delay(10000);
  // //BackDrive(400);
  // //delay(100);
}

// #include <Servo.h>
// #include <Wire.h>

// #include "BNO055_support.h"
// #include "imu_drawbot.h"
// #include "parse_drawbot.h"
// #include "servo_drawbot.h"
// // include stepper.h

// #define SERVOPIN 9
// #define CHECK_COUNT 10

// // structs for initialization
// Servo penServo;
// struct bno055_t imuDevice;

// // struct for bluetooth commands
// commandStruct command;

// // offset of IMU angle from 0 degrees
// signed short imuOffset = 0;

// int nSteps = 0;
// int rSteps = 0;

// void setup() {
//   // bluetooth baudrate
//   Serial.begin(9600);

//   // initialize servo pin
//   penServo.attach(SERVOPIN);

//   // initialize IMU
//   initIMU(&imuDevice);

//   delay(100);
//   // offset IMU output
//   imuOffset = getIMUOffset();
// }

// void loop() {
//   // get struct > pen > rotation > stepper (w/ rotation) > repeat ...

//   getCommandStruct(&command); // struct w/ steps, rotation, penState

//   // raise/lift pen first, maybe lift before rotating
//   if(command.penState == 1){
//     dropPen(&penServo);
//   }else{
//     raisePen(&penServo);
//   }

//   Serial.println(getOrientationOffset(imuOffset,320));
//   Serial.println();
//   delay(100);

// }
