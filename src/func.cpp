//
// Author: Ice.Marek
// 2022 IceNET Technology
//
#include <iostream>

using namespace std;

void Function_A(void)
{
    cout << "   Calling Function_A" << endl;
}

void Function_B(int x)
{
    cout << "   Calling Function_B" << endl;
    x = x + 1;
}

void Function_C(int x,int y)
{
    cout << "   Calling Function_C" << endl;
}

void Function_D(void)
{
    Function_C(500,800);
}