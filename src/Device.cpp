//
// Author: Ice.Marek
// 2023 IceNET Technology
//
#include "Device.h"
#include <iostream>

Device::Device()
{
	std::cout << "[ICE] Initialise Device" << std::endl;
}

Device::~Device()
{
	std::cout << "[ICE] Destroy Device" << std::endl;
}

int Device::openDEV()
{
	std::cout << "[ICE] Open Device" << std::endl;

	return 0;
}

int Device::dataRX()
{
	std::cout << "[ICE] Device data [RX]" << std::endl;

	return 0;
}

int Device::dataTX()
{
	std::cout << "[ICE] Device data [TX]" << std::endl;

	return 0;
}

int Device::closeDEV()
{
	std::cout << "[ICE] Close Device" << std::endl;

	return 0;
}
