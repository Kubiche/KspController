#pragma once

#include <Joystick.h>
#include <MCP23X17.h>

#define analog_check_interval 5 // Analog read interval to prevent USB saturation.

#define io1_int_pin 5

extern unsigned long analog_last_read;

extern Joystick_ Joystick;

extern MCP23017 io1;




void updateAnalogs();

void updateDigitals();

