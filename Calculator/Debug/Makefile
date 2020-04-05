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
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../croutine.c \
../DIO_Prog.c \
../heap_1.c \
../KeyPad_prog.c \
../lcd_4bit.c \
../list.c \
../port.c \
../queue.c \
../RTOS_LAB1_ATMEGA32.c \
../tasks.c \
../timers.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
croutine.o \
DIO_Prog.o \
heap_1.o \
KeyPad_prog.o \
lcd_4bit.o \
list.o \
port.o \
queue.o \
RTOS_LAB1_ATMEGA32.o \
tasks.o \
timers.o


OBJS_AS_ARGS +=  \
croutine.o \
DIO_Prog.o \
heap_1.o \
KeyPad_prog.o \
lcd_4bit.o \
list.o \
port.o \
queue.o \
RTOS_LAB1_ATMEGA32.o \
tasks.o \
timers.o


C_DEPS +=  \
croutine.d \
DIO_Prog.d \
heap_1.d \
KeyPad_prog.d \
lcd_4bit.d \
list.d \
port.d \
queue.d \
RTOS_LAB1_ATMEGA32.d \
tasks.d \
timers.d


C_DEPS_AS_ARGS +=  \
croutine.d \
DIO_Prog.d \
heap_1.d \
KeyPad_prog.d \
lcd_4bit.d \
list.d \
port.d \
queue.d \
RTOS_LAB1_ATMEGA32.d \
tasks.d \
timers.d


OUTPUT_FILE_PATH +=RTOS_LAB1_ATMEGA32.elf

OUTPUT_FILE_PATH_AS_ARGS +=RTOS_LAB1_ATMEGA32.elf

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
	$(QUOTE)C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="RTOS_LAB1_ATMEGA32.map" -Wl,-lm   -mmcu=atmega32  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "RTOS_LAB1_ATMEGA32.elf" "RTOS_LAB1_ATMEGA32.hex"
	"C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "RTOS_LAB1_ATMEGA32.elf" "RTOS_LAB1_ATMEGA32.eep" || exit 0
	"C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-objdump.exe" -h -S "RTOS_LAB1_ATMEGA32.elf" > "RTOS_LAB1_ATMEGA32.lss"
	"C:\Program Files (x86)\Atmel\AVR Studio 5.1\extensions\Atmel\AVRGCC\3.3.1.27\AVRToolchain\bin\avr-size.exe" -C --mcu=atmega32  "RTOS_LAB1_ATMEGA32.elf"
	




# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "RTOS_LAB1_ATMEGA32.hex" "RTOS_LAB1_ATMEGA32.lss" "RTOS_LAB1_ATMEGA32.eep" "RTOS_LAB1_ATMEGA32.map"
	