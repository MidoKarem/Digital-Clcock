################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
DigitalClock.lss \

FLASH_IMAGE += \
DigitalClock.hex \

EEPROM_IMAGE += \
DigitalClock.eep \


# All Target
all: DigitalClock.elf secondary-outputs

# Tool invocations
DigitalClock.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DigitalClock.map -mmcu=atmega32 -o "DigitalClock.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DigitalClock.lss: DigitalClock.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DigitalClock.elf  >"DigitalClock.lss"
	@echo 'Finished building: $@'
	@echo ' '

DigitalClock.hex: DigitalClock.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DigitalClock.elf  "DigitalClock.hex"
	@echo 'Finished building: $@'
	@echo ' '

DigitalClock.eep: DigitalClock.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex DigitalClock.elf  "DigitalClock.eep"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DigitalClock.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
