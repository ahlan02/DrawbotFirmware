#ifndef BOT_H
#define BOT_H

#define STEPS 100;

//typedef struct bot;
class bot{
  public:
  bot(uint8_t wheelcirc, uint8_t steps);
  Stepper FL(STEPS,22,24,26,28);
  Stepper FR(STEPS,23,25,27,29);
  Stepper BL(STEPS,30,32,34,36);
  Stepper BR(STEPS,31,33,35,37);
  void rotateBot(&bot, int8_t deg);
  void driveBot(&bot, uint8_t steps);

  private:
    uint8_t wheelcirc;
    uint8_t steps;

}


#endif
