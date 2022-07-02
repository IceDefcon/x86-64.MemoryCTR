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

extern "C" unsigned long Return_4x_16bit_arguments(int arg_1, int arg_2, int arg_3, int arg_4);
extern "C" unsigned long MEMORY_READ(int offset);
extern "C" unsigned long MEMORY_READ_A(void);
extern "C" unsigned long MEMORY_READ_B(void);
extern "C" unsigned long MEMORY_READ_C(void);
extern "C" unsigned long MEMORY_READ_D(void);

extern unsigned int E;
extern unsigned int F;

class MemAssembly{

    public:
        MemAssembly();
        ~MemAssembly();
        
        int x,y,z,t;
        long a,b,c,d;
        long long dx,dy,dz,dt;

        void MemDump(void)
        {
            Return_4x_16bit_arguments(2,4,6,8);
            long long Argumetns = Return_4x_16bit_arguments(2,4,6,8);
            printf("Return Argumetns = %llx \n",Argumetns);

            int Argumetn_4 = (0xffff000000000000 & Argumetns) >> 0x30;
            int Argumetn_3 = (0x0000ffff00000000 & Argumetns) >> 0x20;
            int Argumetn_2 = (0x00000000ffff0000 & Argumetns) >> 0x10;
            int Argumetn_1 = (0x000000000000ffff & Argumetns) >> 0x00;

            printf("Argumetn_1 = %x \n",Argumetn_1);
            printf("Argumetn_2 = %x \n",Argumetn_2);
            printf("Argumetn_3 = %x \n",Argumetn_3);
            printf("Argumetn_4 = %x \n",Argumetn_4);

            printf("Read Specific Memory ---> %#018" PRIx64 " \n",MEMORY_READ(0x8000300+0x8));
            printf("Read 0x8000300       ---> %#018" PRIx64 " \n",MEMORY_READ_A());
            printf("Read 0x8000300 + 0x4 ---> %#018" PRIx64 " \n",MEMORY_READ_B());
            printf("Read 0x8000300 + 0x8 ---> %#018" PRIx64 " \n",MEMORY_READ_C());
            printf("Read 0x8000300 + 0xC ---> %#018" PRIx64 " \n",MEMORY_READ_D());
            printf("x  ---> %p y  ---> %p z  ---> %p t  ---> %p\n", &x, &y, &z, &t);
            printf("a  ---> %p b  ---> %p c  ---> %p d  ---> %p\n", &a, &b, &c, &d);
            printf("dx ---> %p dy ---> %p dz ---> %p dt ---> %p\n\n", &dx, &dy, &dz, &dt);        }
};

MemAssembly::MemAssembly()
{
    cout << "!!! CONSTRUCTOR CALLED !!! ---> Creating Instance of MemAssembly" << endl << endl;
}

MemAssembly::~MemAssembly()
{
    cout << "!!! DESTRUCTOR CALLED !!! ---> Deleting Instance of MemAssembly" << endl;
}




void Function_A(void);
void Function_B(int x);

#endif /* MEM_H */