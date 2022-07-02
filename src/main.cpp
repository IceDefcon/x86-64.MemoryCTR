#include <iostream>     // system
#include "hack.h"

using namespace std;

extern MemAssembly STACK;
extern MemAssembly HEAP;

int main(int argc, char* argv[]) 
{
    system("clear");

    cout << ".data + .bss are defined @ 0x8000000 ---> And so the unsigned variables\n" << endl;

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
    printf("pD ---> %p\n\n",&DataStruct.D);

    cout << ".iceNET is defined @ 0xA000000\n" << endl;

    unsigned int * pE = &E;
    unsigned int * pF = &F;

    printf("pE ---> %p\n",pE);
    printf("pF ---> %p\n\n",pF);

    cout << ".text is defined @ 0x1000000\n" << endl;

    void (*pFunction_A)(void) = &Function_A;
    void (*pFunction_B)(int)  = &Function_B;

    // Testing function pointers
    pFunction_A();
    pFunction_B(100);

    printf("Pointer to Function_A ---> %p\n",pFunction_A);
    printf("Pointer to Function_B ---> %p\n\n",pFunction_B);

    //
    // This section is still not working !!!
    //
    cout << "THIS SECTION IS STILL NOT FIGURED OUT !!!!!!!!!!!!" << endl;
    cout << "THIS SECTION IS STILL NOT FIGURED OUT !!!!!!!!!!!!" << endl;
    cout << "THIS SECTION IS STILL NOT FIGURED OUT !!!!!!!!!!!!\n" << endl;

    cout << ".MemAssembly is defined @ 0xB000000\n" << endl;

    MemAssembly * pMemAssembly[8];
    printf("Dynamic Pointer to [0] MemAssembly Class ---> %p\n",pMemAssembly[0]);
    printf("Dynamic Pointer to [1] MemAssembly Class ---> %p\n",pMemAssembly[1]);
    printf("Dynamic Pointer to [2] MemAssembly Class ---> %p\n",pMemAssembly[2]);
    printf("Dynamic Pointer to [3] MemAssembly Class ---> %p\n",pMemAssembly[3]);
    printf("Dynamic Pointer to [4] MemAssembly Class ---> %p\n",pMemAssembly[4]);
    printf("Dynamic Pointer to [5] MemAssembly Class ---> %p\n",pMemAssembly[5]);
    printf("Dynamic Pointer to [6] MemAssembly Class ---> %p\n",pMemAssembly[6]);
    printf("Dynamic Pointer to [7] MemAssembly Class ---> %p\n",pMemAssembly[7]);

    pMemAssembly[0] = &STACK;
    pMemAssembly[1] = &HEAP;
    printf("Linked  Pointer to [0] MemAssembly Class ---> %p\n",pMemAssembly[0]);
    printf("Linked  Pointer to [1] MemAssembly Class ---> %p\n",pMemAssembly[1]);

    printf("Or just Pointer to STACK                 ---> %p\n",&STACK);
    printf("Or just Pointer to HEAP                  ---> %p\n\n",&HEAP);

    MemAssembly MemAssemblyInstance;
    MemAssemblyInstance.MemDump();
    pMemAssembly[0]->MemDump();

    return 0;
}
