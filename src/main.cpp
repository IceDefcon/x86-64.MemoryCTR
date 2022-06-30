#include <iostream>     // system
#include "test.h"


int a = 0xFFFF1234;
int b = 0x00001234;

extern "C" unsigned long _RAX(void);
extern "C" unsigned long _RBX(void);
extern "C" unsigned long _RCX(void);
extern "C" unsigned long _RDX(void);
extern "C" unsigned long _RSP(void);
extern "C" unsigned long _RBP(void);
extern "C" unsigned long _RSI(void);
extern "C" unsigned long _RDI(void);

extern "C" int _RSS(void);
extern "C" int _RCS(void);
extern "C" int _RDS(void);
extern "C" int _RES(void);
extern "C" int _RFS(void);
extern "C" int _RGS(void);

extern "C" int _EFLAGS(void);

extern "C" unsigned long _CPU_RAX(void);
extern "C" unsigned long _CPU_RBX(void);
extern "C" unsigned long _CPU_RCX(void);
extern "C" unsigned long _CPU_RDX(void);


int main(int argc, char* argv[]) 
{

    system("clear");

    int * pa = &a;
    int * pb = &b;

    printf("pointer a ---> %x\n",pa);
    printf("pointer b ---> %x\n",pb);

    // Now Create Assembly function which will read
    // Data from addresses 0x8000004 and 0x8000008
    // Hopefully it will be 0xFFFF1234 and 0x00001234
    return 0;
}

