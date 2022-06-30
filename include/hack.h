#ifndef MEM_H
#define MEM_H

#include <inttypes.h>

extern "C" unsigned long _MEMORY_READ_A(void);
extern "C" unsigned long _MEMORY_READ_B(void);

extern unsigned int C;
extern unsigned int D;

class MemAssembly{

    public:
        MemAssembly();
        ~MemAssembly();
        
        void MemDump(void)
        { 
            printf("RAX_Accumulator ---> Read A : %#018" PRIx64 " \n",_MEMORY_READ_A());
            printf("RAX_Accumulator ---> Read B : %#018" PRIx64 " \n\n",_MEMORY_READ_B());
        }
};

MemAssembly::MemAssembly()
{
    //cout << "IceNET ---> MemAssembly Constructor Called" << endl;
}

MemAssembly::~MemAssembly()
{
    //cout << "IceNET ---> MemAssembly Destructor Called" << endl;
}

unsigned int A = 0xFFFF1234;
unsigned int B = 0x00001234;

void Function_A(void);
void Function_B(int x);

#endif /* MEM_H */