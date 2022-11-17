TARGET 		= asmlink
CC  		= g++
ASM 		= nasm 
AFLAGS 		= -f elf64
CFLAGS 		= -m64 
ASM_OBJECTS	= src_asm/link.o
LDSCRIPT    = linker/linker.ld

SRC=\
    src/main.cpp \
    src/hack.cpp \
    src/test.cpp \

SRC_ASM=\
	src_asm/link.asm \

INCLUDES=\
    -Iinclude

all: link main

main:
	$(CC) $(SRC) $(CFLAGS) $(INCLUDES) $(ASM_OBJECTS) -T $(LDSCRIPT) -o $(TARGET)

link:
	$(ASM) $(AFLAGS) $(SRC_ASM)

clean:
	rm $(TARGET) $(ASM_OBJECTS)
