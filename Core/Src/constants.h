#define MPU6050_Address     0x68 << 1
#define RAD_TO_DEG          180/3.14159265
#define ACCEL_XOUT_H_REG    0x3B
#define MAX_ANGLE           10000
#define ANG_DIFF_FILT       0.01f
#define SPEED_FILT          0.03f
#define MOTOR_FILT          1.0f
#define SET_SPEED_FILT      0.02f
#define DELTA_TIME          0.002f

#define K_ANG_PROP          1.6f
#define K_ANG_INTEG         25.0f
#define K_ANG_DIFF          0.039f

#define K_SPEED_PROP        7.0f
#define K_SPEED_INTEG       0.044f
#define K_SPEED_DIFF        0.02f

