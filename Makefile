TARGET 		= asmlink
CC  		= g++
ASM 		= nasm 
AFLAGS 		= -f elf64
CFLAGS 		= -m64
ASM_OBJECTS	= src/link.o

SRCS=\
    src/main.cpp \

SRCS_ASM=\
	src/link.asm \

INCLUDES=\
    -Iinclude

all: link main

main:
	$(CC) $(SRCS) $(CFLAGS) $(INCLUDES) $(ASM_OBJECTS) -o $(TARGET)

link:
	$(ASM) $(AFLAGS) $(SRCS_ASM)

clean:
	rm $(TARGET) $(ASM_OBJECTS)
