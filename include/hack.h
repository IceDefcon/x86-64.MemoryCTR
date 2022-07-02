#ifndef MEM_H
#define MEM_H

#include <inttypes.h>

struct
{
    unsigned int A;
    unsigned int B;
    unsigned int C;
    unsigned int D;
} DataStruct;

using namespace std;

extern "C" unsigned long MEMORY_READ(unsigned int offset);

extern unsigned int E;
extern unsigned int F;

class MemAssembly{

    public:
        MemAssembly();
        ~MemAssembly();
        
        int x,y,z,t;
        long a,b,c,d;
        long long dx,dy,dz,dt;

        void MemRead(int offset)
        {
            printf("Read Specific Memory ---> %lx\n",MEMORY_READ(offset));
        }

        void MemDump(void)
        {
            printf("\nx  ---> %p y  ---> %p z  ---> %p t  ---> %p\n", &x, &y, &z, &t);
            printf("a  ---> %p b  ---> %p c  ---> %p d  ---> %p\n", &a, &b, &c, &d);
            printf("dx ---> %p dy ---> %p dz ---> %p dt ---> %p\n", &dx, &dy, &dz, &dt);
        }
};






void Function_A(void);
void Function_B(int x);

#endif /* MEM_H */