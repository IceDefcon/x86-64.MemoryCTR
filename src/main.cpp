#include <iostream>     // system
#include "mem.h"

unsigned int a = 0xFFFF1234;
unsigned int b = 0x00001234;

int main(int argc, char* argv[]) 
{

    system("clear");

    unsigned int * pa = &a;
    unsigned int * pb = &b;

    printf("Original Data a ---> 0x%08x\n",a);
    printf("Original Data b ---> 0x%08x\n\n",b);

    printf("Linker Pointer pa ---> %p\n",pa);
    printf("Linker Pointer pb ---> %p\n\n",pb);

    MemDump();
    
    return 0;
}
