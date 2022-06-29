#include <iostream>     // system
#include "dump.h"


int a = 0xFFFF1234;
int b = 0x00001234;

int main(int argc, char* argv[]) 
{
    system("clear");

    int * pa = &a;
    int * pb = &b;

    printf("pointer a ---> %x\n",pa);
    printf("pointer b ---> %x\n",pb);

    //RegDump();

    return 0;
}

