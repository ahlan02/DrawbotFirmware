
#ifndef BOT_H
#define BOT_H

#include <Stepper.h>

class bot{
  public:
    bot(float wheelcirc1, int steps1,long speed);
    Stepper FrontR = Stepper(2038,22,24,26,28);
    Stepper FrontL = Stepper(2038,29,27,25,23);
    Stepper BackR = Stepper(2038,30,32,34,36);
    Stepper BackL = Stepper(2038,37,35,33,31);
    void rotateBot(int deg,int steps);
    void driveBot(int steps);
    

  private:
    int wheelcirc;
    int steps;

};


#endif
