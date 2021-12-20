#include <controls.h>

extern KerbalSimpit mySimpit;
extern Joystick_ Joystick;
extern Adafruit_MCP23X17 io;

uint8_t button_check(uint8_t button) {
    uint8_t _button = button - 1;
    uint8_t _value = io.digitalRead(_button);
    return _value;    
    }
