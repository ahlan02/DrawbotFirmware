#ifndef IMU_DRAWBOT_H_
#define IMU_DRAWBOT_H_

#include "BNO055_support.h"		//Contains the bridge code between the API and Arduino
#include <Wire.h>

void initIMU(struct bno055_t *myBNO);

signed short getOffset();

float fixOrientation(signed short offset, unsigned int targetAngle);

#endif // IMU_DRAWBOT_H_