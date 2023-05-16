#
# Author: Ice.Marek
# 2023 IceNET Technology
#
AUTO 		= app
MANUAL 		= app.linked
GCC  		= g++ 
CFLAGS 		= -Wall -Wextra -std=c++11 -O2 -g
LDSCRIPT    := linker/linker.ld

CPP_SOURCES = $(shell find . -name "*.cpp")
CPP_OBJECTS = $(CPP_SOURCES:.cpp=.o)

INCLUDES=\
	include \

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
	rm -f $(AUTO) $(MANUAL) $(CPP_OBJECTS)

.PHONY: all clean
