################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripherals/Src/adc.c \
../Peripherals/Src/exti.c \
../Peripherals/Src/gpio.c \
../Peripherals/Src/i2c.c \
../Peripherals/Src/opamp.c \
../Peripherals/Src/rcc.c \
../Peripherals/Src/spi.c \
../Peripherals/Src/tim.c \
../Peripherals/Src/uart.c 

OBJS += \
./Peripherals/Src/adc.o \
./Peripherals/Src/exti.o \
./Peripherals/Src/gpio.o \
./Peripherals/Src/i2c.o \
./Peripherals/Src/opamp.o \
./Peripherals/Src/rcc.o \
./Peripherals/Src/spi.o \
./Peripherals/Src/tim.o \
./Peripherals/Src/uart.o 

C_DEPS += \
./Peripherals/Src/adc.d \
./Peripherals/Src/exti.d \
./Peripherals/Src/gpio.d \
./Peripherals/Src/i2c.d \
./Peripherals/Src/opamp.d \
./Peripherals/Src/rcc.d \
./Peripherals/Src/spi.d \
./Peripherals/Src/tim.d \
./Peripherals/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Peripherals/Src/%.o Peripherals/Src/%.su Peripherals/Src/%.cyclo: ../Peripherals/Src/%.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L432xx -DUSE_HAL_DRIVER -c -I"C:/Users/DANNY/STM32CubeIDE/workspace_1.12.0/AVANCE_Tesis040425/Peripherals/Inc" -I"C:/Users/DANNY/STM32CubeIDE/workspace_1.12.0/AVANCE_Tesis040425/Core/Inc" -I"C:/Users/DANNY/STM32CubeIDE/workspace_1.12.0/AVANCE_Tesis040425/Applications/SD" -I"C:/Users/DANNY/STM32CubeIDE/workspace_1.12.0/AVANCE_Tesis040425/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/DANNY/STM32CubeIDE/workspace_1.12.0/AVANCE_Tesis040425/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/DANNY/STM32CubeIDE/workspace_1.12.0/AVANCE_Tesis040425/Drivers/CMSIS/Include" -I"C:/Users/DANNY/STM32CubeIDE/workspace_1.12.0/AVANCE_Tesis040425/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Peripherals-2f-Src

clean-Peripherals-2f-Src:
	-$(RM) ./Peripherals/Src/adc.cyclo ./Peripherals/Src/adc.d ./Peripherals/Src/adc.o ./Peripherals/Src/adc.su ./Peripherals/Src/exti.cyclo ./Peripherals/Src/exti.d ./Peripherals/Src/exti.o ./Peripherals/Src/exti.su ./Peripherals/Src/gpio.cyclo ./Peripherals/Src/gpio.d ./Peripherals/Src/gpio.o ./Peripherals/Src/gpio.su ./Peripherals/Src/i2c.cyclo ./Peripherals/Src/i2c.d ./Peripherals/Src/i2c.o ./Peripherals/Src/i2c.su ./Peripherals/Src/opamp.cyclo ./Peripherals/Src/opamp.d ./Peripherals/Src/opamp.o ./Peripherals/Src/opamp.su ./Peripherals/Src/rcc.cyclo ./Peripherals/Src/rcc.d ./Peripherals/Src/rcc.o ./Peripherals/Src/rcc.su ./Peripherals/Src/spi.cyclo ./Peripherals/Src/spi.d ./Peripherals/Src/spi.o ./Peripherals/Src/spi.su ./Peripherals/Src/tim.cyclo ./Peripherals/Src/tim.d ./Peripherals/Src/tim.o ./Peripherals/Src/tim.su ./Peripherals/Src/uart.cyclo ./Peripherals/Src/uart.d ./Peripherals/Src/uart.o ./Peripherals/Src/uart.su

.PHONY: clean-Peripherals-2f-Src

