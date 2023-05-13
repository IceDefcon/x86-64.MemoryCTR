#
# Author: Ice.Marek
# 2023 IceNET Technology
#
AUTO 		= app
MANUAL 		= app.linked
GCC  		= g++ 
CFLAGS 		= -Wall -Wextra -std=c++11 -O2 -g
LDSCRIPT    := linker/linker.ld

ASM_SOURCES = $(shell find . -name "*.asm")
CPP_SOURCES = $(shell find . -name "*.cpp")

INCLUDES=\
	include \

CPP_OBJECTS = $(CPP_SOURCES:.cpp=.o)
ASM_OBJECTS = $(ASM_SOURCES:.asm=.o)

all: $(AUTO) $(MANUAL)

$(AUTO): $(CPP_OBJECTS)
	$(GCC) $(CFLAGS) $^ -o $@ 
	size $(AUTO)

$(MANUAL): $(CPP_OBJECTS)
	$(GCC) $(CFLAGS) -T $(LDSCRIPT) $^ -o $@ 
	size $(MANUAL)

%.o: %.cpp
	$(GCC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(AUTO) $(MANUAL) $(CPP_OBJECTS) $(ASM_OBJECTS)

.PHONY: all clean
