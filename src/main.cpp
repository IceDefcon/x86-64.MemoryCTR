#include <iostream>     // system
#include "hack.h"

using namespace std;

extern MemAssembly STACK;
extern MemAssembly HEAP;

int main(int argc, char* argv[]) 
{
    system("clear");

    unsigned int * pA = &A;
    unsigned int * pB = &B;

    printf("Original Data A ---> 0x%08x\n",A);
    printf("Original Data B ---> 0x%08x\n",B);
    printf("Pointer to A variable ---> %p\n",pA);
    printf("Pointer to B variable ---> %p\n\n",pB);

    unsigned int * pC = &C;
    unsigned int * pD = &D;

    printf("Data from  C variable ---> %x\n",C);
    printf("Data from  D variable ---> %x\n",D);
    printf("Pointer to C variable ---> %p\n",pC);
    printf("Pointer to D variable ---> %p\n\n",pD);

    void (*pFunction_A)(void) = &Function_A;
    void (*pFunction_B)(int)  = &Function_B;

    // Testing function pointers
    pFunction_A();
    pFunction_B(100);

    printf("Pointer to Function_A ---> %p\n",pFunction_A);
    printf("Pointer to Function_B ---> %p\n\n",pFunction_B);

    MemAssembly * pMemAssembly[4];
    printf("Dynamic Pointer to [0] MemAssembly Class ---> %p\n",pMemAssembly[0]);
    printf("Dynamic Pointer to [1] MemAssembly Class ---> %p\n",pMemAssembly[1]);
    printf("Dynamic Pointer to [2] MemAssembly Class ---> %p\n",pMemAssembly[2]);
    printf("Dynamic Pointer to [3] MemAssembly Class ---> %p\n",pMemAssembly[3]);

    pMemAssembly[0] = &STACK;
    pMemAssembly[1] = &HEAP;
    printf("Linked  Pointer to [0] MemAssembly Class ---> %p\n",pMemAssembly[0]);
    printf("Linked  Pointer to [1] MemAssembly Class ---> %p\n",pMemAssembly[1]);

    printf("Or just Pointer to STACK                 ---> %p\n",&STACK);
    printf("Or just Pointer to HEAP                  ---> %p\n\n",&HEAP);

    MemAssembly MemAssemblyInstance;
    MemAssemblyInstance.MemDump();
    pMemAssembly[0]->MemDump();

    //
    // Need implemntation of how to addess the
    // memory regions of funcitons inside class
    //

    return 0;
}
