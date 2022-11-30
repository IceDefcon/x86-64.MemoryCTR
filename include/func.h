//
// Author: Ice.Marek
// 2022 IceNET Technology
//
#ifndef TEST_H
#define TEST_H

struct 
{
    unsigned int A;
    unsigned int B;
    unsigned int C;
    unsigned int D;
} DataStruct;

extern unsigned int X;
extern MemAssembly STACK;
extern "C" unsigned long CALL_PROCEDURE(int* offset);
extern "C" unsigned long MEMORY_READ(unsigned int offset);

void Function_A(void);
void Function_B(int x);
void Function_C(int x,int y);
void Function_D(void);

#endif /* TEST_H */