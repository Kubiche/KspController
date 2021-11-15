#include <Arduino.h>
#include <KerbalSimpit.h>
#include "leds.h"

// Message handler required by simpit.
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
        if (mySStageFuel.available == 0){
          show_in_bar_1(0);
        }
        else {
        show_in_bar_1(map(mySStageFuel.available, 0, mySStageFuel.total, 1, 10));
        }      
      }
    break;
  case LF_STAGE_MESSAGE:
      if (msgSize == sizeof(resourceMessage)){
        resourceMessage myLStageFuel;
        myLStageFuel = parseResource(msg);
        if (myLStageFuel.available == 0){
          show_in_bar_2(0);
        }
        else {
          show_in_bar_2(map(myLStageFuel.available, 0, myLStageFuel.total, 1, 10));
        }
      }
    break;
  case MONO_MESSAGE:
      if (msgSize == sizeof(resourceMessage)){
        resourceMessage myMonoFuel;
        myMonoFuel = parseResource(msg);
        show_in_bar_3(map(myMonoFuel.available, 0, myMonoFuel.total, 0, 10));
      }
    break;
  case ELECTRIC_MESSAGE:
      if (msgSize == sizeof(resourceMessage)){
        resourceMessage myBatteryLevel;
        myBatteryLevel = parseResource(msg);
        show_in_bar_4(map(myBatteryLevel.available, 0, myBatteryLevel.total, 0, 10));
      }
    break;
  }
}