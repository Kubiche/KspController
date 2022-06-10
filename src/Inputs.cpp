#include "Inputs.h"

MCP23017 io1;

unsigned long analog_last_read = 0; // variable to store the time of the last analog value read.

// Create the Joystick
Joystick_ Joystick(0x05,0x04,
  16, 0,                    //  Button Count, Hat Switch Count
  true, true, true,     //  X and Y and Z Axis
  true, true, true,        //  Rx, Ry, or Rz
  false, true,            //  rudder or throttle
  false, false, false);    //  accelerator, brake, or steering



void updateAnalogs()   //read analog values and update accordingly.
{  
  if ((millis() - analog_last_read) > analog_check_interval)
  {  
  Joystick.setRxAxis(analogRead(A0));  
  Joystick.setRyAxis(analogRead(A1));
  Joystick.setRzAxis(analogRead(A2));
  //Joystick.setXAxis(analogRead(A8));
  //Joystick.setYAxis(analogRead(A9));
  //Joystick.setZAxis(analogRead(A10));
  //Joystick.setThrottle(analogRead(A6));
  analog_last_read = millis();
  Joystick.sendState(); //Send joystick updated states to the PC
  }    
}

void updateDigitals()
{
  if (digitalRead(io1_int_pin)) //check for interrupt pin from io expander chip to see if any changes in states.
  {
    io1.readGPIOs(); 
    for (uint8_t i = 0; i < 2; i++)
    {      
      for (uint8_t j = 0; j < 8; j++)
      {        
        Joystick.setButton( (j + (i * 8)), (io1.gpio[i] & (1 << j))); // This applies an offset to the button number, assigning to it the state fo the result of the gpio byte and corresponding mask.  
      }
    }
  }
}