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

GENERAL_FLAGS = -Wall \
		-Werror \
		-g \
		-O0 \
		-std=c99

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
#Compiler Flags and Defines
#CC = arm-none-eabi-gcc
CC= gcc
#LD = arm-none-eabi-ld
#SIZE = arm-none-eabi-size
SIZE = size
TARGET = c1m2
#LDFLAGS = -Wl,-Map=$(TARGET).map -L ../ -T $(LINKER_FILE)
LDFLAGS = -Wl,-Map=$(TARGET).map
#CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) --specs=$(SPECS) $(GENERAL_FLAGS)
CFLAGS = $(GENERAL_FLAGS)

ASSM = $(SRCS:.c=.asm)
OBJS = $(SRCS:.c=.o)

%.asm : %.c
	$(CC) -S $< $(CFLAGS) -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: build
build: $(TARGET).out

$(TARGET).out:$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(ASSM) $(OBJS) $(TARGET).out $(TARGET).map 

