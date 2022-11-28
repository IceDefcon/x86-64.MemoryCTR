//
// Author: Ice.Marek
// 2022 IceNET Technology
//
#include <iostream>     // system
#include "hack.h"

using namespace std;

MemAssembly::MemAssembly()
{
    cout << "   !!! CONSTRUCTOR CALLED !!! ---> Creating Instance of MemAssembly" << endl;
}

MemAssembly::~MemAssembly()
{
    cout << "   !!! DESTRUCTOR CALLED !!!  ---> Deleting Instance of MemAssembly" << endl;
}

void MemAssembly::MemRead(int offset)
{
    cout << "   Read Data from 0x" << hex << offset << " ---> " << MEMORY_READ(offset) << endl;
}

void MemAssembly::MemDump(void)
{
    cout << endl;
    cout << "   x  ---> " << &x  << " y  ---> " << &y  << " z  ---> " << &z  << " t  ---> " << &t  << endl;
    cout << "   a  ---> " << &a  << " b  ---> " << &b  << " c  ---> " << &c  << " d  ---> " << &d  << endl;
    cout << "   dx ---> " << &dx << " dy ---> " << &dy << " dz ---> " << &dz << " dt ---> " << &dt << endl;
}