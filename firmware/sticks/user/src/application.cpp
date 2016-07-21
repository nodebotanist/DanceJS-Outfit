
#include "application.h"
#include "flash_mal.h"

SYSTEM_MODE(SEMI_AUTOMATIC)

bool FLASH_WriteProtectMemory(flash_device_t flashDeviceID, uint32_t startAddress, uint32_t length, bool protect);

void setup()
{
    WiFi.connect();
}
