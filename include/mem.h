#ifndef MEM_H
#define MEM_H

#include <inttypes.h>

extern "C" unsigned long _MEMORY_READ_A(void);
extern "C" unsigned long _MEMORY_READ_B(void);

int * MemDump(void)
{ 
    printf("RAX_Accumulator ---> Read A : %#018" PRIx64 " \n",_MEMORY_READ_A());
    printf("RAX_Accumulator ---> Read B : %#018" PRIx64 " \n",_MEMORY_READ_B());

    return 0;
}

#endif /* MEM_H */