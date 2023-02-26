#include "bot.h"


  
bot::bot(float wheelcirc1, int steps1,long speed){
  this->wheelcirc = wheelcirc1;
  this->steps = steps1;
  this->FrontR.setSpeed(speed);
  this->FrontL.setSpeed(speed);
  this->BackR.setSpeed(speed);
  this->BackL.setSpeed(speed);
}

void bot::rotateBot(int deg,int steps){
  int deg2;
  while(deg2 != deg){
  this->FrontR.step(steps);
  this->FrontL.step(-steps);
  this->BackR.step(steps);
  this->BackL.step(-steps);
  }
}

void bot::driveBot(int steps){
  this->FrontR.step(steps);
  this->FrontL.step(steps);
  this->BackR.step(steps);
  this->BackL.step(steps);
}





