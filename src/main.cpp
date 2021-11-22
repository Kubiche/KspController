#include <Arduino.h>
#include <LedControl_HW_SPI.h>
#include <KerbalSimpit.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MCP3008.h>
#include "inboundMessages.h"
#include "leds.h"
#include "controls.h"


KerbalSimpit mySimpit(Serial);

LedControl_HW_SPI lc = LedControl_HW_SPI();

Adafruit_MCP3008 adc;

Adafruit_MCP23X17 io;

#define io_int_pin 8


void setup() {
  
  //Led driver MAX7219
  lc.begin(10);
  lc.shutdown(0,false); // Turn on the led controller  
  lc.setIntensity(0,5);
  lc.clearDisplay(0); 

  //ADC MCP3008
  adc.begin(9);

  //------------------------------------------------------Write any test code above here since the while below will halt code---------------------------------------------------------------------------------------------

  //IO expander MCP23017
  io.begin_I2C(0x21);
  io.setupInterrupts(true, false, LOW); //sets up interrupts to be mirrored, be pulled high and to pull the pin low if interrupt occurs.
  for (int i = 0 ; i < 16; i++){  
    io.pinMode(i, INPUT_PULLUP); //set up all the pins as input and pull them high
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

  if (digitalRead(io_int_pin) == LOW) {
      
  }

  //throttle message to simpit mod
  throttleMessage throttle_msg;
  throttle_msg.throttle = map(adc.readADC(0), 0, 1023, 0, INT16_MAX);
  mySimpit.send(THROTTLE_MESSAGE, throttle_msg);

                       

}