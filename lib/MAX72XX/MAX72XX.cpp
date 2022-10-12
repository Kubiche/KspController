#include "MAX72XX.h"
#include "Debug.h"
#include <spi.h>


 void MAX72XX::begin(int cs)
{
<<<<<<< HEAD
  led_cs_ = cs;
  number_of_devices_ = LED_Devices;  
  pinMode(led_cs_, OUTPUT); // Set the CS pin as output
  digitalWrite(led_cs_, HIGH); // Set CS pin to High  
  for (uint8_t i = 0; i < number_of_devices_; i++)
=======
  _LED_CS = LED_CS;   
  pinMode(_LED_CS, OUTPUT); // Set the CS pin as output
  digitalWrite(_LED_CS, HIGH); // Set CS pin to High  
  for (uint8_t i = 0; i < LED_Devices; i++)
>>>>>>> 2321d89d32ef52721de25f2b02fdf0aca1bc410e
  {    
    setLedReg(i, OP_SHUTDOWN, 1); // Turn LED controller on
    setLedReg(i, OP_SCANLIMIT, 7); // set to scan all digit_s
    setLedReg(i, OP_INTENSITY, 2); // Set intensity to 2 of 16
    setLedReg(i, OP_DISPLAYTEST, 1);
    delay(1000);    
    setLedReg(i, OP_DISPLAYTEST, 0);
  }  
}

void MAX72XX::setLedReg(uint8_t device, uint16_t opcode, uint16_t val) 
{
<<<<<<< HEAD
  uint16_t led_buffer[number_of_devices_] = {0};
=======
  uint16_t led_buffer[LED_Devices] = {0};
>>>>>>> 2321d89d32ef52721de25f2b02fdf0aca1bc410e
  led_buffer[device] = opcode;
  led_buffer[device] = (led_buffer[device] << 8);
  led_buffer[device] |= val;   
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));  
  debug("Device 1: ");
  debuglnB(led_buffer[1]);
  debug("Device 0: ");
  debuglnB(led_buffer[0]);
  debugln("sent");  
<<<<<<< HEAD
  for (uint8_t i = 0; i < number_of_devices_; i++)
  {
    digitalWrite(led_cs_, LOW);
    SPI.transfer16(led_buffer[i]); //this is the combination of the opcode and the value desired
    digitalWrite(led_cs_, HIGH);
  }  
=======
  digitalWrite(_LED_CS, LOW);
  for (uint8_t i = 0; i < LED_Devices; i++)
  {    
    SPI.transfer16(led_buffer[i]); //this is the combination of the opcode and the value desired    
  } 
  digitalWrite(_LED_CS, HIGH); 
>>>>>>> 2321d89d32ef52721de25f2b02fdf0aca1bc410e
  SPI.endTransaction();
}

void MAX72XX::setLed(uint8_t device, uint8_t dig, uint8_t seg, bool state)
{
  uint8_t mask = 0b10000000 >> (seg-1);
  if ((digit_[device][dig] & mask) != state){
    digit_[device][dig] ^= mask; 
    setLedReg(device, (dig + 1), digit_[device][dig]);    
  }
}

// This function applies a mask to the byte/digit_ controlling the lower and upper part of each led bar and set a value on it leaving the ones for other bars alone
void MAX72XX::show_in_bar(uint8_t device, uint8_t bar,uint8_t value)
{ 
  // Bars indexed from left to right from 1 to 6 
  if ((value >= 0) && (value <= 10))
  {
    const uint16_t fullbar[6] {0b1111111111000000, 0b0011111111110000, 0b0000111111111100, 0b0000001111111111, 0b1111111111000000, 0b0011111111110000};// Array to store the full bar value to manipulate for the actual value  
    uint8_t barTopByte;
    uint8_t barBottomByte;
    uint8_t topDigitOpcode;
    uint8_t bottomDigitOpcode;
    uint8_t index = bar - 1;
    if ( bar < 5)
    {
      barTopByte = bar;
      barBottomByte = bar - 1;
      topDigitOpcode = bar + 1;
      bottomDigitOpcode = bar;
    }
    else
    {
      barTopByte = bar + 1;
      barBottomByte = bar;
      topDigitOpcode = bar + 2;
      bottomDigitOpcode = bar + 1;
    }    
    uint8_t shifted = (10 - value); // fugure out the amount of bits to shift
<<<<<<< HEAD
    uint16_t barlevel = fullbar[(bar - 1)] << shifted;  // shift the bits left to show the desired level. Bar 1 index 0 of array.
    //unsigned int levelmask = ~barMask[(bar - 1)]; // Reverse mask to correct any bits that have been moved to spots where they could interfere with other bars
    barlevel &= fullbar[(bar - 1)];  // Apply modified mask
    digit_[device][(bar)] &= ~fullbar[(bar - 1)]; // Apply LSBits of actual mask to the top byte of the bar 
    digit_[device][(bar)] |= barlevel;     // Apply the LSBits of the value to the top byte of bar
    setLedReg(0, (bar + 1), digit_[device][bar]); // Send the new value of the top byte of the bar to the proper digit_
    digit_[device][(bar - 1)] &= ~fullbar[(bar - 1)] >> 8;      // Apply MSBits of mask to the bottom byte of the bar
    digit_[device][(bar - 1)] |= barlevel >> 8;          // Apply the MSBits of the value to the bottom byte of the bar
    setLedReg(0, bar, digit_[device][(bar - 1)]);     //  Send the new value of the bottom byte to the propper digit_
=======
    uint16_t barlevel = fullbar[index] << shifted;  // shift the bits left to show the desired level. Bar 1 index 0 of array.    
    barlevel &= fullbar[index];  // Apply modified mask
    digit[device][barTopByte] &= ~fullbar[index]; // Apply LSBits of actual mask to the top byte of the bar 
    digit[device][barTopByte] |= barlevel;     // Apply the LSBits of the value to the top byte of bar
    setLedReg(device, topDigitOpcode, digit[device][barTopByte]); // Send the new value of the top byte of the bar to the proper digit
    digit[device][barBottomByte] &= ~fullbar[index] >> 8;      // Apply MSBits of mask to the bottom byte of the bar
    digit[device][barBottomByte] |= barlevel >> 8;          // Apply the MSBits of the value to the bottom byte of the bar
    setLedReg(device, bottomDigitOpcode, digit[device][barBottomByte]);     //  Send the new value of the bottom byte to the propper digit
>>>>>>> 2321d89d32ef52721de25f2b02fdf0aca1bc410e
  }
}     
    

