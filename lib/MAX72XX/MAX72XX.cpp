#include "MAX72XX.h"

uint8_t digit[8] {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}; //array to store the max7219 digit values to be used by the leds

static const unsigned int fullbar[4] {0b1111111111000000, 0b0011111111110000, 0b0000111111111100, 0b0000001111111111}; 

// arrays to store mask for bit manupulation depending on the led bar
static const unsigned int barMask[4] {0b0000000000111111, 0b1100000000001111, 0b1111000000000011, 0b1111110000000000};

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
  unsigned int barlevel;
  barlevel = barlevel<<(10-value);
  barlevel = fullbar[bar] & ~barMask[bar];  
  digit[bar+1] &= barMask[bar];
  digit[bar+1] |= barlevel;
  digit[bar] &= (barMask[bar]>>8);
  digit[bar] |= (barlevel>>8);      
}     
    

