#include "inboundMessages.h"

// Message handler required by simpit.
void messageHandler(uint8_t messageType, uint8_t msg[], uint8_t msgSize) {
  switch(messageType) {
    case SF_STAGE_MESSAGE: //Current stage solid fuel
      // Checking if the message is the size we expect is a very basic
      // way to confirm if the message was received properly.
      if (msgSize == sizeof(resourceMessage)){
        // Create a new fuel struct
        resourceMessage mySStageFuel;
        // Convert the message we received to an Resource struct.
        mySStageFuel = parseResource(msg);
        if (mySStageFuel.available == 0){
          led.Show_in_bar(Controller_v2, 1, 0);
        }
        else {
          led.Show_in_bar(Controller_v2, 1, map(mySStageFuel.available, 0, mySStageFuel.total, 1, 10));
        }      
      }
        break;
    case LF_STAGE_MESSAGE: //Current stage liquid fuel
      if (msgSize == sizeof(resourceMessage)){
        resourceMessage myLStageFuel;
        myLStageFuel = parseResource(msg);
        if (myLStageFuel.available == 0){
          led.Show_in_bar(Controller_v2, 2, 0);
        }
        else {
          led.Show_in_bar(Controller_v2, 2, map(myLStageFuel.available, 0, myLStageFuel.total, 1, 10));
        }
      }
      break;
    case MONO_MESSAGE: //Vessel total Monopropellant fuel
      if (msgSize == sizeof(resourceMessage)){
        resourceMessage myMonoFuel;
        myMonoFuel = parseResource(msg);
        if (myMonoFuel.available == 0){
          led.Show_in_bar(Controller_v2, 4, 0);
        }
        else {
          led.Show_in_bar(Controller_v2, 4, map(myMonoFuel.available, 0, myMonoFuel.total, 1, 10));
        }
      }
      break;
    case ELECTRIC_MESSAGE: //Vessel total Battery charge
      if (msgSize == sizeof(resourceMessage)){
        resourceMessage myBatteryLevel;
        myBatteryLevel = parseResource(msg);
        if (myBatteryLevel.available == 0){
          led.Show_in_bar(Controller_v2, 5, 0);
        }
        else {        
          led.Show_in_bar(Controller_v2, 5, map(myBatteryLevel.available, 0, myBatteryLevel.total, 1, 10));
        }
      }
      break;
    case SF_MESSAGE:  ////Vessel total Solid fuel
      if (msgSize == sizeof(resourceMessage)){
        resourceMessage mySFuel;
        mySFuel = parseResource(msg);
        if (mySFuel.available == 0){
          led.Show_in_bar(Controller_v2, 1, 0);
        }
        else {
          led.Show_in_bar(Controller_v2, 1, map(mySFuel.available, 0, mySFuel.total, 1, 10));
        }
      }
      break;  
    case LF_MESSAGE:  ////Vessel total Liquid fuel
      if (msgSize == sizeof(resourceMessage))
      {
        resourceMessage myLFuel;
        myLFuel = parseResource(msg);
      if (myLFuel.available == 0)
      {
        led.Show_in_bar(Controller_v2, 2, 0);
      }
      else {
        led.Show_in_bar(Controller_v2, 2, map(myLFuel.available, 0, myLFuel.total, 1, 10));
      }
    }
      break;
    case ACTIONSTATUS_MESSAGE:  ////Vessel total Solid fuel
      if (msg[0] & SAS_ACTION)
      {
        led.SetLed(Controller_v3, 0, 2, true);      
      }
      else
      {
        led.SetLed(Controller_v3, 0,2,false);
      } 
    break;
  }

}