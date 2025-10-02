#include "SH1106.h"

/*
baseline:
Sketch uses 5160 bytes (17%) of program storage space. Maximum is 28672 bytes.
Global variables use 185 bytes (7%) of dynamic memory, leaving 2375 bytes for local variables. Maximum is 2560 bytes.

SH1106:
Sketch uses 14910 bytes (52%) of program storage space. Maximum is 28672 bytes.
Global variables use 1514 bytes (59%) of dynamic memory, leaving 1046 bytes for local variables. Maximum is 2560 bytes.

PGMEM▲: 9750
 SRAM▲: 1329
*/

SH1106 oled;

unsigned long last = 0;
unsigned long wait = 1250;
char stampChars[16];

void setup() {
  while(Serial.available() == 0 && millis() < 2000);
  oled.begin();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.clearDisplay();
  oled.display();
}

void loop() {
  unsigned long stamp = millis();
  if (stamp - last > wait) {
    oled.clearDisplay();
    oled.setCursor(0, 0);
    oled.println("Millis: ");
    sprintf(stampChars, "%ld", stamp);
    oled.print(stampChars);
    oled.display();
    last = stamp;
  }
}
