//
// Author: Ice.Marek
// 2023 IceNET Technology
//
#pragma once

#include "Core.h"

class Device : public Core
{
	private:

		int m_x;
		int m_y;

	public:

		Device();
		~Device();

		int openDEV() override;
		int dataRX() override;
		int dataTX() override;
		int closeDEV() override;
};

