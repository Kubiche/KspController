#pragma once

#include <Arduino.h>

class MCP300X
{

public:

  void begin(uint8_t CS);
  unsigned int read(uint8_t channel);

private:
  uint8_t _ADC_CS;

};