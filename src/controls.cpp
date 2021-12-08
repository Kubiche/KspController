#include <Arduino.h>
#include <KerbalSimpit.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MCP3008.h>
#include <Joystick.h>

extern KerbalSimpit mySimpit;
extern Joystick_ Joystick;
extern Adafruit_MCP23X17 io;
extern Adafruit_MCP3008 adc; 


void axis_input(uint8_t axis) {
    int value = adc.readADC(axis);
    switch (axis) {
        case 0:
        //RX Axis
        Joystick.setRxAxis(value);
        break;
        case 1:
        //RY Axis
        Joystick.setRyAxis(value);
        break;
        case 2:
        //Rz Axis
        Joystick.setRzAxis(value);
        break;
        case 7:
        //Throttle Axis
        Joystick.setThrottle(value);
        break;        
    }
    
}

uint8_t button_check(uint8_t button) {
    uint8_t _button = button - 1;
    uint8_t _value = io.digitalRead(_button);
    return _value;    
    }
