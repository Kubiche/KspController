#include <Arduino.h>
#include <LedControl.h>
#include <KerbalSimpit.h>
#include "inboundMessages.h"
#include "leds.h"


KerbalSimpit mySimpit(Serial);

LedControl lc=LedControl(12,11,10,1);


void setup() {

  Serial.begin(115200); // Initialize Serial connection to mod
  while (!mySimpit.init()); 
  
  lc.shutdown(0,false); // Turn on the led controller  
  lc.clearDisplay(0);

  mySimpit.inboundHandler(messageHandler); // callback function
  
  // Register to desired messages from simpit
  mySimpit.registerChannel(SF_STAGE_MESSAGE);
  mySimpit.registerChannel(LF_STAGE_MESSAGE);
  mySimpit.registerChannel(MONO_MESSAGE);
  mySimpit.registerChannel(ELECTRIC_MESSAGE);

  
}

void loop() {
  
  mySimpit.update(); // Update messages from simpit 

}