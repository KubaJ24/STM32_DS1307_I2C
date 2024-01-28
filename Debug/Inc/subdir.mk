################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/DS1307_I2C.c \
../Inc/i2c1.c 

OBJS += \
./Inc/DS1307_I2C.o \
./Inc/i2c1.o 

C_DEPS += \
./Inc/DS1307_I2C.d \
./Inc/i2c1.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F746ZGTx -DSTM32F7 -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/DS1307_I2C.cyclo ./Inc/DS1307_I2C.d ./Inc/DS1307_I2C.o ./Inc/DS1307_I2C.su ./Inc/i2c1.cyclo ./Inc/i2c1.d ./Inc/i2c1.o ./Inc/i2c1.su

.PHONY: clean-Inc

