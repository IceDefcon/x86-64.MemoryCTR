//
// Author: Ice.Marek
// 2023 IceNET Technology
//
#pragma once

#include <iostream>

class Core
{
	private:



	public:

		Core()
		{
			std::cout << "[ICE] Initialise the Core" << std::endl;
		}

		virtual ~Core()
		{
			std::cout << "[ICE] Destroy the Core" << std::endl;
		}

		virtual int openDEV() = 0;
		virtual int dataRX() = 0;
		virtual int dataTX() = 0;
		virtual int closeDEV() = 0;
};
