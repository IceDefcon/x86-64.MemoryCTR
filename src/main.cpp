//
// Author: Ice.Marek
// 2022 IceNET Technology
//
#include <iostream>
#include "hack.h"
#include "func.h"

using namespace std;

extern MemAssembly STACK;

extern "C" unsigned long CALL_POINTER(int* offset);

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

    cout << "---==[ .text ---> 0x2000000 ]==---\n" << endl;

    void (*pFunction_A)(void)     = &Function_A;
    void (*pFunction_B)(int)      = &Function_B;
    void (*pFunction_C)(int,int)  = &Function_C;
    void (*pFunction_D)(void)     = &Function_D;

    // Testing function pointers
    pFunction_A();
    pFunction_B(100);
    pFunction_C(100,200);
    pFunction_D();

    cout << "   pFunction_A ---> " << (int*)pFunction_A << endl;
    cout << "   pFunction_B ---> " << (int*)pFunction_B << endl;
    cout << "   pFunction_C ---> " << (long*)pFunction_C << endl;
    cout << "   pFunction_D ---> " << (int*)pFunction_D << endl;
    cout << endl;

    cout << "---==[ .data ---> 0x4000000 ]==---\n" << endl;

    // Initialised variables with specific data ---> .data
    static int Variable_A = 0xABC;
    static int Variable_B = 0x123;

    int * pVariable_A = &Variable_A;
    int * pVariable_B = &Variable_B;

    cout << "   pVariable_A ---> " << pVariable_A << endl;
    cout << "   pVariable_B ---> " << pVariable_B << endl;
    cout << endl;

    cout << "---==[ .bss ---> 0x6000000 ]==---\n" << endl;

    // Un-initialised variables ---> .bss
    static int Variable_C;
    static int Variable_D;

    int * pVariable_C = &Variable_C;
    int * pVariable_D = &Variable_D;

    cout << "   pVariable_C ---> " << pVariable_C << endl;
    cout << "   pVariable_D ---> " << pVariable_D << endl << endl;

    DataStruct.A = 1;
    DataStruct.B = 2;
    DataStruct.C = 3;
    DataStruct.D = 4;

    unsigned int * pA = &DataStruct.A;
    unsigned int * pB = &DataStruct.B;
    unsigned int * pC = &DataStruct.C;
    unsigned int * pD = &DataStruct.D;

    cout << "   pA ---> " << &DataStruct.A << endl;
    cout << "   pB ---> " << &DataStruct.B << endl;
    cout << "   pC ---> " << &DataStruct.C << endl;
    cout << "   pD ---> " << &DataStruct.D << endl;

    MemAssembly * pStack = &STACK;

    uintptr_t base = (uintptr_t)&DataStruct.A;

    pStack->MemRead(base + 0x0);
    pStack->MemRead(base + 0x4);
    pStack->MemRead(base + 0x8);
    pStack->MemRead(base + 0xC);
    cout << endl;

    cout << "---==[ .iceNET ---> 0x8000000 ]==---\n" << endl;

    unsigned int * pE = &E;
    unsigned int * pF = &F;

    cout << "   pE ---> " << pE << endl;
    cout << "   pF ---> " << pF << endl;
    cout << endl;

    cout << "---==[ .MemAssembly ---> 0xA000000 ]==---" << endl;

    pStack->MemDump();

    cout << endl;
    cout << "---==[ Final Test ]==---" << endl;

    cout << endl;
    cout << "   Calling from >> (int*)pFunction_D ---> " << (int*)pFunction_D << endl;
    CALL_POINTER((int*)pFunction_D);
    cout << "   Calling from >> 0x20001a0 ---> " << (int*)pFunction_D << endl;
    CALL_POINTER((int*)0x20001a0);

    return 0;
}
