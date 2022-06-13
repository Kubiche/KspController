#pragma once

#include <Joystick.h>
#include <MCP23X17.h>

#define ANALOG_CHECK_INTERVAL 5 // Analog read interval to prevent USB saturation.

#define IO1_I2C_ADDRESS 0x21
#define IO1_INT_PIN 5


extern unsigned long analog_last_read;

extern Joystick_ Joystick;

extern MCP23017 io1;




void updateAnalogs();

void updateDigitals();

