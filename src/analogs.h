#pragma once

#include <Joystick.h>

#define analog_check_interval 5 // Analog read interval to prevent USB saturation.

extern unsigned long analog_last_read;

extern Joystick_ Joystick;


void updateAnalogs();