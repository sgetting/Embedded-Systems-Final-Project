################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../fft


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../avr.c \
../AVRGCC4.c \
../keypad.c \
../Lab4.c \
../lcd.c


PREPROCESSING_SRCS +=  \
../fft/ffft.S \
../fft/suart.S


ASM_SRCS += 


OBJS +=  \
avr.o \
AVRGCC4.o \
fft/ffft.o \
fft/suart.o \
keypad.o \
Lab4.o \
lcd.o


OBJS_AS_ARGS +=  \
avr.o \
AVRGCC4.o \
fft/ffft.o \
fft/suart.o \
keypad.o \
Lab4.o \
lcd.o


C_DEPS +=  \
avr.d \
AVRGCC4.d \
keypad.d \
Lab4.d \
lcd.d


C_DEPS_AS_ARGS +=  \
avr.d \
AVRGCC4.d \
keypad.d \
Lab4.d \
lcd.d


OUTPUT_FILE_PATH +=AVRGCC4.elf

OUTPUT_FILE_PATH_AS_ARGS +=AVRGCC4.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

# AVR32/GNU C Compiler











./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler
	$(QUOTE)C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-gcc.exe$(QUOTE)  -funsigned-char -funsigned-bitfields -O1 -fpack-struct -fshort-enums -g2 -Wall -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -mmcu=atmega32  -o"$@" "$<" 
	@echo Finished building: $<



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler
fft/ffft.o: ../fft/ffft.s
	@echo Building file: $<
	@echo Invoking: AVR32/GNU C Assembler
	$(QUOTE)C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -Wa,-gdwarf2 -x assembler-with-cpp -c  -mmcu=atmega32   -o"$@" "$<"
	@echo Finished building: $<

fft/suart.o: ../fft/suart.s
	@echo Building file: $<
	@echo Invoking: AVR32/GNU C Assembler
	$(QUOTE)C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -Wa,-gdwarf2 -x assembler-with-cpp -c  -mmcu=atmega32   -o"$@" "$<"
	@echo Finished building: $<


fft/%.o: ../fft/%.s
	@echo Building file: $<
	@echo Invoking: AVR32/GNU C Assembler
	$(QUOTE)C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -Wa,-gdwarf2 -x assembler-with-cpp -c  -mmcu=atmega32   -o"$@" "$<"
	@echo Finished building: $<




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU C Linker
	$(QUOTE)C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="AVRGCC4.map" -Wl,-lm  -Wl,-u,vfprintf -lprintf_flt  -mmcu=atmega32  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "AVRGCC4.elf" "AVRGCC4.hex"
	"C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "AVRGCC4.elf" "AVRGCC4.eep" || exit 0
	"C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-objdump.exe" -h -S "AVRGCC4.elf" > "AVRGCC4.lss"
	"C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-size.exe" -C --mcu=atmega32  "AVRGCC4.elf"
	




# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "AVRGCC4.hex" "AVRGCC4.lss" "AVRGCC4.eep" "AVRGCC4.map"
	