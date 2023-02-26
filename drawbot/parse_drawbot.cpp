#include "parse_drawbot.h"

void getCommandStruct(struct commandStruct * command){
  while (!Serial2.available());
  Serial2.flush();
  while (!Serial2.available());
  Serial2.find("[");
  while (!Serial2.available());
  command->penState = Serial2.parseFloat();
  while (!Serial2.available());
  command->rotation = Serial2.parseFloat();
  while (!Serial2.available());
  command->steps = Serial2.parseFloat();

  while (!Serial2.available());
  Serial2.find("]");
}