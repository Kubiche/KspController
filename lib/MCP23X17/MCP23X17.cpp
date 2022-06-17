#include "MCP23X17.h"
#include <Wire.h>
#include "Debug.h"

void MCP23017::init(uint8_t I2CAddress, uint8_t intPin)
{
    _deviceAddress = I2CAddress;
    _intPin = intPin;
    pinMode(_intPin, INPUT_PULLUP);
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_IOCON);
    Wire.write(0b01111100);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_IODIRA);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_IODIRB);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_GPINTENA);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_GPINTENB);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_INTCONA);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_INTCONB);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_GPPUA);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_GPPUB);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_IPOLA);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_IPOLB);
    Wire.write(0xFF);
    Wire.endTransmission();
}

uint8_t MCP23017::readGPIOs()
{
  Wire.beginTransmission(_deviceAddress);
  Wire.write(MCP23017_INTFB);
  Wire.endTransmission();
  Wire.requestFrom(_deviceAddress, 2);
  uint8_t i = 0;
  unsigned int intflag = 0;
  while (Wire.available())
  {
    intflag = intflag << (8*i);
    intflag = (intflag | Wire.read());    
    i++;
  }
  uint8_t bitpos = 0;
  while ((intflag - (1 << bitpos)))
  {
    bitpos++;
  }
  Wire.beginTransmission(_deviceAddress);
  Wire.write(MCP23017_GPIOB);
  Wire.endTransmission();
  Wire.requestFrom(_deviceAddress, 2);
  int j = 0;    
  while (Wire.available())
  {
    gpio = gpio << (8*j);
    gpio = (gpio | Wire.read());
    j++;                
  }
  return bitpos;
}