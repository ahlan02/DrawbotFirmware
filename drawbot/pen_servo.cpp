#include "pen_servo.h"

void raisePen(Servo *aServo){
  aServo->write(0);
}

void dropPen(Servo *aServo){
  aServo->write(90);
}