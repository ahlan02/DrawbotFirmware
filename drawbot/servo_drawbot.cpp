#include "servo_drawbot.h"

/**
  * @brief Raises pen for not drawing
  * @param  aServo servo device struct
  */
void raisePen(Servo *aServo){
  aServo->write(0);
}

/**
  * @brief Drops pen for drawing
  * @param  aServo servo device struct
  */
void dropPen(Servo *aServo){
  aServo->write(90);
}