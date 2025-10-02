#include <U8x8lib.h>

/*
baseline:
Sketch uses 5160 bytes (17%) of program storage space. Maximum is 28672 bytes.
Global variables use 185 bytes (7%) of dynamic memory, leaving 2375 bytes for local variables. Maximum is 2560 bytes.

U8X8:
Sketch uses 10818 bytes (37%) of program storage space. Maximum is 28672 bytes.
Global variables use 606 bytes (23%) of dynamic memory, leaving 1954 bytes for local variables. Maximum is 2560 bytes.

PGMEM▲: 5658
 SRAM▲: 501
*/

U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

unsigned long last = 0;
unsigned long wait = 1250;
char stampChars[16];

void setup(void) {
  u8x8.begin();
  // Oooh! PowerSave!
  u8x8.setPowerSave(0);
}

void loop(void) {
  unsigned long stamp = millis();
  if (stamp - last > wait) {
    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.drawString(0, 0, "Millis: ");
    sprintf(stampChars, "%ld", stamp);
    u8x8.drawString(0, 1, stampChars);
    last = stamp;
  }
}
