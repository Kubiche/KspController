#pragma once

#include <Arduino.h>

class MCP300X
{

public:

  MCP300X(uint8_t CS);
  unsigned int read(uint8_t channel);

private:
  uint8_t _CS;

};