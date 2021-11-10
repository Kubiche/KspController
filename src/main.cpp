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
  // put your main code here, to run repeatedly:
  for (int i = 5; i > -1; i = i - 1){
    while (digit[i]){
      byte current = digit[i];      
      digit[i] = current << 1;
      lc.setRow(0,i,digit[i]);
      delay(1000);
    }
  }
  for (int i = 0; i < 5; i++){
    digit[i] = 0B11111111;
    lc.setRow(0,i,digit[i]);    
  } 
  delay(2000);
}