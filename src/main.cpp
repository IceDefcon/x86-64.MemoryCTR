#include <iostream>     // system
#include "hack.h"
#include "test.h"

using namespace std;

extern MemAssembly STACK;
extern MemAssembly HEAP;

int main(int argc, char* argv[]) 
{
    system("clear");

    cout << ".text @ 0x1000000\n" << endl;

    void (*pFunction_A)(void)     = &Function_A;
    void (*pFunction_B)(int)      = &Function_B;
    void (*pFunction_C)(int,int)  = &Function_C;
    void (*pFunction_D)(void)     = &Function_D;

    // Testing function pointers
    pFunction_A();
    pFunction_B(100);
    pFunction_C(100,200);
    pFunction_D();

    printf("pFunction_A ---> %p\n",pFunction_A);
    printf("pFunction_B ---> %p\n",pFunction_B);
    printf("pFunction_C ---> %p\n",pFunction_C);
    printf("pFunction_D ---> %p\n",pFunction_D);

    cout << endl;
    cout << ".data + .bss @ 0x8000000\n" << endl;

    DataStruct.A = 1;
    DataStruct.B = 2;
    DataStruct.C = 3;
    DataStruct.D = 4;

    unsigned int * pA = &DataStruct.A;
    unsigned int * pB = &DataStruct.B;
    unsigned int * pC = &DataStruct.C;
    unsigned int * pD = &DataStruct.D;

    printf("pA ---> %p\n",&DataStruct.A);
    printf("pB ---> %p\n",&DataStruct.B);
    printf("pC ---> %p\n",&DataStruct.C);
    printf("pD ---> %p\n",&DataStruct.D);

    cout << endl;
    cout << ".iceNET @ 0xA000000\n" << endl;

    unsigned int * pE = &E;
    unsigned int * pF = &F;

    printf("pE ---> %p\n",pE);
    printf("pF ---> %p\n\n",pF);

    cout << ".MemAssembly @ 0xB000000\n" << endl;

    MemAssembly * pStack = &STACK;
    MemAssembly * pHeap  = &HEAP;

    uintptr_t base = (uintptr_t)&DataStruct.A;

    pStack->MemRead(base + 0x0);
    pStack->MemRead(base + 0x4);
    pStack->MemRead(base + 0x8);
    pStack->MemRead(base + 0xC);
    pStack->MemDump();

    return 0;
}
