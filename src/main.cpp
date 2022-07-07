#include <iostream>     // system
#include "hack.h"
#include "test.h"

using namespace std;

extern MemAssembly STACK;

int main(int argc, char* argv[]) 
{
    system("clear");

    cout << "SECTIONS" << endl;
    cout << "{" << endl;
    cout << "  . = 0x2000000;" << endl;
    cout << "  .text : { *(.text) }" << endl;
    cout << "  . = 0x4000000;" << endl;
    cout << "  .data : { *(.data) }" << endl;
    cout << "  . = 0x6000000;" << endl;
    cout << "  .bss : { *(.bss) }" << endl;
    cout << "  . = 0x8000000;" << endl;
    cout << "  .iceNET : { *(.iceNET)}" << endl;
    cout << "  . = 0xA000000;" << endl;
    cout << "  .MemAssembly : { *(.MemAssembly)}" << endl;
    cout << "}" << endl << endl;

    static const int AA = 1;
    static const int BB = 2;
    static int CC = 3;          // Initialised DATA
    static int DD = 4;          // Initialised DATA
    static int EE;              // Uninitialised BSS
    static int FF;              // Uninitialised BSS

    const int * pAA =  &AA;
    const int * pBB =  &BB;
    int * pCC =  &CC;
    int * pDD =  &DD;
    int * pEE = &EE;
    int * pFF = &FF;

    cout << "pAA ---> " << pAA << " ????" << endl;
    cout << "pBB ---> " << pBB << " ????" << endl;
    cout << "pCC ---> " << pCC << endl;
    cout << "pDD ---> " << pDD << endl;
    cout << "pEE ---> " << pEE << endl;
    cout << "pFF ---> " << pFF << endl << endl;

    cout << ".text @ 0x2000000\n" << endl;

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
    cout << ".data @ 0x4000000" << endl;
    cout << ".bss  @ 0x6000000\n" << endl;

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

    MemAssembly * pStack = &STACK;

    uintptr_t base = (uintptr_t)&DataStruct.A;

    pStack->MemRead(base + 0x0);
    pStack->MemRead(base + 0x4);
    pStack->MemRead(base + 0x8);
    pStack->MemRead(base + 0xC);

    cout << endl;
    cout << ".iceNET @ 0x8000000\n" << endl;

    unsigned int * pE = &E;
    unsigned int * pF = &F;

    printf("pE ---> %p\n",pE);
    printf("pF ---> %p\n\n",pF);

    cout << ".MemAssembly @ 0xA000000" << endl;

    pStack->MemDump();

    return 0;
}
