#include <Arduino.h>
#include <LedControl.h>
#include <KerbalSimpit.h>

byte digit[8]; //array to store the max7219 digit values.
byte bar1Mask[2] {0b00000000, 0b00111111};
byte bar2Mask[2] {0b11000000, 0b00001111};
byte bar3Mask[2] {0b11110000, 0b00000011};
byte bar4Mask[2] {0b11111100, 0b00000000};

LedControl lc=LedControl(12,11,10,1);

void initializeBars() {
  lc.shutdown(0,false); // Turn on the led controller  
  lc.clearDisplay(0);
}

void setLED(int digit, int led, bool state) {
    lc.setLed(0, digit, led, state);
}

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
        switch (map(mySStageFuel.available, 0, mySStageFuel.total, 0, 50)){
          case 0:
            digit[0] = 0;            
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];
            lc.setRow(0,1,digit[1]);                        
            break;
          case 5:            
            digit[0] = 0b10000000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;        
          case 10:            
            digit[0] = 0b11000000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 15:            
            digit[0] = 0b11100000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 20:            
            digit[0] = 0b11110000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];
            lc.setRow(0,1,digit[1]);
            break;
          case 25: 
            digit[0] = 0b11111000;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 30:             
            digit[0] = 0b11111100;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 35:            
            digit[0] = 0b11111110;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 40:             
            digit[0] = 0b11111111;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];            
            lc.setRow(0,1,digit[1]);
            break;
          case 45:
            digit[0] = 0b11111111;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];
            digit[1] |= 0b10000000;
            lc.setRow(0,1,digit[1]);
            break;
          case 50:
            digit[0] = 0b11111111;
            lc.setRow(0,0,digit[0]);
            digit[1] &= bar1Mask[1];
            digit[1] |= 0b11000000;
            lc.setRow(0,1,digit[1]);
            break;  
        }      
      }
    break;
  case LF_STAGE_MESSAGE:
      if (msgSize == sizeof(resourceMessage)){
        resourceMessage myLStageFuel;
        myLStageFuel = parseResource(msg);
        switch (map(myLStageFuel.available, 0, myLStageFuel.total, 0, 50)){
        case 0:
            digit[1] &= bar2Mask[0];            
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            lc.setRow(0,2,digit[2]);                        
            break;
          case 5:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00100000;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;        
          case 10:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00110000;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;
          case 15:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111000;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;
          case 20:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111100;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            lc.setRow(0,2,digit[2]);
            break;
          case 25: 
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111110;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;
          case 30:             
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];            
            lc.setRow(0,2,digit[2]);
            break;
          case 35:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b10000000;            
            lc.setRow(0,2,digit[2]);
            break;
          case 40:             
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b11000000;            
            lc.setRow(0,2,digit[2]);
            break;
          case 45:
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b11100000;
            lc.setRow(0,2,digit[2]);
            break;
          case 50:
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            lc.setRow(0,1,digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b11110000;
            lc.setRow(0,2,digit[2]);
            break;
        }
      }
      break;




  }


}