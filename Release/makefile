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
Weed_detection.lss \

FLASH_IMAGE += \
Weed_detection.hex \

EEPROM_IMAGE += \
Weed_detection.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Weed_detection.elf secondary-outputs

# Tool invocations
Weed_detection.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Weed_detection.map -mmcu=atmega16 -o "Weed_detection.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Weed_detection.lss: Weed_detection.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Weed_detection.elf  >"Weed_detection.lss"
	@echo 'Finished building: $@'
	@echo ' '

Weed_detection.hex: Weed_detection.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Weed_detection.elf  "Weed_detection.hex"
	@echo 'Finished building: $@'
	@echo ' '

Weed_detection.eep: Weed_detection.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Weed_detection.elf  "Weed_detection.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Weed_detection.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Weed_detection.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Weed_detection.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
