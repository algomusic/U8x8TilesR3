// test the U8x8TilesR3 library 

#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
U8X8_SH1107_128X128_HW_I2C u8x8(/* reset=*/ 0); // replace init for diff screens

#include "U8x8TilesR3.h"
U8x8TilesR3 display;

void setup() {
  Serial.begin(115200);
  u8x8.begin();
  Serial.println("starting U8x8TilesR3 test");

  display.drawWord(0, 0, "Hello World", 11);
  display.drawNumber(5, 3, 2);
  display.drawWord(4, 5, "Cat", 3);
  display.drawWordBar(4, 6, "Cat", 3);
  display.drawDial9(4, 8, 0);
  display.drawWord4(0, 12, "String", 6);
}

void loop() {
  display.drawNumber(5, 3, random(10));
  display.drawDial9(4, 8, random(1024));
  delay(1000);
}
