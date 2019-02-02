# EspSoftwareSerial

Implementation of the Arduino software serial library for the ESP8266

This fork supports 1..8 databits and 1 or 2 stopbits. The default is 8 databits and one stopbit.

Example:
```c++
#include <SoftwareSerial.h>

// RX: GPIO14, TX: GPIO12, no inverse, buffer size 256, 7 data bits, 2 stop bits
SoftwareSerial swSer(14, 12, false, 256, 7, 2);
```

Same functionality as the corresponding AVR library but several instances can be active at the same time.
Speed up to 115200 baud is supported. The constructor also has an optional input buffer size.

Please note that due to the fact that the ESP always have other activities ongoing, there will be some inexactness in interrupt
timings. This may lead to bit errors when having heavy data traffic in high baud rates.


