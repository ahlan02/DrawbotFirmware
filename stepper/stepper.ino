#include <Stepper.h>

#include "bot.h"

bot bot1 = bot(8.04,4076,5);
//bot bot2 = bot (???,2038,15);

void setup(){
}

void loop(){
  bot1.driveBot(2038);
}
