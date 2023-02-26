#ifndef BOT_H
#define BOT_H

#include "Arduino.h"
#include "Stepper.h" 


class bot{
  public:
  bot(uint8_t wheelcirc, uint8_t steps);
  void rotateBot(bot, int8_t deg);
  void driveBot(bot, uint8_t steps);
  void Motor_Init(bool O, string MotorName, uint8_t P1, uint8_t P2, uint8_t P3, uint8_t P4, uint8_t steps);
  Motor_Init(0,FR,22,24,26,28,100);
  Motor_Init(1,FL,23,25,27,29,100);
  Motor_Init(0,BR,30,32,34,36,100);
  Motor_Init(1,BL,31,33,35,37,100);
  
  private:
    uint8_t wheelcirc;
    uint8_t steps;

}


#endif
