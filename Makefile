#
# Author: Ice.Marek
# 2022 IceNET Technology
#
TARGET 		= asmlink
GCC  		= g++
NASM 		= nasm 

AFLAGS 		= -f elf64
CFLAGS 		= -m64

LDSCRIPT    := linker/linker.ld

SRC 		:= src
OBJ 		:= $(SRC)/obj
CPP_INCLUDE	:= include
CPP_SOURCES := $(wildcard $(SRC)/*.cpp)
CPP_OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(CPP_SOURCES))

SRC_ASM 	:= src_asm
OBJ_ASM 	:= $(SRC_ASM)/obj_asm
ASM_SOURCES := $(wildcard src_asm/*.asm)
ASM_OBJECTS := $(patsubst $(SRC_ASM)/%.asm, $(OBJ_ASM)/%.o, $(ASM_SOURCES))

all: $(CPP_OBJECTS) $(ASM_OBJECTS)
	$(GCC) -T $(LDSCRIPT) $^ -o $(TARGET)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(GCC) $(CFLAGS) -I $(CPP_INCLUDE) -c $< -o $@

$(ASM_OBJECTS):$(ASM_SOURCES)
	$(NASM) $(AFLAGS) $(ASM_SOURCES) -o $@

clean:
	rm $(TARGET) $(ASM_OBJECTS) $(CPP_OBJECTS)
