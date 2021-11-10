#include <Arduino.h>
#include <LedControl.h>
#include <KerbalSimpit.h>

byte digit[5] = {0B11111111,0B11111111,0B11111111,0B11111111,0B11111111};



LedControl lc=LedControl(12,11,10,1);

void setup() {
 
  // put your setup code here, to run once:
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  delay(2000);
  for (int i = 0; i < 5; i++){
    lc.setRow(0,i,digit[i]);    
  } 
  delay(2000);
  
}

void loop() {
  // reduce the level in each bar by one every 1 second. Only 1 bar implemented now.
  if (digit[0]) {
    digit[1] = digit[1] & 0B10111111;
    lc.setRow(0,1,digit[1]);
    digit[3] = digit[3] & 0B11101111;
    delay(1000);
    digit[1] = digit[1] & 0B00111111;
    lc.setRow(0,1,digit[1]);
    delay(1000);
    digit[0] = digit[0] & 0B11111110;
    lc.setRow(0,0,digit[0]);
    delay(1000);
    digit[0] = digit[0] & 0B11111100;
    lc.setRow(0,0,digit[0]);
    delay(1000);
    digit[0] = digit[0] & 0B11111000;
    lc.setRow(0,0,digit[0]);
    delay(1000);
    digit[0] = digit[0] & 0B11110000;
    lc.setRow(0,0,digit[0]);
    delay(1000);
    digit[0] = digit[0] & 0B11100000;
    lc.setRow(0,0,digit[0]);
    delay(1000);
    digit[0] = digit[0] & 0B11000000;
    lc.setRow(0,0,digit[0]);
    delay(1000);
    digit[0] = digit[0] & 0B10000000;
    lc.setRow(0,0,digit[0]);
    delay(1000);
    digit[0] = digit[0] & 0B00000000;
    lc.setRow(0,0,digit[0]);
    delay(1000);
  } 

  delay(1000);

  if (digit[0] == false){
    digit[0] = 0B11111111;
    digit[1] = digit[1] | 0B11000000;
    lc.setRow(0,0,digit[0]);
    lc.setRow(0,1,digit[1]);    
  }

  delay(2000);
}