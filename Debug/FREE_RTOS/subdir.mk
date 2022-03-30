################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FREE_RTOS/croutine.c \
../FREE_RTOS/heap_1.c \
../FREE_RTOS/list.c \
../FREE_RTOS/port.c \
../FREE_RTOS/queue.c \
../FREE_RTOS/tasks.c \
../FREE_RTOS/timers.c 

OBJS += \
./FREE_RTOS/croutine.o \
./FREE_RTOS/heap_1.o \
./FREE_RTOS/list.o \
./FREE_RTOS/port.o \
./FREE_RTOS/queue.o \
./FREE_RTOS/tasks.o \
./FREE_RTOS/timers.o 

C_DEPS += \
./FREE_RTOS/croutine.d \
./FREE_RTOS/heap_1.d \
./FREE_RTOS/list.d \
./FREE_RTOS/port.d \
./FREE_RTOS/queue.d \
./FREE_RTOS/tasks.d \
./FREE_RTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FREE_RTOS/%.o: ../FREE_RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


