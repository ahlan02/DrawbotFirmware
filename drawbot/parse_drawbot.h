#ifndef PARSE_DRAWBOT_H_
#define PARSE_DRAWBOT_H_

#include <hardwareSerial.h>

struct commandStruct{
  float steps;
  float rotation;
  float penState;
}typedef commandStruct;

void getCommandStruct(struct commandStruct * command);

#endif // PARSE_DRAWBOT_H_