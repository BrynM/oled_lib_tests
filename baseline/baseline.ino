// Done the same as the other tests, but using Serial for output.

/*
baseline:
Sketch uses 5160 bytes (17%) of program storage space. Maximum is 28672 bytes.
Global variables use 185 bytes (7%) of dynamic memory, leaving 2375 bytes for local variables. Maximum is 2560 bytes.
*/

unsigned long last = 0;
unsigned long wait = 1250;
char stampChars[16];

void setup() {
  while(Serial.available() == 0 && millis() < 2000);
}

void loop() {
  unsigned long stamp = millis();
  if (stamp - last > wait) {
    Serial.print("Millis: ");
    sprintf(stampChars, "%ld", stamp);
    Serial.println(stampChars);
    last = stamp;
  }
}
