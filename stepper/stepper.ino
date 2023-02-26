
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

		delayMicroseconds(1000);
		digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    digitalWrite(stepPin3, LOW);
    digitalWrite(stepPin4, LOW);
		delayMicroseconds(1000);
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

		delayMicroseconds(1000);
		digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    digitalWrite(stepPin3, LOW);
    digitalWrite(stepPin4, LOW);
		delayMicroseconds(1000);
	}

}

void RotateLeft(float deg){
  float deg2 = 0;
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, LOW);
  digitalWrite(dirPin3, LOW);
  digitalWrite(dirPin4, LOW);

  while(deg2!=deg){  
    for(int i = 0; i < stepsPerRevolution;i++){  
      //rei poll here
      digitalWrite(stepPin1, HIGH);
      digitalWrite(stepPin2, HIGH);
      //digitalWrite(stepPin3, HIGH);
      //digitalWrite(stepPin4, HIGH);

      delayMicroseconds(4000);
      digitalWrite(stepPin1, LOW);
      digitalWrite(stepPin2, LOW);
      //digitalWrite(stepPin3, LOW);
      //digitalWrite(stepPin4, LOW);
      delayMicroseconds(4000);
    }
    deg2-=1;
	}

}

void RotateRight(float deg){
  float deg2 = 0;
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);
  digitalWrite(dirPin3, HIGH);
  digitalWrite(dirPin4, HIGH);

  while(deg2!=deg){ 
      for(int i = 0; i < stepsPerRevolution;i++){
        //rei poll here
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
    }
    deg2 += 1;
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
}
void loop()
{
  //forwardDrive(200);
  RotateRight(5);
  //backwardDrive(200);
  //RotateLeft(-5);
  delay(10000);
  //BackDrive(400);
  //delay(100);
}
