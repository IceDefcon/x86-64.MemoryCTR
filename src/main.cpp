



#include <iostream>     // system
#include "dump.h"


int a = 0xFFFFABCD;
int b = 0x0000ABCD;

int main(int argc, char* argv[]) 
{
    system("clear");

    RegDump();

    return 0;
}
