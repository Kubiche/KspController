#include <Arduino.h>
#include <LedControl_HW_SPI.h>
#include <KerbalSimpit.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MCP3008.h>
#include "inboundMessages.h"
#include "leds.h"
#include "controls.h"


KerbalSimpit mySimpit(Serial);

LedControl_HW_SPI lc=LedControl_HW_SPI();

Adafruit_MCP3008 adc;

Adafruit_MCP23X17 io;


void setup() {
  
  //Led driver related
  lc.begin(10);
  lc.shutdown(0,false); // Turn on the led controller  
  lc.setIntensity(0,5);
  lc.clearDisplay(0); 

  //ADC MCP3008 related
  adc.begin(9);

  //------------------------------------------------------Write any test code above here since the while below will halt code---------------------------------------------------------------------------------------------

  //IO expander MCP23017 related
  if (!io.begin_I2C(0x20)) {     //address not set in circuit as fo now
    //while (1);  //uncomment once actually added
  } 
  
  
  Serial.begin(115200); // Initialize Serial connection to mod
  while (!mySimpit.init()); 

  mySimpit.inboundHandler(messageHandler); // callback function
  
  // Register to desired messages from simpit
  mySimpit.registerChannel(SF_STAGE_MESSAGE);
  mySimpit.registerChannel(LF_STAGE_MESSAGE);
  mySimpit.registerChannel(MONO_MESSAGE);
  mySimpit.registerChannel(ELECTRIC_MESSAGE);

  
}

void loop() {  
  
  mySimpit.update(); // Update messages from simpit, as part of it the function messageHandler gets called to process the mod's output in our code (see inboundMessages.h)

  read_Right_Analog_Stick();

                       

}