//
// Author: Ice.Marek
// 2022 IceNET Technology
//
#include <iostream>     // system

void Function_A(void)
{
    printf("This is execution of the void Function A \n");
}

void Function_B(int x)
{
    x = x + 1;
    printf("This is execution of the void Function B with variable x:%d \n",x);
}