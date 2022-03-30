################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include app/subdir.mk
-include MCAL/WatchDog/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO_driver/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD_driver/subdir.mk
-include HAL/Keypad_driver/subdir.mk
-include HAL/EXT_EEPROM/subdir.mk
-include FREE_RTOS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ATMEGA_32_Drivers.lss \

FLASH_IMAGE += \
ATMEGA_32_Drivers.hex \

EEPROM_IMAGE += \
ATMEGA_32_Drivers.eep \


# All Target
all: ATMEGA_32_Drivers.elf secondary-outputs

# Tool invocations
ATMEGA_32_Drivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATMEGA_32_Drivers.map -mmcu=atmega32 -o "ATMEGA_32_Drivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATMEGA_32_Drivers.lss: ATMEGA_32_Drivers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATMEGA_32_Drivers.elf  >"ATMEGA_32_Drivers.lss"
	@echo 'Finished building: $@'
	@echo ' '

ATMEGA_32_Drivers.hex: ATMEGA_32_Drivers.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ATMEGA_32_Drivers.elf  "ATMEGA_32_Drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

ATMEGA_32_Drivers.eep: ATMEGA_32_Drivers.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ATMEGA_32_Drivers.elf  "ATMEGA_32_Drivers.eep"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ATMEGA_32_Drivers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
