

#include <SoftwareSerial.h>

#define BAUD_RATE 115200

// RX: GPIO14, TX: GPIO12, no inverse, buffer size 256, 8 databits, 1 stopbit
SoftwareSerial swSer(14, 12, false, 256);

// RX: GPIO14, TX: GPIO12, no inverse, buffer size 256, 7 databits, 2 stopbits
// SoftwareSerial swSer(14, 12, false, 256, 7, 2);


void setup() {
  Serial.begin(BAUD_RATE);
  swSer.begin(BAUD_RATE);

  Serial.println("\nSoftware serial test started");

  for (char ch = ' '; ch <= 'z'; ch++) {
    swSer.write(ch);
  }
  swSer.println("");

}

void loop() {
  while (swSer.available() > 0) {
    Serial.write(swSer.read());
    yield();
  }
  while (Serial.available() > 0) {
    swSer.write(Serial.read());
    yield();
  }

}
