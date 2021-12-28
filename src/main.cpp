#include <Arduino.h>
#include <KerbalSimpit.h>
#include <Joystick.h>
#include <HID.h>
#include "inboundMessages.h"
#include "leds.h"
#include "controls.h"



KerbalSimpit mySimpit(Serial);

unsigned long axis_last_update = 0;

unsigned long axis_check_interval = 100;

// Create the Joystick
Joystick_ Joystick(0x05,0x04,
  1, 0,                    //  Button Count, Hat Switch Count
  false, false, false,     //  X and Y and Z Axis
  true, true, true,        //  Rx, Ry, or Rz
  false, false,            //  rudder or throttle
  false, false, false);    //  accelerator, brake, or steering


void setup() {

  SPI.begin();

  // Initialize Joystick Library
	Joystick.begin();
  
  
  //Led driver MAX7219  
  pinMode(LED_CS, OUTPUT); // Set the CS pin as output
  digitalWrite(LED_CS, HIGH); // Set CS pin to High
  setLedReg(OP_SHUTDOWN, 1); // Turn LED controller on
  setLedReg(OP_SCANLIMIT, 7); // set to scan all digits
  setLedReg(OP_INTENSITY, 2); // Set intensity to 2 of 16
  //clear the display
  for (int i=8; i>0; i--){
    setLedReg(i, 255);
  }   

  //------------------------------------------------------Write any test code above here since the while below will halt code---------------------------------------------------------------------------------------------
  
  
  Serial.begin(115200); // Initialize Serial connection to mod
  /*while (!mySimpit.init()) {
    delay(100);
  }
  */

  mySimpit.inboundHandler(messageHandler); // callback function
  
  // Register to desired messages from simpit
  mySimpit.registerChannel(SF_STAGE_MESSAGE);
  mySimpit.registerChannel(LF_STAGE_MESSAGE);
  mySimpit.registerChannel(MONO_MESSAGE);
  mySimpit.registerChannel(ELECTRIC_MESSAGE);
  mySimpit.registerChannel(ACTIONSTATUS_MESSAGE);

  
}

void loop() {  
  
  mySimpit.update(); // Update messages from simpit, as part of it the function messageHandler gets called to process the mod's output in our code (see inboundMessages.h)
  

  if ((millis() - axis_last_update) > axis_check_interval) {    
    int readValue = analogRead(A0);
    Joystick.setRxAxis(readValue);
    Serial.println(readValue);
    readValue = analogRead(A1);
    Joystick.setRyAxis(readValue);
    Serial.println(readValue);
    readValue = analogRead(A2);
    Joystick.setRzAxis(readValue);
    Serial.println(readValue);
    axis_last_update = millis();
  }
      
}