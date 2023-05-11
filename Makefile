#
# Author: Ice.Marek
# 2023 IceNET Technology
#
AUTO 		= auto
MANUAL 		= manual
GCC  		= g++
NASM 		= nasm 

AFLAGS 		= -f elf64
CFLAGS 		= -m64

LDSCRIPT    := linker/linker.ld

ASM_SOURCES = $(shell find . -name "*.asm")
CPP_SOURCES = $(shell find . -name "*.cpp")

INCLUDES=\
	include \

CPP_OBJECTS = $(CPP_SOURCES:.cpp=.o)
ASM_OBJECTS = $(ASM_SOURCES:.asm=.o)

all: $(AUTO) $(MANUAL)

$(AUTO): $(CPP_OBJECTS) $(ASM_OBJECTS)
	$(GCC) $(CFLAGS) -no-pie $^ -o $@ 
	size $(AUTO)

$(MANUAL): $(CPP_OBJECTS) $(ASM_OBJECTS)
	$(GCC) $(CFLAGS) -T $(LDSCRIPT) $^ -o $@ 
	size $(MANUAL)

%.o: %.cpp
	$(GCC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<

%.o: %.asm
	$(NASM) $(AFLAGS) $(ASM_SOURCES) -o $@

clean:
	rm -f $(AUTO) $(MANUAL) $(CPP_OBJECTS) $(ASM_OBJECTS)

.PHONY: all clean
