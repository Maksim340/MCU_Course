################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f745zgtx.s 

OBJS += \
./Startup/startup_stm32f745zgtx.o 

S_DEPS += \
./Startup/startup_stm32f745zgtx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"C:/Users/Maxim/STM32CubeIDE/workspace_1.9.0/MCU_Course/Drivers/CMSIS/Include" -I"C:/Users/Maxim/STM32CubeIDE/workspace_1.9.0/MCU_Course/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f745zgtx.d ./Startup/startup_stm32f745zgtx.o

.PHONY: clean-Startup
