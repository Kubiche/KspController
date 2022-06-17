#pragma once

#define DEBUG 0

#if DEBUG == 1
#define debug(x, y) Serial.print(x, y)
#define debugln(x, y) Serial.println(x, y)
#else
#define debug(x, y)
#define debugln(x, y)
#endif                                            