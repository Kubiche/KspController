#include "MCP23017.h"
#include <Wire.h>

void MCP23017::init(int I2CAddress){
    _deviceAddress = I2CAddress;
    Wire.beginTransmission(_deviceAddress);
    Wire.write(MCP23017_IOCON);
    Wire.write(0b11111100);
    Wire.endTransmission(false);
    Wire.write(MCP23017_IODIRA);
    Wire.write(0xFF);
    Wire.endTransmission(false);
    Wire.write(MCP23017_IODIRB);
    Wire.write(0xFF);
    Wire.endTransmission(false);
    Wire.write(MCP23017_GPINTENA);
    Wire.write(0xFF);
    Wire.endTransmission(false);
    Wire.write(MCP23017_GPINTENB);
    Wire.write(0xFF);
    Wire.endTransmission(false);
    Wire.write(MCP23017_INTCONA);
    Wire.write(0xFF);
    Wire.endTransmission(false);
    Wire.write(MCP23017_INTCONB);
    Wire.write(0xFF);
    Wire.endTransmission();
}

uint8_t MCP23017::readGPIO(uint8_t _gpio){
    Wire.beginTransmission(_deviceAddress);
    Wire.write(_gpio);
    Wire.endTransmission();
    Wire.requestFrom(_deviceAddress, 1);
    return Wire.read();
    
}