################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/FreeRtos_2TasksHasLCDSource.c \
../app/FreeRtos_2TasksHasLCDSource_Semahore.c \
../app/FreeRtos_Blinking2Leds.c \
../app/FreeRtos_Queue.c \
../app/FreeRtos_SynchSemaphore_Task_INT.c \
../app/ICU_Using_Timer.c \
../app/Test_ADC.c \
../app/Test_EXTI.c \
../app/Test_I2c_Ext_EEPROM.c \
../app/Test_LCD_Keypad.c \
../app/Test_OverFlow_Timer.c \
../app/Test_SPI.c \
../app/Test_UART.c \
../app/Test_WD.c \
../app/anims.c \
../app/blinkled.c \
../app/lcd.c \
../app/testDIO.c 

OBJS += \
./app/FreeRtos_2TasksHasLCDSource.o \
./app/FreeRtos_2TasksHasLCDSource_Semahore.o \
./app/FreeRtos_Blinking2Leds.o \
./app/FreeRtos_Queue.o \
./app/FreeRtos_SynchSemaphore_Task_INT.o \
./app/ICU_Using_Timer.o \
./app/Test_ADC.o \
./app/Test_EXTI.o \
./app/Test_I2c_Ext_EEPROM.o \
./app/Test_LCD_Keypad.o \
./app/Test_OverFlow_Timer.o \
./app/Test_SPI.o \
./app/Test_UART.o \
./app/Test_WD.o \
./app/anims.o \
./app/blinkled.o \
./app/lcd.o \
./app/testDIO.o 

C_DEPS += \
./app/FreeRtos_2TasksHasLCDSource.d \
./app/FreeRtos_2TasksHasLCDSource_Semahore.d \
./app/FreeRtos_Blinking2Leds.d \
./app/FreeRtos_Queue.d \
./app/FreeRtos_SynchSemaphore_Task_INT.d \
./app/ICU_Using_Timer.d \
./app/Test_ADC.d \
./app/Test_EXTI.d \
./app/Test_I2c_Ext_EEPROM.d \
./app/Test_LCD_Keypad.d \
./app/Test_OverFlow_Timer.d \
./app/Test_SPI.d \
./app/Test_UART.d \
./app/Test_WD.d \
./app/anims.d \
./app/blinkled.d \
./app/lcd.d \
./app/testDIO.d 


# Each subdirectory must supply rules for building sources it contributes
app/%.o: ../app/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


