//
// Author: Ice.Marek
// 2023 IceNET Technology
//
#include "child.h"
#include <iostream>

child::child() // default
: 
dx(0), 
dy(0), 
dt(0) 
{}

child::child(int _dx, int _dy, int _dt) // custom
: 
dx(_dx), 
dy(_dy), 
dt(_dt) 
{}

void
child::print()
{
	std::cout << dx << std::endl;
	std::cout << dy << std::endl;
	std::cout << dt << std::endl;
}