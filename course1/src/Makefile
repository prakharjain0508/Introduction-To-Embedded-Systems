#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
# Author: Prakhar Jain
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple Makefile that supports the host environment and the target embedded system MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      <FILE>.i - Builds <File>.i preprocessed file
#      <FILE>.d - Builds <File>.d dependency files
#      <FILE>.asm - Builds <File>.asm assembly output of c-program
#      build - Builds and links all source files
#      compile-all - Compile all object files, but DO NOT link
#      clean - removes all generated files
#
# Platform Overrides:
#      HOST - Default Platform
#      MSP432 - Target cross-compiled Embedded System Platform
#------------------------------------------------------------------------------

include sources.mk

# Platform Overrides
PLATFORM = HOST
#VERBOSE := $(VERBOSE)
#COURSE1 := $(COURSE1)
flag = 0

GENERAL_FLAGS = -Wall \
		-Werror \
		-g \
		-O0 \
		-std=c99

ifeq ($(PLATFORM),MSP432)
	
	#Sources files for MSP432
	SRCS = main.c \
       	       memory.c \
	       data.c \
	       stats.c \
	       course1.c \
	       startup_msp432p401r_gcc.c \
       	       system_msp432p401r.c \
       	       interrupts_msp432p401r_gcc.c

	#Include Paths for MSP432
	INCLUDES = -I ../include/common \
	   	   -I ../include/CMSIS \
		   -I ../include/msp432

	# Architectures Specific Flags
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	FPU = fpv4-sp-d16
	FP_ABI = hard


	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	TARGET = c1m4
	LDFLAGS = -Wl,-Map=$(TARGET).map -L ../ -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfpu=$(FPU) -mfloat-abi=$(FP_ABI) --specs=$(SPECS) $(GENERAL_FLAGS)
	CPPFLAGS = -DMSP432 $(INCLUDES) 

else

	# Compiler Flags and Defines
	CC = gcc
	SIZE = size
	TARGET = c1m4
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = $(GENERAL_FLAGS)
	ifeq ($(VERBOSE)$(COURSE1),11)      #Using String Concatination technique as there is not logical AND, OR operations supported in MAKE
		CPPFLAGS = -DVERBOSE -DCOURSE1 -DHOST $(INCLUDES)
		flag=1
	else
		CPPFLAGS = -DHOST $(INCLUDES)
	endif

	ifeq ($(VERBOSE)$(flag),10)
		CPPFLAGS = -DVERBOSE -DHOST $(INCLUDES)
	endif
	ifeq ($(COURSE1)$(flag),10)
		CPPFLAGS = -DCOURSE1 -DHOST $(INCLUDES)
	endif

endif

PREP = $(SRCS:.c=.i)
ASSM = $(SRCS:.c=.asm)
OBJS = $(SRCS:.c=.o)
DEPN = $(SRCS:.c=.d)

%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.d : %.c
	$(CC) -M $< $(CPPLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out:$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(PREP) $(ASSM) $(OBJS) $(DEPN) $(TARGET).out $(TARGET).map 

