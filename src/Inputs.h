#pragma once

#include <Joystick.h>

#define analog_check_interval 5 // Analog read interval to prevent USB saturation.

#define io_int_pin 5

extern unsigned long analog_last_read;

extern Joystick_ Joystick;




void updateAnalogs();

void updateDigitals();

