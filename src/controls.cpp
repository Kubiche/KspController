#include "controls.h"

extern KerbalSimpit mySimpit;
extern Joystick_ Joystick;
extern Adafruit_MCP23X17 io;

bool button_check(uint8_t button) {
    uint8_t _button = button - 1;
    bool _value = io.digitalRead(_button);
    return _value;    
    }
