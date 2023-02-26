#include "imu_drawbot.h"

/**
  * @brief Initializes BNO055
  * @param  imuDevice IMU device struct
  */
void initIMU(struct bno055_t *imuDevice){
  Wire.begin();
  BNO_Init(imuDevice);
  bno055_set_operation_mode(OPERATION_MODE_NDOF);
  delay(1);
}



/**
  * @brief Initializes BNO055
  */
signed short getIMUOffset(){
  signed short initOrientation;

  bno055_read_euler_h(&initOrientation);

  return (5760 - initOrientation);
}



/**
  * @brief Initializes BNO055
  * @param  imuOffset IMU output offset, from getIMUOffset()
  * @param  targetAngle angle bot should be facing
  */
float getOrientationOffset(signed short imuOffset, float targetAngle){
  signed short imuAngle; // angle output from imu
  float currAngle;       // angle output in degrees  
  float difference;      // displacement between target and current

  bno055_read_euler_h(&imuAngle);

  currAngle = float((imuAngle + imuOffset)%5760) / 16.00;

  difference = targetAngle - currAngle;
  
  if(difference > 180){
    difference -= 360;
  }else if(difference < -180){
    difference += 360;
  }

  return difference;
}