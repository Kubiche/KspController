#include <Arduino.h>
#include <KerbalSimpit.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MCP3008.h>
#include <Joystick.h>

extern KerbalSimpit mySimpit;
extern Joystick_ Joystick;
extern Adafruit_MCP23X17 io;
extern Adafruit_MCP3008 adc;


bool last_button_state[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

//storage array to keep the last value read from the adc
int last_axis_val[8] = {0, 0, 0, 0, 0, 0, 0, 0}; 


void axis_input(int axis) {
    int value = map(adc.readADC(axis),0,1023,0,255);
    if (value != last_axis_val[axis]) {
        last_axis_val[axis] = value;
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
}

void  button_check(int button) {
    int index = button - 1;
    bool state = io.digitalRead(index);
    if (state != last_button_state[index]) {
        last_button_state[index] = state;
        Joystick.setButton(index, (!state));   
    }
}
