#include <Arduino.h>
#include <LedControl.h>
#include <KerbalSimpit.h>
#include "inboundMessages.h"



unsigned long lastupdated;

KerbalSimpit mySimpit(Serial);

//LedControl lc=LedControl(12,11,10,1);


void setup() {

  Serial.begin(115200); // Initialize Serial connection to mod
  while (!mySimpit.init()); 
  
  initializeBars();

  mySimpit.inboundHandler(messageHandler); // callback function
  
  // Register to fuel messages  
  mySimpit.registerChannel(SF_STAGE_MESSAGE);
  mySimpit.registerChannel(LF_STAGE_MESSAGE);
  mySimpit.registerChannel(MONO_MESSAGE);
  mySimpit.registerChannel(ELECTRIC_MESSAGE);

  
}

void loop() {

  if ((millis() - lastupdated) > 100) {
    mySimpit.update(); // Update with the mod

  }
  

}