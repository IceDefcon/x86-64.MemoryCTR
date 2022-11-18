//
// Author: Ice.Marek
// 2022 IceNET Technology
//
#ifndef HACK_H
#define HACK_H

#include <inttypes.h>

using namespace std;

extern "C" unsigned long MEMORY_READ(unsigned int offset);

class MemAssembly{

    public:
        MemAssembly();
        ~MemAssembly();
        
        int x,y,z,t;
        long a,b,c,d;
        long long dx,dy,dz,dt;

        void MemRead(int offset);

        void MemDump(void);
};


#endif /* HACK_H */