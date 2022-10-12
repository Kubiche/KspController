#pragma once

#include <Arduino.h>

class MCP300X
{

public:

  void begin(uint8_t cs);
  unsigned int read(uint8_t channel);

private:
  uint8_t adc_cs_;

};