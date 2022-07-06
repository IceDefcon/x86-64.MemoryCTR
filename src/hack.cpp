//
// Author: Ice.Marek
// 2022 IceNET Te
//
#include <iostream>     // system
#include "hack.h"

using namespace std;

MemAssembly::MemAssembly()
{
    cout << "!!! CONSTRUCTOR CALLED !!! ---> Creating Instance of MemAssembly" << endl << endl;
}

MemAssembly::~MemAssembly()
{
    cout << "!!! DESTRUCTOR CALLED !!! ---> Deleting Instance of MemAssembly" << endl;
}

void MemAssembly::MemRead(int offset)
{
    printf("Read from 0x%x ---> %lx\n",offset,MEMORY_READ(offset));
}

void MemAssembly::MemDump(void)
{
    cout << endl;
    printf("x  ---> %p y  ---> %p z  ---> %p t  ---> %p\n", &x, &y, &z, &t);
    printf("a  ---> %p b  ---> %p c  ---> %p d  ---> %p\n", &a, &b, &c, &d);
    printf("dx ---> %p dy ---> %p dz ---> %p dt ---> %p\n", &dx, &dy, &dz, &dt);
}

