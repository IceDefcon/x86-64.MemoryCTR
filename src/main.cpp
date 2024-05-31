//
// Author: Ice.Marek
// 2024 IceNET Technology
//
#include <iostream>
#include <string>

#include "Device.h"

int main()
{
    Core* pCore = nullptr; /* Stack Allocation */
    Device* pDevice = new Device(); /* Heap Allocation */

    pCore = pDevice;
    pCore->openDEV();
    pCore->dataRX();
    pCore->dataTX();
    pCore->closeDEV();

    delete pCore;

    return 0;
}
