#include "MCP300X.h"
#include <spi.h>

unsigned int readADC(uint8_t channel)
{
  uint8_t adcBuffer[3];
  adcBuffer[0] = 0b00000001;
  adcBuffer[1] = 0b10000000 | (channel << 4);
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));
  digitalWrite(ADC_CS, LOW);
  SPI.transfer(adcBuffer, 3);
  digitalWrite(ADC_CS, HIGH);
  SPI.endTransaction();
  unsigned int read = ((adcBuffer[1] & 0b00000011) << 8) | adcBuffer[2];
  return read;
}