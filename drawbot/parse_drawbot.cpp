#include "parse_drawbot.h"

void getPCData(int data[3]){
  while (!Serial.available());
  data[0] = Serial.parseInt();
  data[1] = Serial.parseInt();
  data[2] = Serial.parseInt();
  Serial.readString();
}