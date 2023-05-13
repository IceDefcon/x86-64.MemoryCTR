//
// Author: Ice.Marek
// 2023 IceNET Technology
//
#pragma once
#include "parent.h"

class child : public parent
{
public:
	child();
	child(int _dx, int _dy, int _dt);

	void print();

private:

	int dx;
	int dy;
	int dt;
};
