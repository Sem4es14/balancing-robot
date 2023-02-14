#include <stm32f103xb.h>
#include <stm32f1xx_hal.h>
void InitMPU6050(I2C_HandleTypeDef *i2c);
int MPU6050Read(uint8_t *mpuData);
