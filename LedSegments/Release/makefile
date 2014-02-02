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
LedSegments.lss \

FLASH_IMAGE += \
LedSegments.hex \

EEPROM_IMAGE += \
LedSegments.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LedSegments.elf secondary-outputs

# Tool invocations
LedSegments.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LedSegments.map -mmcu=atmega328p -o "LedSegments.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LedSegments.lss: LedSegments.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LedSegments.elf  >"LedSegments.lss"
	@echo 'Finished building: $@'
	@echo ' '

LedSegments.hex: LedSegments.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LedSegments.elf  "LedSegments.hex"
	@echo 'Finished building: $@'
	@echo ' '

LedSegments.eep: LedSegments.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LedSegments.elf  "LedSegments.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LedSegments.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p LedSegments.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) LedSegments.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
