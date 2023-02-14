#include "imu.h"
#include "../constants.h"
#include <stm32f1xx_hal.h>
#include "../MadgwickAHRS.h"
#include <math.h>

 void InitMPU6050(I2C_HandleTypeDef *i2c) {
        uint8_t mpuData;
        mpuData = 0;
        HAL_I2C_Mem_Write(i2c, MPU6050_Address, 0x6B, 1, &mpuData, 1, 500); //dont sleep

        mpuData = 0x15;
        HAL_I2C_Mem_Write(i2c, MPU6050_Address, 0x19, 1, &mpuData, 1, 500); //  sample rate = 8kHz / 16 = 500Hz

        mpuData = 0x18;
        HAL_I2C_Mem_Write(i2c, MPU6050_Address, 0x1B, 1, &mpuData, 1, 500); //  gyro full scale = +/- 2000dps

        mpuData = 0x08;
        HAL_I2C_Mem_Write(i2c, MPU6050_Address, 0x1C, 1, &mpuData, 1, 500); //  accelerometer full scale = +/- 4g

        mpuData = 0x01;
        HAL_I2C_Mem_Write(i2c, MPU6050_Address, 0x38, 1, &mpuData, 1, 500); //  enable INTA interrupt*/
}

 int MPU6050Read(uint8_t *mpuData) {
   ///////////////////////////склейка/////////////////
 	int16_t AccelX = (int16_t)(mpuData[0] << 8 | mpuData[1]);
 	int16_t AccelY = (int16_t)(mpuData[2] << 8 | mpuData[3]);
 	int16_t AccelZ = (int16_t)(mpuData[4] << 8 | mpuData[5]);
 	int16_t GyroX = (int16_t)(mpuData[8] << 8 | mpuData[9]);
 	int16_t GyroY = (int16_t)(mpuData[10] << 8 | mpuData[11]);
 	int16_t GyroZ = (int16_t)(mpuData[12] << 8 | mpuData[13]);
 /////////////////////////////обработка////////////////////
     float accel_x = AccelX / 8192.0f;
     float accel_y = AccelY / 8192.0f;
     float accel_z = AccelZ / 8192.0f;
     float gyro_x = GyroX / 939.650784f;
     float gyro_y = GyroY / 939.650784f;
     float gyro_z = GyroZ / 939.650784f;
  /////////////////////////вычисление////////////////////
     MadgwickAHRSupdateIMU(gyro_z, gyro_y, -gyro_x, accel_z, accel_y, -accel_x);

     return (asinf(-2.f * (q1*q3 - q2*q0))) * 100000 + 5500;
 }
