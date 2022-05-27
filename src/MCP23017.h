#pragma once

#include <Arduino.h>


// registers
#define MCP23017_IODIRA 0x00   //!< I/O direction register
#define MCP23017_IODIRB 0x10   //!< I/O direction register
#define MCP23017_GPINTENA 0x02 //!< Interrupt-on-change control register
#define MCP23017_GPINTENB 0x12 //!< Interrupt-on-change control register
#define MCP23017_INTCONA 0x04 //!< Default compare register for interrupt-on-change
#define MCP23017_INTCONB 0x14 //!< Interrupt control register
#define MCP23017_IOCON 0x05  //!< Configuration register
#define MCP23017_GPPUA 0x06   //!< Pull-up resistor configuration register
#define MCP23017_GPPUB 0x16   //!< Pull-up resistor configuration register
#define MCP23017_INTCAP 0x08 //!< Interrupt capture register
#define MCP23017_GPIOA 0x09   //!< Port register
#define MCP23017_GPIOB 0x19   //!< Port register




class MCP23017 
{
public:
    void init(uint8_t I2CAddress);    
    uint8_t readGPIO(uint8_t _gpio);    
    
private:
    uint8_t _deviceAddress;
    
};