//
// Author: Ice.Marek
// 2022 IceNET Technology
//
#include <iostream>
#include "hack.h"
#include "func.h"

int main(int argc, char* argv[]) 
{
    system("clear");

    std::cout << "---==[ .text ]==---\n" << endl;

    void (*pFunction_A)(void)     = &Function_A;
    void (*pFunction_B)(int)      = &Function_B;
    void (*pFunction_C)(int,int)  = &Function_C;
    void (*pFunction_D)(void)     = &Function_D;

    std::cout << "pFunction_A ---> " << (int*)pFunction_A  << std::endl;
    std::cout << "pFunction_B ---> " << (int*)pFunction_B  << std::endl;
    std::cout << "pFunction_C ---> " << (long*)pFunction_C << std::endl;
    std::cout << "pFunction_D ---> " << (int*)pFunction_D  << std::endl;
    std::cout << std::endl;

    int A = 5;
    std::cout << "STACK  :: &A   ---> " << &A << std::endl;

    static int B = 5;
    static int C = 10;
    int* pB = &B;
    int* pC = &C;

    std::cout << "STATIC GLOBAL ADDRESS :: pB   ---> " << pB << std::endl;
    std::cout << "STATIC GLOBAL ADDRESS :: pC   ---> " << pC << std::endl;

    #define N 4

    int* ptr0 = (int*)malloc(N*sizeof(int));
    int* ptr1 = (int*)malloc(N*sizeof(int));
    int* ptr2 = (int*)malloc(N*sizeof(int));
    int* ptr3 = (int*)malloc(N*sizeof(int));
    int* ptr4 = (int*)malloc(N*sizeof(int));

    std::cout << "HEAP :: ptr0 ---> " << ptr0 << std::endl;
    std::cout << "HEAP :: ptr1 ---> " << ptr1 << std::endl;
    std::cout << "HEAP :: ptr2 ---> " << ptr2 << std::endl;
    std::cout << "HEAP :: ptr3 ---> " << ptr3 << std::endl;
    std::cout << "HEAP :: ptr4 ---> " << ptr4 << std::endl;

    std:cout << std::endl;

    for (int i = 0; i < N; ++i)
    {
        *(ptr0+i) = 2<<i;
    }
    *ptr1 = 4096;
    *(ptr0+N+0) = 0xCC;
    *(ptr0+N+1) = 0xCC;
    *(ptr0+N+2) = 0xCC;
    *(ptr0+N+3) = 0xCC;

    for (int i = 0; i < N+5; ++i)
    {
        std::cout << "HEAP :: *ptr+" << i << " ---> " << hex << *(ptr0+i) << std::endl;
    }

    // // Initialised variables with specific data ---> .data
    // static int Variable_A = 0xABC;
    // static int Variable_B = 0x123;

    // int * pVariable_A = &Variable_A;
    // int * pVariable_B = &Variable_B;

    // cout << "   pVariable_A ---> " << pVariable_A << endl;
    // cout << "   pVariable_B ---> " << pVariable_B << endl;
    // cout << endl;

    // cout << "---==[ .bss ---> 0x6000000 ]==---\n" << endl;

    // // Un-initialised variables ---> .bss
    // static int Variable_C;
    // static int Variable_D;

    // int * pVariable_C = &Variable_C;
    // int * pVariable_D = &Variable_D;

    // cout << "   pVariable_C ---> " << pVariable_C << endl;
    // cout << "   pVariable_D ---> " << pVariable_D << endl << endl;

    // DataStruct.A = 1;
    // DataStruct.B = 2;
    // DataStruct.C = 3;
    // DataStruct.D = 4;

    // unsigned int * pA = &DataStruct.A;
    // unsigned int * pB = &DataStruct.B;
    // unsigned int * pC = &DataStruct.C;
    // unsigned int * pD = &DataStruct.D;

    // cout << "   pA ---> " << &DataStruct.A << " == " << pA << endl;
    // cout << "   pB ---> " << &DataStruct.B << " == " << pB << endl;
    // cout << "   pC ---> " << &DataStruct.C << " == " << pC << endl;
    // cout << "   pD ---> " << &DataStruct.D << " == " << pD << endl;

    // uintptr_t base = (uintptr_t)&DataStruct.A;

    // cout << "   Read Data from 0x" << hex << base + 0x0 << " ---> " << MEMORY_READ(base + 0x0) << endl;
    // cout << "   Read Data from 0x" << hex << base + 0x4 << " ---> " << MEMORY_READ(base + 0x4) << endl;
    // cout << "   Read Data from 0x" << hex << base + 0x8 << " ---> " << MEMORY_READ(base + 0x8) << endl;
    // cout << "   Read Data from 0x" << hex << base + 0xC << " ---> " << MEMORY_READ(base + 0xC) << endl;
    // cout << endl;

    // cout << "---==[ .MemClass ---> 0x8000000 ]==---" << endl;

    // STACK.MemDump();
    // cout << endl;

    // cout << "---==[ .iceNET ---> 0xA000000 ]==---\n" << endl;

    // unsigned int * pX = &X;

    // cout << "   pX     ---> "   << pX  << endl;
    // cout << "  *pX + 0 ---> 0x" << hex << *(pX + 0) << endl;
    // cout << "  *pX + 2 ---> 0x" << hex << *(pX + 2) << endl;
    // cout << "  *pX + 4 ---> 0x" << hex << *(pX + 4) << endl;
    // cout << "  *pX + 6 ---> 0x" << hex << *(pX + 6) << endl;
    // cout << "  *pX + 7 ---> 0x" << hex << *(pX + 7) << endl;
    // cout << endl;

    // cout << "---==[ Class Test ]==---" << endl;
    // cout << endl;

    // static MemAssembly * pMemAssembly = new MemAssembly;
    // cout << "   pMemAssembly is " << pMemAssembly << endl;

    // pMemAssembly->MemDump();
    // delete pMemAssembly;

    // cout << "   Calling using pointer definition---> " << (int*)pFunction_D << endl;
    // CALL_PROCEDURE((int*)pFunction_D);

    // //
    // // Memory allocation
    // //
    // cout << endl;
    // cout << "---==[ Memory accocations ]==---" << endl;
    // cout << endl;

    // int * p_malloc = (int*)malloc(5*sizeof(int));
    // int * p_calloc = (int*)calloc(5,sizeof(int));

    // cout << "   p_malloc---> 0x" << hex << p_malloc << endl;
    // cout << "   p_calloc---> 0x" << hex << p_calloc << endl;

    // cout << endl;

    // *(p_malloc+2) = 0xC0DECA11;
    // *(p_calloc+4) = 0xDEADCA11;

    // for (int i = 0; i < 5; ++i)
    // {
    //     cout << "   p_malloc---> 0x" << hex << *p_malloc << endl;
    //     p_malloc++;
    // }

    // cout << endl;

    // for (int i = 0; i < 5; ++i)
    // {
    //     cout << "   p_calloc---> 0x" << hex << *p_calloc << endl;
    //     p_calloc++;
    // }

    return 0;
}
