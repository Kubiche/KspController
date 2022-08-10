#pragma once

#include <KerbalSimpit.h>
#include "MAX72XX.h"

extern LED led;
#define Bar_Device 0

void messageHandler(uint8_t messageType, uint8_t msg[], uint8_t msgSize); // Message handler required by simpit