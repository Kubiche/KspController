#include "MCP300X.h"
#include <spi.h>


void MCP300X::init(uint8_t CS)
{ 
 _CS = CS;  
 pinMode(_CS, OUTPUT);
 digitalWrite(_CS, HIGH);
}


unsigned int MCP300X::read(uint8_t channel)
{
  uint8_t adcBuffer[3]; //stores data temporarily to transmit to IC ans stores received readings to return
  adcBuffer[0] = 0b00000001; //this is the start bit as per datasheet section 6.1
  adcBuffer[1] = 0b10000000 | (channel << 4); //harcoded 1 for single ended reading ans channel number combined
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  digitalWrite(_CS, LOW);
  SPI.transfer(adcBuffer, 3); 
  digitalWrite(_CS, HIGH);
  SPI.endTransaction();
  unsigned int read = ((adcBuffer[1] & 0b00000011) << 8) | adcBuffer[2]; //combine the relevant bits to come up with the actual reading
  return read;
}