################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/libs/control.c \
../Core/Src/libs/imu.c \
../Core/Src/libs/motor.c 

OBJS += \
./Core/Src/libs/control.o \
./Core/Src/libs/imu.o \
./Core/Src/libs/motor.o 

C_DEPS += \
./Core/Src/libs/control.d \
./Core/Src/libs/imu.d \
./Core/Src/libs/motor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/libs/%.o Core/Src/libs/%.su: ../Core/Src/libs/%.c Core/Src/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-libs

clean-Core-2f-Src-2f-libs:
	-$(RM) ./Core/Src/libs/control.d ./Core/Src/libs/control.o ./Core/Src/libs/control.su ./Core/Src/libs/imu.d ./Core/Src/libs/imu.o ./Core/Src/libs/imu.su ./Core/Src/libs/motor.d ./Core/Src/libs/motor.o ./Core/Src/libs/motor.su

.PHONY: clean-Core-2f-Src-2f-libs

