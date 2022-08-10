#pragma once

#include <KerbalSimpit.h>
#include "MAX72XX.h"
#include "Defines.h"

extern MAX72XX led;


void messageHandler(uint8_t messageType, uint8_t msg[], uint8_t msgSize); // Message handler required by simpit