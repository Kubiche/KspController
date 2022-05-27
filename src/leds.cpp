#include "leds.h"




uint8_t digit[8] {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}; //array to store the max7219 digit values to be used by the leds

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
  uint8_t mask = 0b10000000 >>(seg-1);
  if ((digit[dig] & mask) != state){
    digit[dig] ^= mask; 
    setLedReg((dig+1), digit[dig]);
  }
}

// arrays to store mask for bit manupulation depending on the led bar
static const uint8_t bar1Mask[2] {0b00000000, 0b00111111};
static const uint8_t bar2Mask[2] {0b11000000, 0b00001111};
static const uint8_t bar3Mask[2] {0b11110000, 0b00000011};
static const uint8_t bar4Mask[2] {0b11111100, 0b00000000};

// These functions apply a mask to the byte/digit controlling the lower and upper part of each led bar and set a value on it leaving the ones for other bars alone
void show_in_bar_1(uint8_t value)
{
  switch (value)
  {          
    case 1:            
      digit[0] = 0b10000000;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];            
      setLedReg(OP_DIGIT1, digit[1]);
      break;        
    case 2:            
      digit[0] = 0b11000000;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];            
      setLedReg(OP_DIGIT1, digit[1]);
      break;
    case 3:            
      digit[0] = 0b11100000;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];            
      setLedReg(OP_DIGIT1, digit[1]);
      break;
    case 4:            
      digit[0] = 0b11110000;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];
      setLedReg(OP_DIGIT1, digit[1]);
      break;
    case 5: 
      digit[0] = 0b11111000;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];            
      setLedReg(OP_DIGIT1, digit[1]);
      break;
    case 6:             
      digit[0] = 0b11111100;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];            
      setLedReg(OP_DIGIT1, digit[1]);
      break;
    case 7:            
      digit[0] = 0b11111110;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];            
      setLedReg(OP_DIGIT1, digit[1]);
      break;
    case 8:             
      digit[0] = 0b11111111;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];            
      setLedReg(OP_DIGIT1, digit[1]);
      break;
    case 9:
      digit[0] = 0b11111111;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];
      digit[1] |= 0b10000000;
      setLedReg(OP_DIGIT1, digit[1]);
      break;
    case 10:
      digit[0] = 0b11111111;
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];
      digit[1] |= 0b11000000;
      setLedReg(OP_DIGIT1, digit[1]);
      break;
    default:            
      digit[0] = 0b00000000;            
      setLedReg(OP_DIGIT0, digit[0]);
      digit[1] &= bar1Mask[1];
      setLedReg(OP_DIGIT1, digit[1]);                        
      break; 
  }
}

void show_in_bar_2(uint8_t value)
{
    switch (value)
    {        
          case 1:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00100000;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];            
            setLedReg(OP_DIGIT2, digit[2]); 
            break;        
          case 2:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00110000;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];            
            setLedReg(OP_DIGIT2, digit[2]);
            break;
          case 3:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111000;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];            
            setLedReg(OP_DIGIT2, digit[2]);
            break;
          case 4:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111100;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];
            setLedReg(OP_DIGIT2, digit[2]);
            break;
          case 5: 
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111110;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];            
            setLedReg(OP_DIGIT2, digit[2]);
            break;
          case 6:             
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];            
            setLedReg(OP_DIGIT2, digit[2]);
            break;
          case 7:            
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b10000000;            
            setLedReg(OP_DIGIT2, digit[2]);
            break;
          case 8:             
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b11000000;            
            setLedReg(OP_DIGIT2, digit[2]);
            break;
          case 9:
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b11100000;
            setLedReg(OP_DIGIT2, digit[2]);
            break;
          case 10:
            digit[1] &= bar2Mask[0];
            digit[1] |= 0b00111111;
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];
            digit[2] |= 0b11110000;
            setLedReg(OP_DIGIT2, digit[2]);
            break;
          default:
            digit[1] &= bar2Mask[0];            
            setLedReg(OP_DIGIT1, digit[1]);
            digit[2] &= bar2Mask[1];
            setLedReg(OP_DIGIT2, digit[2]);
            break;
        }
}

void show_in_bar_3(uint8_t value){
    switch (value){            
            case 1:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001000;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];            
            setLedReg(OP_DIGIT3, digit[3]);
            break;        
          case 2:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001100;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];            
            setLedReg(OP_DIGIT3, digit[3]);
            break;
          case 3:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001110;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];            
            setLedReg(OP_DIGIT3, digit[3]);
            break;
          case 4:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];
            setLedReg(OP_DIGIT3, digit[3]);
            break;
          case 5: 
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b10000000;            
            setLedReg(OP_DIGIT3, digit[3]);
            break;
          case 6:             
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11000000;            
            setLedReg(OP_DIGIT3, digit[3]);
            break;
          case 7:            
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11100000;            
            setLedReg(OP_DIGIT3, digit[3]);
            break;
          case 8:             
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11110000;            
            setLedReg(OP_DIGIT3, digit[3]);
            break;
          case 9:
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11111000;
            setLedReg(OP_DIGIT3, digit[3]);
            break;
          case 10:
            digit[2] &= bar3Mask[0];
            digit[2] |= 0b00001111;
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];
            digit[3] |= 0b11111100;
            setLedReg(OP_DIGIT3, digit[3]);
            break;
          default:
            digit[2] &= bar3Mask[0];            
            setLedReg(OP_DIGIT2, digit[2]);
            digit[3] &= bar3Mask[1];
            setLedReg(OP_DIGIT3, digit[3]);
            break;
        }


}

void show_in_bar_4(uint8_t value){
    switch (value){
          case 1:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000010;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];            
            setLedReg(OP_DIGIT4, digit[4]);
            break;        
          case 2:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[3] &= bar4Mask[1];            
            setLedReg(OP_DIGIT4, digit[4]);
            break;
          case 3:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b1000000;            
            setLedReg(OP_DIGIT4, digit[4]);
            break;
          case 4:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b1100000;
            setLedReg(OP_DIGIT4, digit[4]);
            break;
          case 5: 
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11100000;            
            setLedReg(OP_DIGIT4, digit[4]);
            break;
          case 6:             
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11110000;            
            setLedReg(OP_DIGIT4, digit[4]);
            break;
          case 7:            
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11111000;            
            setLedReg(OP_DIGIT4, digit[4]);
            break;
          case 8:             
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11111100;            
            setLedReg(OP_DIGIT4, digit[4]);
            break;
          case 9:
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11111110;
            setLedReg(OP_DIGIT4, digit[4]);
            break;
          case 10:
            digit[3] &= bar4Mask[0];
            digit[3] |= 0b0000011;
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];
            digit[4] |= 0b11111111;
            setLedReg(OP_DIGIT4, digit[4]);
            break;
          default:
            digit[3] &= bar4Mask[0];            
            setLedReg(OP_DIGIT3, digit[3]);
            digit[4] &= bar4Mask[1];
            setLedReg(OP_DIGIT4, digit[4]);
            break;
        }
}