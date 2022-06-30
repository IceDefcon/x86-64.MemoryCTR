#include <iostream>     // system
#include "hack.h"


using namespace std;

extern MemAssembly HACK;

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

    printf("Defined Pointer to HACK              ---> %p\n",&HACK);
    MemAssembly * pMemAssembly;
    printf("Dynamic Pointer to MemAssembly Class ---> %p\n",pMemAssembly);
    pMemAssembly = &HACK;
    printf("Hacked Pointer to MemAssembly  Class ---> %p\n",pMemAssembly);

    MemAssembly MemAssemblyInstance;
    MemAssemblyInstance.MemDump();
    pMemAssembly->MemDump();

    //
    // Need inmplemntation of addee
    // To memory regions of the funcitons
    // Inside the clas + variables !!!!
    //

    return 0;
}
