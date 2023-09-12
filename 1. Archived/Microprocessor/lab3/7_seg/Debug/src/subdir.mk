################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/7seg.c \
../src/helper_functions.c \
../src/led_button.c \
../src/main.c 

OBJS += \
./src/7seg.o \
./src/helper_functions.o \
./src/led_button.o \
./src/main.o 

C_DEPS += \
./src/7seg.d \
./src/helper_functions.d \
./src/led_button.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DNUCLEO_L476RG -DDEBUG -c -I"/home/littled3092/Documents/My-Vault/Microprocessor/lab3/7_seg/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/7seg.d ./src/7seg.o ./src/7seg.su ./src/helper_functions.d ./src/helper_functions.o ./src/helper_functions.su ./src/led_button.d ./src/led_button.o ./src/led_button.su ./src/main.d ./src/main.o ./src/main.su

.PHONY: clean-src

