#include <Arduino.h>
#include <KerbalSimpit.h>
#include <HID.h>
#include <Wire.h>
#include "inboundMessages.h"
#include "Inputs.h"
#include "Debug.h"

extern MCP23017 io1;
extern MCP23017 io2;

KerbalSimpit mySimpit(Serial);

LED leds(LED_CS, 2);

extern Joystick_ Joystick;

void setup() 
{  
  Wire.begin(); // set up I2c bus
  SPI.begin(); // set up SPI bus

  // Initiate and set the joystick to manual update to prevent USB overflow
	Joystick.begin(false);  

 //ADC
 pinMode(ADC_CS, OUTPUT);
 digitalWrite(ADC_CS, HIGH);

 

  
  
   

  // MCP23017 IO expanders  
  //io1.init(IO1_I2C_ADDRESS, IO1_INT_PIN);
  //io2.init(IO2_I2C_ADDRESS, IO2_INT_PIN);


  //------------------------------------------------------Write any test code above here since the while below will halt code---------------------------------------------------------------------------------------------
    
  Serial.begin(115200); // Initialize Serial connection to mod  
  pinMode(BOOT_MODE_PIN, INPUT_PULLUP);
  delay(5000);
  if (digitalRead(BOOT_MODE_PIN))
  {
    while (!mySimpit.init()) 
    {
      delay(100);
    }    
  }
  else
  {
    debugln("MOD connection bypassed");
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
  updateDigitals();
  Joystick.sendState(); //Send joystick updated states to the PC      
}