
#ifndef BOT_H
#define BOT_H

//#include <Stepper.h>
//#include "Arduino.h"  

using namespace std;

class bot{
  public:
    bot(int wheelcirc1, int steps1);
    void rotateBot(bot &bot, int deg);
    void driveBot(bot &bot, int steps);
    Stepper FrontR(2038,22,24,26,28);
    Stepper FrontL(2038,29,27,25,23);
    Stepper BackR(2038,30,32,34,36);
    Stepper BackL(2038,37,35,33,31);
  
  private:
    int wheelcirc;
    int steps;

};


#endif
