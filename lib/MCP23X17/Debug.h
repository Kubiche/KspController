#pragma once

#define DEBUG 0

#if DEBUG == 1
<<<<<<< HEAD
#define debug(x) Serial.print(x)
#define debugln(x, y) Serial.println(x, y)
#else
#define debug(x)
=======
#define debug(x, y) Serial.print(x, y)
#define debugln(x, y) Serial.println(x, y)
#else
#define debug(x, y)
>>>>>>> c978ae64cd07af11917ccc2997560cb28d1c5671
#define debugln(x, y)
#endif                                            