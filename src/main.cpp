#include <Arduino.h>
#include <LedControl.h>
#include <KerbalSimpit.h>

byte digit0 = B11111111;
byte digit1 = B11111111;

LedControl lc=LedControl(12,11,10,1);

void setup() {
 
  // put your setup code here, to run once:
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  delay(2000);
  lc.setRow(0,0,digit0);
  lc.setRow(0,1,digit1);
  delay(2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (digit1 >0){
    delay(1000);
    digit1 = digit1 << 1;
    lc.setRow(0,1,digit1);    
  }
  while (digit0 > 0){
   delay(1000); 
   digit0 = digit0 << 1;
   lc.setRow(0,0,digit0);   
  }  
}