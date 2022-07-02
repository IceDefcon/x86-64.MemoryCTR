#ifndef MEM_H
#define MEM_H

#include <inttypes.h>

using namespace std;

extern "C" unsigned long MEMORY_READ_A(void);
extern "C" unsigned long MEMORY_READ_B(void);

extern unsigned int C;
extern unsigned int D;

class MemAssembly{

    public:
        MemAssembly();
        ~MemAssembly();
        
        int x,y,z,t;
        long a,b,c,d;
        long long dx,dy,dz,dt;

        void MemDump(void)
        { 
            printf("RAX_Accumulator ---> Read A : %#018" PRIx64 " \n",MEMORY_READ_A());
            printf("RAX_Accumulator ---> Read B : %#018" PRIx64 " \n",MEMORY_READ_B());
            printf("Address for integer x  ---> %p y  ---> %p z  ---> %p t  ---> %p\n", &x, &y, &z, &t);
            printf("Address for integer a  ---> %p b  ---> %p c  ---> %p d  ---> %p\n", &a, &b, &c, &d);
            printf("Address for integer dx ---> %p dy ---> %p dz ---> %p dt ---> %p\n\n", &dx, &dy, &dz, &dt);
        }
};

MemAssembly::MemAssembly()
{
    cout << "!!! CONSTRUCTOR CALLED !!! ---> Creating Instance of MemAssembly" << endl << endl;
}

MemAssembly::~MemAssembly()
{
    cout << "!!! DESTRUCTOR CALLED !!! ---> Deleting Instance of MemAssembly" << endl;
}

unsigned int A = 0xFFFF1234;
unsigned int B = 0x00001234;

void Function_A(void);
void Function_B(int x);

#endif /* MEM_H */