//
// Author: Ice.Marek
// 2023 IceNET Technology
//
#include <iostream>
#include <string>

#include "parent.h"
#include "child.h"

void Log(const char* message)
{
    std::cout << message << std::endl;
}

int main(int argc, char* argv[]) 
{
    //
    //
    //
    std::cout << "Program name: " << argv[0] << std::endl;
    for (int i = 1; i < argc; i++) 
    {
        std::cout << "Argument[" << i << "]: " << argv[i] << std::endl;
    }
    std::cout << std::endl;

    //
    //
    //
    Log("Parent Class:");
    parent dad(2,3,1);
    dad.print();

    Log("Child Class:");
    child baby(1,1,1);
    baby.print();


    return 0;
}
