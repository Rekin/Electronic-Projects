################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ButtonCounter.lss \

FLASH_IMAGE += \
ButtonCounter.hex \

EEPROM_IMAGE += \
ButtonCounter.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ButtonCounter.elf secondary-outputs

# Tool invocations
ButtonCounter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ButtonCounter.map -mmcu=atmega328p -o "ButtonCounter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ButtonCounter.lss: ButtonCounter.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ButtonCounter.elf  >"ButtonCounter.lss"
	@echo 'Finished building: $@'
	@echo ' '

ButtonCounter.hex: ButtonCounter.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ButtonCounter.elf  "ButtonCounter.hex"
	@echo 'Finished building: $@'
	@echo ' '

ButtonCounter.eep: ButtonCounter.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ButtonCounter.elf  "ButtonCounter.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ButtonCounter.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p ButtonCounter.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) ButtonCounter.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
