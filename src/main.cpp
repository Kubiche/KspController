#include <Arduino.h>
#include <KerbalSimpit.h>
#include <Joystick.h>
#include <HID.h>
#include <Wire.h>
#include "inboundMessages.h"
#include "leds.h"
#include "MCP23017.h"

#define DEBUG 0

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

#define analog_check_interval 5 // Analog read interval to prevent USB saturation.

// FUNCTION DECLARATIONS
void readAnalogs(); //function to read the analog inputs for the controller

unsigned long analog_last_read = 0; // variable to store the time of the last analog value read.

MCP23017 io1;

KerbalSimpit mySimpit(Serial);



// Create the Joystick
Joystick_ Joystick(0x05,0x04,
  1, 0,                    //  Button Count, Hat Switch Count
  true, true, true,     //  X and Y and Z Axis
  true, true, true,        //  Rx, Ry, or Rz
  false, true,            //  rudder or throttle
  false, false, false);    //  accelerator, brake, or steering


void setup() 
{
  
  Wire.begin(); // set up I2c bus
  SPI.begin(); // set up SPI bus

  // Initialize Joystick Library
	Joystick.begin(false);
  
  
  //Led driver MAX7219  
  pinMode(LED_CS, OUTPUT); // Set the CS pin as output
  digitalWrite(LED_CS, HIGH); // Set CS pin to High
  setLedReg(OP_SHUTDOWN, 1); // Turn LED controller on
  setLedReg(OP_SCANLIMIT, 7); // set to scan all digits
  setLedReg(OP_INTENSITY, 2); // Set intensity to 2 of 16
  
  //clear the display
  for (int i=8; i>0; i--)
  {
    setLedReg(i, 255);
  }   

  // MCP23017 IO expanders
  io1.init(0x21);
  



  //------------------------------------------------------Write any test code above here since the while below will halt code---------------------------------------------------------------------------------------------
  
  
  Serial.begin(115200); // Initialize Serial connection to mod
  while (!mySimpit.init()) 
  {
    delay(100);
  }
  

  mySimpit.inboundHandler(messageHandler); // callback function
  
  // Register to desired messages from simpit
  mySimpit.registerChannel(SF_STAGE_MESSAGE);
  mySimpit.registerChannel(LF_STAGE_MESSAGE);
  mySimpit.registerChannel(MONO_MESSAGE);
  mySimpit.registerChannel(ELECTRIC_MESSAGE);
  mySimpit.registerChannel(ACTIONSTATUS_MESSAGE);

  
}

void loop() 
{  
  
  mySimpit.update(); // Update messages from simpit, as part of it the function messageHandler gets called to process the mod's output in our code (see inboundMessages.h)
  
  if ((millis() - analog_last_read) > analog_check_interval)
  {
    readAnalogs();
    analog_last_read = millis();
    Joystick.sendState(); //Send joystick updated states to the PC
  }
   
  
      
}

// FUNCTION DEFINITIONS

void readAnalogs() //read analog values and update accordingly.
{  
  Joystick.setRxAxis(analogRead(A0));  
  Joystick.setRyAxis(analogRead(A1));
  Joystick.setRzAxis(analogRead(A2));
  //Joystick.setXAxis(analogRead(A8));
  //Joystick.setYAxis(analogRead(A9));
  //Joystick.setZAxis(analogRead(A10));
  //Joystick.setThrottle(analogRead(A6));    
}