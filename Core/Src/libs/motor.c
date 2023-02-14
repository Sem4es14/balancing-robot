#include <stm32f1xx_hal.h>
#include <main.h>

void stepperMotor(int speed, int turn) {
	if (speed > 3500) {
		speed = 3500;
	}
	if (speed < -3500) {
		speed = -3500;
	}
	int leftSpeed = speed + turn;
	int rightSpeed = speed - turn;

	if (rightSpeed < 15 && rightSpeed > 0) {
		rightSpeed = 0;
	}
	if (rightSpeed > -15 && rightSpeed < 0) {
		rightSpeed = 0;
	}
	if (leftSpeed < 15 && leftSpeed > 0) {
		leftSpeed = 0;
	}
	if (leftSpeed > -15 && leftSpeed < 0) {
		leftSpeed = 0;
	}
	int rightPeriod;
	int leftPeriod;

	if (rightSpeed > 0) {
		HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_SET);
		rightPeriod = 65000/rightSpeed;
	}
    if (rightSpeed < 0) {
    	HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);
		rightPeriod = 65000/-rightSpeed;
	}
    if (leftSpeed > 0) {
    	HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_SET);
    	leftPeriod = 65000/leftSpeed;
    }
    if (leftSpeed < 0) {
    	HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, GPIO_PIN_RESET);
    	leftPeriod = 65000/-leftSpeed;
	}
    if (leftSpeed == 0 || rightSpeed == 0) {
    	TIM1->CCR2 = leftPeriod;
    	TIM3->CCR1 = rightPeriod;
        return;
    }
    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
    int pwmL = leftPeriod / 2;
    int pwmR = rightPeriod / 2;

    TIM1->ARR = leftPeriod;
    TIM3->ARR = rightPeriod;
    TIM1->CCR2 = pwmL;
    TIM3->CCR1 = pwmR;
}
