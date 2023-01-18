//
// Author: Ice.Marek
// 2022 IceNET Technology
//
#include <iostream>
#include "hack.h"
#include "func.h"

using namespace std;

int main(int argc, char* argv[]) 
{
    system("clear");

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

    uintptr_t base = (uintptr_t)&DataStruct.A;

    // cout << "   Read Data from 0x" << hex << base + 0xC << " ---> " << MEMORY_READ(base + 0x0) << endl;
    // cout << "   Read Data from 0x" << hex << base + 0xC << " ---> " << MEMORY_READ(base + 0x4) << endl;
    // cout << "   Read Data from 0x" << hex << base + 0xC << " ---> " << MEMORY_READ(base + 0x8) << endl;
    // cout << "   Read Data from 0x" << hex << base + 0xC << " ---> " << MEMORY_READ(base + 0xC) << endl;
    cout << endl;

    cout << "---==[ .MemClass ---> 0x8000000 ]==---" << endl;

    STACK.MemDump();
    cout << endl;

    cout << "---==[ .iceNET ---> 0xA000000 ]==---\n" << endl;

    unsigned int * pX = &X;

    cout << "   pX     ---> "   << pX  << endl;
    cout << "  *pX + 0 ---> 0x" << hex << *(pX + 0) << endl;
    cout << "  *pX + 2 ---> 0x" << hex << *(pX + 2) << endl;
    cout << "  *pX + 4 ---> 0x" << hex << *(pX + 4) << endl;
    cout << endl;

    cout << "---==[ Final Test ]==---" << endl;
    //
    // BEGIN
    //
    cout << endl;
    static MemAssembly * pMemAssembly = new MemAssembly;
    cout << "   pMemAssembly is " << pMemAssembly << endl;
    pMemAssembly->MemDump();
    delete pMemAssembly;

    int   var1 = 20;     /* actual variable declaration */
    int   var2;          /* not initialised variable    */
    int * ip1 = &var1;   /* store address of var in pointer variable*/
    int * ip2 = &var2;   /* store address of var in pointer variable*/

    cout << "   Address of var variable: " << &var1 << endl;
    cout << "   Address of var variable: " << &var2 << endl;
    cout << "   Address stored in ip1 variable: " << hex << ip1 << endl;
    cout << "   Address stored in ip2 variable: " << hex << ip2 << endl;
    cout << "   Access the value using the *ip1 pointer: " << *ip1 << endl;
    cout << "   Access the value using the *ip2 pointer: " << *ip2 << endl;
    //
    // END
    //
    cout << "   Calling using pointer definition---> " << (int*)pFunction_D << endl;
    CALL_PROCEDURE((int*)pFunction_D);

    return 0;
}
