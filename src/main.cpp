#include <iostream>     // system
#include "hack.h"

using namespace std;

extern MemAssembly STACK;
extern MemAssembly HEAP;

int main(int argc, char* argv[]) 
{
    system("clear");

    cout << ".text is defined @ 0x1000000\n" << endl;

    void (*pFunction_A)(void) = &Function_A;
    void (*pFunction_B)(int)  = &Function_B;

    // Testing function pointers
    pFunction_A();
    pFunction_B(100);

    printf("Pointer to Function_A ---> %p\n",pFunction_A);
    printf("Pointer to Function_B ---> %p\n\n",pFunction_B);

    cout << ".data + .bss are defined @ 0x8000000 ---> And so the unsigned variables\n" << endl;

    DataStruct.A = 1;
    DataStruct.B = 2;
    DataStruct.C = 3;
    DataStruct.D = 4;

    unsigned int * pA = &DataStruct.A;
    unsigned int * pB = &DataStruct.B;
    unsigned int * pC = &DataStruct.C;
    unsigned int * pD = &DataStruct.D;

    cout << "DataStruct.A = " << DataStruct.A << endl;
    cout << "DataStruct.B = " << DataStruct.B << endl;
    cout << "DataStruct.C = " << DataStruct.C << endl;
    cout << "DataStruct.D = " << DataStruct.D << endl;

    printf("pA ---> %p\n",&DataStruct.A);
    printf("pB ---> %p\n",&DataStruct.B);
    printf("pC ---> %p\n",&DataStruct.C);
    printf("pD ---> %p\n\n",&DataStruct.D);

    cout << ".iceNET is defined @ 0xA000000\n" << endl;

    unsigned int * pE = &E;
    unsigned int * pF = &F;

    printf("pE ---> %p\n",pE);
    printf("pF ---> %p\n\n",pF);

    cout << ".MemAssembly is defined @ 0xB000000\n" << endl;

    MemAssembly * pStack = &STACK;
    MemAssembly * pHeap  = &HEAP;

    printf("STACK is linked to ---> %p\n\n",pStack);

    uintptr_t base = (uintptr_t)&DataStruct.A;

    pStack->MemRead(base + 0x0);
    pStack->MemRead(base + 0x4);
    pStack->MemRead(base + 0x8);
    pStack->MemRead(base + 0xC);
    pStack->MemDump();

    return 0;
}
