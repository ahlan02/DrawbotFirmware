#include "imu_drawbot.h"

void initIMU(struct bno055_t *myBNO){
  Wire.begin();
  BNO_Init(myBNO);
  bno055_set_operation_mode(OPERATION_MODE_NDOF);
  delay(1);
}

signed short getOffset(){
  signed short initOrientation;

  delay(100);
  bno055_read_euler_h(&initOrientation);
  delay(100);

  return (5760 - initOrientation);
}

float fixOrientation(signed short offset, unsigned int targetAngle){
  signed short orientation;
  float currAngle;

  bno055_read_euler_h(&orientation);

  currAngle = float((orientation + offset)%5760) / 16.00;

  return (targetAngle - currAngle);
}