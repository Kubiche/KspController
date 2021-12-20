#pragma once

#include <Arduino.h>
#include <KerbalSimpit.h>
#include "leds.h"


void messageHandler(byte messageType, byte msg[], byte msgSize); // Message handler required by simpit