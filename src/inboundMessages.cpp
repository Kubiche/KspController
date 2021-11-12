#include <Arduino.h>
#include <LedControl.h>
#include <KerbalSimpit.h>
#include "leds.h"




//extern LedControl lc;



void messageHandler(byte messageType, byte msg[], byte msgSize) {
  switch(messageType) {
  case SF_STAGE_MESSAGE:
      // Checking if the message is the size we expect is a very basic
      // way to confirm if the message was received properly.
      if (msgSize == sizeof(resourceMessage)){
        // Create a new fuel struct
        resourceMessage mySStageFuel;
        // Convert the message we received to an Resource struct.
        mySStageFuel = parseResource(msg);
        show_in_bar_1(map(mySStageFuel.available, 0, mySStageFuel.total, 0, 50));      
      }
    break;
  case LF_STAGE_MESSAGE:
      if (msgSize == sizeof(resourceMessage)){
        resourceMessage myLStageFuel;
        myLStageFuel = parseResource(msg);
        show_in_bar_2(map(myLStageFuel.available, 0, myLStageFuel.total, 0, 50));
      }
    break;




  }


}