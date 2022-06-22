#pragma once

#define DEBUG 1

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#define debuglnB(x) Serial.print(x, BIN)
#else
#define debug(x)
#define debugln(x)
#define debuglnB(x) 
#endif                                            