#include <iostream>     // system
#include "mem.h"

using namespace std;

#define MemAssemblyLength 8


unsigned int A = 0xFFFF1234;
unsigned int B = 0x00001234;

void Function_A(void)
{
    printf("This is execution of the void Function A \n");
}

void Function_B(int x)
{
    x = x + 1;
    printf("This is execution of the void Function B with variable x:%d \n",x);
}

int main(int argc, char* argv[]) 
{
    system("clear");

    unsigned int * pA = &A;
    unsigned int * pB = &B;

    printf("Original Data A ---> 0x%08x\n",A);
    printf("Original Data B ---> 0x%08x\n\n",B);

    printf("Pointer to A variable ---> %p\n",pA);
    printf("Pointer to B variable ---> %p\n\n",pB);

    void (*pFunction_A)(void) = &Function_A;
    void (*pFunction_B)(int)  = &Function_B;

    MemAssembly * pMemAssembly;
    pMemAssembly->MemDump();

    //
    // Testing function pointers
    //
    pFunction_A();
    pFunction_B(100);
    (*pFunction_B)(200);

    printf("Pointer to Function_A ---> %p\n",pFunction_A);
    printf("Pointer to Function_B ---> %p\n\n",pFunction_B);
    
    //
    // Not Fixed Yet ---> Address is not linked
    //
    printf("Pointer to MemAssembly Class ---> %p\n\n",pMemAssembly);

    //void (*pTest)(void) = &pMemAssembly->MemDump();

    return 0;
}
