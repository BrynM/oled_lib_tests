#include <ss_oled.h>

/*
baseline:
Sketch uses 5160 bytes (17%) of program storage space. Maximum is 28672 bytes.
Global variables use 185 bytes (7%) of dynamic memory, leaving 2375 bytes for local variables. Maximum is 2560 bytes.

Sketch uses 11302 bytes (39%) of program storage space. Maximum is 28672 bytes.
Global variables use 465 bytes (18%) of dynamic memory, leaving 2095 bytes for local variables. Maximum is 2560 bytes.

PGMEM▲: 6142
 SRAM▲: 280
*/

SSOLED ssoled;

#define SDA_PIN -1
#define SCL_PIN -1
// no reset pin needed
#define RESET_PIN -1
// let ss_oled find the address of our display
#define OLED_ADDR -1
#define FLIP180 0
#define INVERT 0
// Use the default Wire library
#define USE_HW_I2C 1

unsigned long last = 0;
unsigned long wait = 1250;
char stampChars[16];

void setup() {
  while(Serial.available() == 0 && millis() < 2000);
  oledInit(
    &ssoled,
    OLED_128x64,
    OLED_ADDR,
    FLIP180,
    INVERT,
    USE_HW_I2C,
    SDA_PIN,
    SCL_PIN,
    RESET_PIN,
    400000L
  );
}

void loop() {
  unsigned long stamp = millis();
  if (stamp - last > wait) {
    oledFill(&ssoled, 0, 1);
    oledWriteString(&ssoled, 0, 0, 0,(char *)"Millis: ", FONT_NORMAL, 0, 1);
    sprintf(stampChars, "%ld", stamp);
    oledWriteString(&ssoled, 0, 0, 1, (char*)stampChars, FONT_NORMAL, 0, 1);
    last = stamp;
  }
}
