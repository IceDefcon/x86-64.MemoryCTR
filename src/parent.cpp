//
// Author: Ice.Marek
// 2023 IceNET Technology
//
#include "parent.h"
#include <iostream>

parent::parent() // default
: 
x(0), 
y(0), 
t(0) 
{}

parent::parent(int _x, int _y, int _t) // custom
: 
x(_x), 
y(_y), 
t(_t) 
{}

void
parent::print()
{
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << t << std::endl;
}