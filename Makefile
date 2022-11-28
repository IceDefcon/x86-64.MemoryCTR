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
OBJ 		:= src
CPP_INCLUDE	:= include
CPP_SOURCES := $(wildcard $(SRC)/*.cpp)
CPP_OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(CPP_SOURCES))
DBG_OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.dbg, $(CPP_SOURCES))

SRC_ASM 	:= src_asm
OBJ_ASM 	:= src_asm
ASM_SOURCES := $(wildcard src_asm/*.asm)
ASM_OBJECTS := $(patsubst $(SRC_ASM)/%.asm, $(OBJ_ASM)/%.o, $(ASM_SOURCES))

all: main debug

main: $(CPP_OBJECTS) $(ASM_OBJECTS)
	$(GCC) -T $(LDSCRIPT) $^ -o $(TARGET)
	objdump -d -M intel $^ > $(TARGET).dbg

dynamic: $(CPP_OBJECTS) $(ASM_OBJECTS)
	$(GCC) $^ -o $(TARGET)
	objdump -d -M intel $^ > $(TARGET).dbg
	
$(OBJ)/%.o: $(SRC)/%.cpp
	$(GCC) $(CFLAGS) -I $(CPP_INCLUDE) -c $< -o $@

$(OBJ_ASM)/%.o:$(SRC_ASM)/%.asm
	$(NASM) $(AFLAGS) $(ASM_SOURCES) -o $@

debug: $(DBG_OBJECTS)

$(OBJ)/%.dbg: $(SRC)/%.o
	objdump -d -M intel $< > $@

clean:
	rm $(TARGET) $(ASM_OBJECTS) $(CPP_OBJECTS) $(TARGET).dbg $(DBG_OBJECTS)
