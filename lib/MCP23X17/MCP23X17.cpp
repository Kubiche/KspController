#include "MCP23X17.h"
#include <Wire.h>

void MCP23017::init(int I2CAddress)
{
    _deviceAddress = I2CAddress;
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_IOCON);
    Wire.write(0b01111010);
    Wire.endTransmission();
    Wire.write(MCP23017_IODIRA);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.write(MCP23017_IODIRB);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.write(MCP23017_GPINTENA);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.write(MCP23017_GPINTENB);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.write(MCP23017_INTCONA);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.write(MCP23017_INTCONB);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.write(MCP23017_GPPUA);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.write(MCP23017_GPPUB);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.write(MCP23017_IPOLA);
    Wire.write(0xFF);
    Wire.endTransmission();
    Wire.write(MCP23017_IPOLB);
    Wire.write(0xFF);
    Wire.endTransmission();
}

uint8_t MCP23017::readGPIOs()
{
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_GPIOA);
    Wire.endTransmission();
    Wire.requestFrom(_deviceAddress, 2);
    int i = 0;    
    while (Wire.available())
    {
        gpio[i] = Wire.read();
        i++;
    }
    Wire.endTransmission();    
}