#pragma once

#include <Arduino.h>




// registers
#define MCP23017_IODIRA 0x00   //!< I/O direction register
#define MCP23017_IODIRB 0x01   //!< I/O direction register
#define MCP23017_IPOLA 0x02    //!< Input polarity register
#define MCP23017_IPOLB 0x03    //!< Input polarity register
#define MCP23017_GPINTENA 0x04 //!< Interrupt-on-change control register
#define MCP23017_GPINTENB 0x05 //!< Interrupt-on-change control register
#define MCP23017_INTCONA 0x08 //!< Default compare register for interrupt-on-change
#define MCP23017_INTCONB 0x09 //!< Interrupt control register
#define MCP23017_IOCON 0x05  //!< Configuration register
#define MCP23017_GPPUA 0x0C   //!< Pull-up resistor configuration register
#define MCP23017_GPPUB 0x0D    //!< Pull-up resistor configuration register
#define MCP23017_INTCAPA 0x10 //!< Interrupt capture register
#define MCP23017_INTCAPB 0x11 //!< Interrupt capture register
#define MCP23017_GPIOA 0x12   //!< Port register
#define MCP23017_GPIOB 0x13   //!< Port register


          

class MCP23017 
{
public:
    void init(int I2CAddress, uint8_t intPin);    
    void readGPIOs(); // Reads gpio registers from IC and stores them in the array bellow.
    uint8_t gpio[2];    
    
private:
    int _deviceAddress;
    uint8_t _intPin;
    
};