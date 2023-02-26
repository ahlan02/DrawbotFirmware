#include <Stepper.h>
#include "bot.h"

void rotateBot(bot, int8_t deg){

}

void driveBot(bot, uint8_t steps){
  
}

void Motor_Init(bool O, String MotorName, uint8_t P1, uint8_t P2, uint8_t P3, uint8_t P4, uint8_t steps){
  if(O == 0){
    Stepper MotorName(steps,P1,P2,P3,P4);
  }
  elif(O == 1){
    Stepper MotorName(steps,P4,P3,P2,P1);
  }
}

