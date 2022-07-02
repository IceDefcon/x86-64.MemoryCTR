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

void Function_A(void)
{
    cout << "This is execution of the void Function A" << endl;
}

void Function_B(int x)
{
    x = x + 1;
    cout << "This is execution of the void Function B with variable x = x + 1 ---> " << x << endl;
}