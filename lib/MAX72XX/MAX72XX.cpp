#include "MAX72XX.h"
#include "Debug.h"

uint8_t digit[8] {0, 0, 0, 0, 0, 0, 0, 0}; //array to store the max7219 digit values to be used by the leds



void setLedReg(uint8_t opcode, uint8_t val) 
{
  uint8_t led_buffer[2];
  led_buffer[0] = opcode;
  led_buffer[1] = val; 
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));
  digitalWrite(LED_CS, LOW);
  SPI.transfer(led_buffer[0]);
  SPI.transfer(led_buffer[1]);
  digitalWrite(LED_CS, HIGH);
  SPI.endTransaction();
}

void setLed(uint8_t dig, uint8_t seg, bool state)
{
  uint8_t mask = 0b10000000 >> (seg-1);
  if ((digit[dig] & mask) != state){
    digit[dig] ^= mask; 
    setLedReg((dig + 1), digit[dig]);
    
  }
}

// These functions apply a mask to the byte/digit controlling the lower and upper part of each led bar and set a value on it leaving the ones for other bars alone
void show_in_bar(uint8_t bar,uint8_t value)
{ 
  if ((value >= 0) && (value <= 10))
  {
    const unsigned int fullbar[4] {0b1111111111000000, 0b0011111111110000, 0b0000111111111100, 0b0000001111111111};// Array to store the full bar value to manipulate for the actual value  
    const unsigned int barMask[4] {0b0000000000111111, 0b1100000000001111, 0b1111000000000011, 0b1111110000000000}; // arrays to store mask for bit manupulation depending on the led bar  
    uint8_t shifted = (10 - value); // fugure out the amount of bits to shift
    unsigned int barlevel = fullbar[bar] << shifted;  // shift the bits left to show the desired level
    unsigned int levelmask = ~barMask[bar]; // Reverse mask to correct any bits that have been moved to spots where they could interfere with other bars
    barlevel &= levelmask;  // Apply modified mask
    digit[(bar+1)] &= barMask[bar]; // Apply LSBits of actual mask to the top byte of the bar 
    digit[(bar+1)] |= barlevel;     // Apply the LSBits of the value to the top byte of bar
    setLedReg((bar+2), digit[(bar+1)]); // Send the new value of the top byte of the bar to the proper digit
    digit[bar] &= barMask[bar]>>8;      // Apply MSBits of mask to the bottom byte of the bar
    digit[bar] |= barlevel>>8;          // Apply the MSBits of the value to the bottom byte of the bar
    setLedReg((bar+1), digit[bar]);     //  Send the new value of the bottom byte to the propper digit
  }
}     
    

