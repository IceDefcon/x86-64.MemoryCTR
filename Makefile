#
# Author: Ice.Marek
# 2023 IceNET Technology
#
DYNAMIC 	= dynamic
STATIC 		= static
GCC  		= g++ -no-pie
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

all: $(DYNAMIC)

$(DYNAMIC): $(CPP_OBJECTS) $(ASM_OBJECTS)
	$(GCC) $(CFLAGS) $^ -o $@ 

static: $(STATIC)

$(STATIC): $(CPP_OBJECTS) $(ASM_OBJECTS)
	$(GCC) $(CFLAGS) -T $(LDSCRIPT) $^ -o $@ 

%.o: %.cpp
	$(GCC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<

%.o: %.asm
	$(NASM) $(AFLAGS) $(ASM_SOURCES) -o $@

clean:
	rm -f $(DYNAMIC) $(CPP_OBJECTS) $(ASM_OBJECTS)

.PHONY: all static clean
