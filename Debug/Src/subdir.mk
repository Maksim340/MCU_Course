################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/rcc.c \
../Src/system_stm32f7xx.c 

OBJS += \
./Src/main.o \
./Src/rcc.o \
./Src/system_stm32f7xx.o 

C_DEPS += \
./Src/main.d \
./Src/rcc.d \
./Src/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32F745xx -DSTM32 -DSTM32F745ZGTx -DSTM32F7 -c -I../Inc -I"C:/Users/Maxim/STM32CubeIDE/workspace_1.9.0/MCU_Course/Drivers/CMSIS/Include" -I"C:/Users/Maxim/STM32CubeIDE/workspace_1.9.0/MCU_Course/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.d ./Src/main.o ./Src/main.su ./Src/rcc.d ./Src/rcc.o ./Src/rcc.su ./Src/system_stm32f7xx.d ./Src/system_stm32f7xx.o ./Src/system_stm32f7xx.su

.PHONY: clean-Src
