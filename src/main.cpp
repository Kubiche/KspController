#include <Arduino.h>
#include <KerbalSimpit.h>
#include <Joystick.h>
#include <HID.h>
#include <Wire.h>
#include "inboundMessages.h"
#include <leds.h>
#include <MCP23017.h>
#include "Inputs.h"

#define DEBUG 0

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif



MCP23017 io1;

KerbalSimpit mySimpit(Serial);

extern Joystick_ Joystick;

void setup() 
{
  
  Wire.begin(); // set up I2c bus
  SPI.begin(); // set up SPI bus

  // Set the joystick to manual update to prevent USB overflow
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
    setLedReg(i, 0);
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
  
  mySimpit.update(); // Update messages from simpit mod, as part of it the function messageHandler gets called to process the mod's output in our code (see inboundMessages.h)
  updateAnalogs();
  
      
}