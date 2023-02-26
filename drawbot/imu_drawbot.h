#ifndef IMU_DRAWBOT_H_
#define IMU_DRAWBOT_H_

#include "BNO055_support.h"
#include <Wire.h>

void initIMU(struct bno055_t *myBNO);

signed short getIMUOffset();

float getOrientationOffset(signed short imuOffset, float targetAngle);

#endif // IMU_DRAWBOT_H_