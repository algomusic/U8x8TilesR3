/*
 * U8x8TilesR3.h
 *
 * This library writes to a OLED display board using u8x8 tiles. 
 * The 128 x 128 pixel display is treated as a grid of 16 x 16 tiles of 8 x 8 pixels.
 * It is designed to write to a 90 degree rotated display (with the top connecting pins on the right),
 * be very lightwight in memory and data transfer, and avoid interrupts.
 * It utilises the u8g2lib library by Oliver Kraus 2016, which must be included and setup in the main sketch.
 * It provides a limited set of functions to draw numbers, letters, symbols, dials, and indicator bars.
 *
 * Written by Andrew R. Brown 2023
 *
 * Delveloped for use with the Arduino IDE and the SH1107 OLED display board, but may work with boards.
 *
 * U8x8TilesR3.h is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 */

#ifndef U8X8TILESR3_H_
#define U8X8TILESR3_H_

class U8x8TilesR3 {

public:

 /** Constructor */
  U8x8TilesR3() { };

  /* Draw a single-tile number at the specified tile location on the display */
  void drawNumber(int x, int y, int n) { 
    u8x8.drawTile(y-yOffset, xOffset-x, 1, numbers[n]);
  }

  /* Draw a four-tile sized uppercase letter 
  * starting at the specified tile location on the display 
  */
  void drawLetter4(int x, int y, int l) {
    u8x8.drawTile(y-yOffset, xOffset-x, 1, letters4[l][0]);
    u8x8.drawTile(y-yOffset, xOffset-1-x, 1, letters4[l][1]);
    u8x8.drawTile(y-yOffset+1, xOffset-x, 1, letters4[l][2]);
    u8x8.drawTile(y-yOffset+1, xOffset-1-x, 1, letters4[l][3]);
  }

  /* Draw a nine-tile circle at the specified location. */
  void drawCircle9(int x, int y) {
    u8x8.drawTile(y - yOffset, xOffset - x, 1, circle9[0]);
    u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, circle9[1]);
    u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, circle9[2]);
    u8x8.drawTile(y - yOffset+1, xOffset - x, 1, circle9[3]);
    u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, circle9[4]);
    u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, circle9[5]);
    u8x8.drawTile(y - yOffset+2, xOffset - x, 1, circle9[6]);
    u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, circle9[7]);
    u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, circle9[8]);
  }

  /* Draw a nine-tile dial at the specified location
  * displaying the value from 0 to 1024.
  */
  void drawDial9(int x, int y, int val) {  // val 0 - 1024
    int pos = val * 0.0118; // pos 0 _ 12
    switch (pos) {
      case 0:
        drawCircle9(x, y);
        break;
      case 1:
        drawCircle9(x, y);
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_1[0]);  // 4
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_1[1]);  // 7
        break;
      case 2:
        u8x8.drawTile(y - yOffset, xOffset - x, 1, circle9[0]);
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, circle9[1]);
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, circle9[2]);
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, circle9[5]);
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, circle9[8]);
        //
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_2[0]);  // 3
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_2[1]);  // 4
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);  // 6
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_2[3]);  // 7
        break;
      case 3:
        u8x8.drawTile(y - yOffset, xOffset - x, 1, circle9[0]);
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, circle9[1]);
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, circle9[2]);
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, circle9[5]);
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, circle9[8]);
        //
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_3[0]);  // 3
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_3[1]);  // 4
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);  // 6
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_2[3]);  // 7
        break;
      case 4:
        u8x8.drawTile(y - yOffset, xOffset - x, 1, circle9[0]);
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, circle9[1]);
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, circle9[2]);
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, circle9[5]);
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, circle9[8]);
        //
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_4[0]);  // 3
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_4[1]);  // 4
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);  // 6
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_2[3]);  // 7
        break;
      case 5:
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, circle9[2]);
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, circle9[5]);
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, circle9[8]);
        //
        u8x8.drawTile(y - yOffset, xOffset - x, 1, dial9_5[0]);  // 0
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, dial9_5[1]);  // 1
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_5[2]);  // 3
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_5[3]);  // 4
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);  // 6
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_2[3]);  // 7
        break;
      case 6:
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, circle9[2]);
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, circle9[5]);
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, circle9[8]);
        //
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, dial9_6[0]);  // 1
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_6[1]);  // 4
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);  // 6
        u8x8.drawTile(y - yOffset, xOffset - x, 1, dial9_5[0]);  // 0
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_5[2]);  // 3
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_2[3]);  // 7
        break;
      case 7:
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, circle9[5]);
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, circle9[8]);
        //
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, dial9_7[0]);  // 1
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, dial9_7[1]);  // 2
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_7[2]);  // 4
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);  // 6
        u8x8.drawTile(y - yOffset, xOffset - x, 1, dial9_5[0]);  // 0
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_5[2]);  // 3
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_2[3]);  // 7
        break;
      case 8:
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, circle9[8]);
        //
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, dial9_8[0]);  // 2
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_8[1]);  // 4
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, dial9_8[2]);  // 5
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);  // 6
        u8x8.drawTile(y - yOffset, xOffset - x, 1, dial9_5[0]);  // 0
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, dial9_7[0]);  // 1
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_5[2]);  // 3
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_2[3]);  // 7
        break;
      case 9:
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, circle9[8]);
        //
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_9[0]);  // 4
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, dial9_9[1]);  // 5
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);  // 6
        u8x8.drawTile(y - yOffset, xOffset - x, 1, dial9_5[0]);  // 0
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, dial9_7[0]);  // 1
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, dial9_8[0]);  // 2
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_5[2]);  // 3
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_2[3]);  // 7
        break;
      case 10:
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_10[0]);  // 4
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, dial9_10[1]);  // 5
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, dial9_10[2]);  // 8
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);   // 6
        u8x8.drawTile(y - yOffset, xOffset - x, 1, dial9_5[0]);   // 0
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, dial9_7[0]);   // 1
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, dial9_8[0]);   // 2
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_5[2]);   // 3
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_2[3]);   // 7
        break;
      case 11:
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_11[0]);  // 4
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, dial9_11[1]);  // 5
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_11[2]);  // 7
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, dial9_11[3]);  // 8
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);   // 6
        u8x8.drawTile(y - yOffset, xOffset - x, 1, dial9_5[0]);   // 0
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, dial9_7[0]);   // 1
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, dial9_8[0]);   // 2
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_5[2]);   // 3

        break;
      case 12:
        u8x8.drawTile(y - yOffset+1, xOffset-1 - x, 1, dial9_12[0]);  // 4
        u8x8.drawTile(y - yOffset+2, xOffset-1 - x, 1, dial9_12[1]);  // 7
        u8x8.drawTile(y - yOffset+2, xOffset - x, 1, dial9_2[2]);   // 6
        u8x8.drawTile(y - yOffset, xOffset - x, 1, dial9_5[0]);   // 0
        u8x8.drawTile(y - yOffset, xOffset-1 - x, 1, dial9_7[0]);   // 1
        u8x8.drawTile(y - yOffset, xOffset-2 - x, 1, dial9_8[0]);   // 2
        u8x8.drawTile(y - yOffset+1, xOffset-2 - x, 1, dial9_11[1]);  // 5
        u8x8.drawTile(y - yOffset+1, xOffset - x, 1, dial9_5[2]);   // 3
        u8x8.drawTile(y - yOffset+2, xOffset-2 - x, 1, dial9_11[3]);  // 8
        break;
    }
  }

  /* Draw a five-tile high VU metre at the specified tile location */
  void drawVUBar5(int x, int y, int val) {  // val, 0 - 40
    if (val <= 8) {
      u8x8.drawTile(y - yOffset + 4, xOffset - x, 1, vuBars[val]);
      u8x8.drawTile(y - yOffset + 3, xOffset - x, 1, vuBars[0]);
      u8x8.drawTile(y - yOffset + 2, xOffset - x, 1, vuBars[0]);
      u8x8.drawTile(y - yOffset + 1, xOffset - x, 1, vuBars[0]);
      u8x8.drawTile(y - yOffset + 0, xOffset - x, 1, vuBars[0]);
    } else if (val <= 16) {
      u8x8.drawTile(y - yOffset + 4, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 3, xOffset - x, 1, vuBars[val - 8]);
      u8x8.drawTile(y - yOffset + 2, xOffset - x, 1, vuBars[0]);
      u8x8.drawTile(y - yOffset + 1, xOffset - x, 1, vuBars[0]);
      u8x8.drawTile(y - yOffset + 0, xOffset - x, 1, vuBars[0]);
    } else if (val <= 24) {
      u8x8.drawTile(y - yOffset + 4, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 3, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 2, xOffset - x, 1, vuBars[val - 16]);
      u8x8.drawTile(y - yOffset + 1, xOffset - x, 1, vuBars[0]);
      u8x8.drawTile(y - yOffset + 0, xOffset - x, 1, vuBars[0]);
    } else if (val <= 32) {
      u8x8.drawTile(y - yOffset + 4, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 3, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 2, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 1, xOffset - x, 1, vuBars[val - 24]);
      u8x8.drawTile(y - yOffset + 0, xOffset - x, 1, vuBars[0]);
    } else if (val <= 40) {
      u8x8.drawTile(y - yOffset + 4, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 3, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 2, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 1, xOffset - x, 1, vuBars[8]);
      u8x8.drawTile(y - yOffset + 0, xOffset - x, 1, vuBars[val - 32]);
    }
  }

  /* Draw up to seven four-tile high VU metre at the specified tile location */
  void drawWord4(int x, int y, String word, int length) { // mode name, length chars pad with spaces, no punctuation
    char charbuf[length+1];
    word.toCharArray(charbuf, length+1);
    for(int i=0; i<length+1; i++) {
      int charVal = (int)charbuf[x+i];
      if (charVal>64 && charVal<91) drawLetter4(x+i*2, y, charVal-65); // caps
      if (charVal>96 && charVal<123) drawLetter4(x+i*2, y, charVal-97); // lower case to caps
      if (charVal == 32) drawLetter4(x+i*2, y, 26); // space
    }
  }

  /* Draw a single-tile centered dash at the specified tile location */
  void drawDash(int x, int y) {
    u8x8.drawTile(y-yOffset, xOffset-x, 1, symbols[0]);
  }

  /* Draw a single-tile dot at the specified tile location */
  void drawDot(int x, int y) {
    u8x8.drawTile(y-yOffset, xOffset-x, 1, symbols[1]);
  }

  /* Draw a single-tile blank space at the specified tile location */
  void drawBlank(int x, int y) {
    u8x8.drawTile(y-yOffset, xOffset-x, 1, symbols[2]);
  }

  /* Draw a single-tile dash at val height location the specified tile x y coords */
  void drawHeightMark(int x, int y, int val) { // 0 - 7
    u8x8.drawTile(y-yOffset, xOffset-x, 1, heightMarks[val]);
  }

  /* Draw a single-tile uppercase letter at the specified tile location */
  void drawLetter(int x, int y, int n) { 
    u8x8.drawTile(y-yOffset, xOffset-x, 1, letters[n]);
  }

  /* Draw a single-tile uppercase letter 
  * with a dotted bar on the right 
  * at the specified tile location */
  void drawLetterBar(int x, int y, int n) { 
    u8x8.drawTile(y-yOffset, xOffset-x, 1, lettersBar[n]);
  }

  /* Draw a string of length single-tile uppercase letters/numbers/spaces at the specified tile location */
  void drawWord(int x, int y, String word, int length) { // length chars pad with spaces, no punctuation
    char charbuf[length+1];
    word.toCharArray(charbuf, length+1);
    for(int i=0; i<length; i++) {
      int charVal = (int)charbuf[i];
      if (charVal>64 && charVal<91) drawLetter(x+i, y, charVal-65); // caps
      if (charVal>96 && charVal<123) drawLetter(x+i, y, charVal-97); // lower case to caps
      if (charVal>=0 && charVal<=9) drawNumber(x+i, y, charVal); // numbers
      if (charVal == 32) drawLetter(x+i, y, 26); // space
    }
  }

  /* Draw a word of single-tile uppercase letters 
  * with a dotted bar on the right at the specified tile location */
  void drawWordBar(int x, int y, String word, int length) { // add bar to 3 chars pad with spaces, no punctuation
    char charbuf[length+1];
    word.toCharArray(charbuf, length+1);
    for(int i=0; i<length; i++) {
      int charVal = (int)charbuf[i];
      if (i < length-1) {
        if (charVal>64 && charVal<91) drawLetter(x+i, y, charVal-65); // caps
        if (charVal>96 && charVal<123) drawLetter(x+i, y, charVal-97); // lower case to caps
        if (charVal>=48 && charVal<=57) drawNumber(x+i, y, charVal-48); // numbers
        if (charVal == 32) drawLetter(x+i, y, 26); // space
      } else { // last char
        if (charVal>64 && charVal<91) drawLetterBar(x+i, y, charVal-65); // caps
        if (charVal>96 && charVal<123) drawLetterBar(x+i, y, charVal-97); // lower case to caps
        if (charVal>=48 && charVal<=57) drawNumber(x+i, y, charVal-48); // numbers
        if (charVal == 32) drawLetterBar(x+i, y, 26); // space
      }
    }
  }

  /* Draw a 3-digit single-tile number (0 to 999) at the specified tile location */
  void draw100(int x, int y, int val) {
    int n = val * 0.098;
    if (n == 100) {
      drawNumber(x, y, 1);
      drawNumber(x+1, y, 0);
      drawNumber(x+2, y, 0);
    } else if (n > 9) {
      drawBlank(x, y);
      drawNumber(x+1, y, floor(n/10));
      drawNumber(x+2, y, n%10);
    } else {
      drawBlank(x, y);
      drawBlank(x+1, y);
      drawNumber(x+2, y, n);
    }
  }

  /* Specify the xOffset value for the target screen size */
  void setXOffset(int val) {
    xOffset = val;
  }

  /* Specify the yOffset value for the target screen size */
  void setYOffset(int val) {
    yOffset = val;
  }

 private:
  uint8_t oledBarRotate = 0;
  // Functions designed for a 128 x 128 display has 16 x 16 tiles of 8 x 8 pixels
  // x axis, y on rotation: -12 to 3 tile positions (odd?)
  // y axis, x on rotation: 15 to 0 tile positions
  uint8_t xOffset = 15; // negative
  uint8_t yOffset = 12;
  // 0,0 is top left corner

  uint8_t circle9[9][8] = { { 0, 0, 7, 4, 8, 16, 32, 32 }, { 0, 126, 129, 0, 0, 0, 0, 0 }, { 0, 0, 224, 32, 16, 8, 4, 4 }, { 32, 64, 64, 64, 64, 64, 64, 32 }, { 0, 0, 0, 24, 24, 16, 16, 16 }, { 4, 2, 2, 2, 2, 2, 2, 4 }, { 32, 32, 16, 8, 4, 3, 0, 0 }, { 16, 16, 16, 16, 16, 129, 126, 0 }, { 4, 4, 8, 16, 32, 192, 0, 0 } };
  uint8_t dial9_1[2][8] = { { 0, 0, 0, 24, 24, 16, 48, 48 }, { 112, 112, 112, 240, 240, 240, 126, 0 } };                                                                                   // 4, 7
  uint8_t dial9_2[4][8] = { { 32, 64, 64, 64, 64, 64, 64, 35 }, { 0, 0, 0, 24, 24, 48, 112, 240 }, { 63, 63, 31, 15, 7, 3, 0, 0 }, { 240, 240, 240, 240, 240, 241, 126, 0 } };             //3, 4, 6, 7
  uint8_t dial9_3[2][8] = { { 32, 64, 64, 64, 127, 127, 127, 63 }, { 0, 0, 0, 24, 248, 240, 240, 240 } };                                                                                  //3, 4
  uint8_t dial9_4[2][8] = { { 56, 127, 127, 127, 127, 127, 127, 63 }, { 0, 0, 192, 248, 248, 240, 240, 240 } };                                                                            // 3, 4
  uint8_t dial9_5[4][8] = { { 0, 0, 3, 7, 15, 31, 63, 63 }, { 0, 126, 129, 0, 0, 128, 128, 128 }, { 63, 127, 127, 127, 127, 127, 127, 63 }, { 192, 192, 224, 248, 248, 240, 240, 240 } };  //0, 1, 3, 4
  uint8_t dial9_6[2][8] = { { 0, 126, 241, 240, 240, 240, 240, 240 }, { 240, 240, 240, 248, 248, 240, 240, 240 } };                                                                        // 1, 4
  uint8_t dial9_7[3][8] = { { 0, 126, 255, 255, 255, 255, 255, 255 }, { 0, 0, 224, 160, 144, 8, 4, 4 }, { 254, 252, 252, 248, 248, 240, 240, 240 } };                                      // 1, 2, 4
  uint8_t dial9_8[3][8] = { { 0, 0, 192, 224, 240, 248, 252, 252 }, { 255, 255, 255, 252, 248, 240, 240, 240 }, { 240, 194, 2, 2, 2, 2, 2, 4 } };                                          //2, 4, 5
  uint8_t dial9_9[2][8] = { { 255, 255, 255, 255, 248, 240, 240, 240 }, { 252, 254, 254, 254, 2, 2, 2, 4 } };
  uint8_t dial9_10[3][8] = { { 255, 255, 255, 255, 255, 243, 240, 240 }, { 252, 254, 254, 254, 254, 254, 254, 60 }, { 12, 4, 8, 16, 32, 192, 0, 0 } };                                                //4, 5, 8
  uint8_t dial9_11[4][8] = { { 255, 255, 255, 255, 255, 247, 243, 241 }, { 252, 254, 254, 254, 254, 254, 254, 252 }, { 241, 240, 240, 240, 240, 241, 126 }, { 252, 252, 248, 112, 96, 192, 0, 0 } };  //4, 5, 7, 8
  uint8_t dial9_12[2][8] = { { 255, 255, 255, 255, 255, 255, 255, 255 }, { 255, 255, 255, 255, 255, 255, 126, 0 } };                                                                                  //4, 7
  uint8_t vuBars[9][8] = { {0, 16, 0, 16, 0, 16, 0, 16}, {0, 16, 0, 16, 0, 16, 0, 124}, {0, 16, 0, 16, 0, 16, 124, 124}, {0, 16, 0, 16, 0, 124, 124, 124 }, {0, 16, 0, 16, 124, 124, 124, 124}, {0, 16, 0, 124, 124, 124, 124, 124}, {0, 16, 124, 124, 124, 124, 124, 124}, {0, 124, 124, 124, 124, 124, 124, 124 }, { 124, 124, 124, 124, 124, 124, 124, 124 } };
  uint8_t letters4[27][4][8] = {{{0,3,7,28,56,56,112,127}, {0,192,224,56,28,28,14,254}, {127,96,96,96,96,96,96,96}, {254,6,6,6,6,6,6,6}}, // A
    {{0,127,127,96,96,96,96,127}, {0,248,252,12,6,6,12,252}, {127,96,96,96,96,96,127,127}, {248,12,6,6,6,12,252,248}}, // B
    {{0,15,31,56,112,96,96,96}, {0,248,252,14,6,6,0,0}, {96,96,96,96,112,56,31,15}, {0,0,0,6,6,14,252,248}}, // C
    {{0,127,127,96,96,96,96,96},{0,248,252,12,6,6,6,6}, {96,96,96,96,96,96,127,127}, {6,6,6,6,6,12,252,248}}, // D
    {{0,127,127,96,96,96,96,127}, {0,254,254,0,0,0,0,248}, {127,96,96,96,96,96,127,127}, {248,0,0,0,0,0,254,254}}, // E
    {{0,127,127,96,96,96,96,127}, {0,254,254,0,0,0,0,248}, {127,96,96,96,96,96,96,96}, {248,0,0,0,0,0,0,0}}, // F
    {{0,31,63,112,96,96,96,96}, {0,254,254,0,0,0,0,124}, {96,96,96,96,96,112,63,31}, {126,6,6,6,6,14,254,252}}, // G
    {{0,96,96,96,96,96,96,127}, {0,6,6,6,6,6,6,254}, {127,96,96,96,96,96,96,96}, {254,6,6,6,6,6,6,6}}, // H
    {{0,31,31,1,1,1,1,1}, {0,248,248,128,128,128,128,128}, {1,1,1,1,1,1,31,31}, {128,128,128,128,128,128,248,248}}, // I
    {{0,0,0,0,0,0,0,0}, {0,62,62,6,6,6,6,6}, {0,0,0,96,96,112,63,31}, {6,6,6,6,6,12,252,248}}, // J
    {{0,96,96,96,97,103,126,120}, {0,6,30,120,224,128,0,0}, {120,124,102,103,97,96,96,96}, {0,0,0,128,224,120,30,6}}, // K
    {{0,96,96,96,96,96,96,96}, {0,0,0,0,0,0,0,0}, {96,96,96,96,96,96,127,127}, {0,0,0,0,0,0,254,254}}, // L
    {{0,96,120,126,103,97,97,97}, {0,6,30,126,230,134,134,134}, {96,96,96,96,96,96,96,96}, {6,6,6,6,6,6,6,6}}, // M
    {{0,96,96,96,120,126,103,97}, {0,6,6,6,6,6,134,230}, {96,96,96,96,96,96,96,96},{126,30,6,6,6,6,6,6}}, // N
    {{0,31,63,112,96,96,96,96}, {0,252,254,14,6,6,6,6}, {96,96,96,96,96,112,63,31}, {6,6,6,6,6,14,254,252}}, // O
    {{0,127,127,96,96,96,96,127}, {0,252,254,14,6,6,14,252}, {127,96,96,96,96,96,96,96}, {248,0,0,0,0,0,0,0}}, // P
    {{0,31,63,112,96,96,96,96}, {0,252,254,14,6,6,6,6}, {96,96,96,96,96,112,63,31}, {6,198,230,118,62,30,254,252}}, // Q
    {{0,127,127,96,96,96,96,127}, {0,248,252,12,6,6,12,252}, {127,124,111,99,96,96,96,96}, {248,0,0,192,240,60,14,6}}, // R
    {{0,31,63,112,96,96,96,63}, {0,248,252,14,6,0,0,252}, {31,0,0,0,96,112,63,31}, {254,14,6,6,6,14,252,248}}, // S
    {{0,127,127,1,1,1,1,1}, {0,254,254,128,128,128,128,128}, {1,1,1,1,1,1,1,1}, {128,128,128,128,128,128,128,128}}, // T
    {{0,96,96,96,96,96,96,96}, {0,6,6,6,6,6,6,6}, {96,96,96,96,96,112,63,31}, {6,6,6,6,6,14,254,252}}, // U
    {{0,96,96,96,96,96,96,96}, {0,6,6,6,6,6,6,6}, {96,96,96,112,56,30,7,1}, {6,6,6,14,28,120,224,128}}, // V
    {{0,96,96,96,96,96,96,96}, {0,6,6,6,6,6,6,6}, {96,96,97,97,103,126,120,96}, {6,6,134,134,230,126,30,6}}, // W
    {{0,96,96,96,96,120,30,7}, {0,6,6,6,6,30,120,224}, {1,7,30,120,96,96,96,96}, {224,248,30,6,6,6,6,6}}, //X
    {{0,96,96,96,96,120,30,7}, {0,6,6,6,6,30,120,224}, {1,1,1,1,1,1,1,1}, {128,128,128,128,128,128,128,128}}, // Y
    {{0,127,127,0,0,0,0,1}, {0,254,254,6,6,30,120,224}, {7,30,120,96,96,96,127,127}, {128,0,0,0,0,0,254,254}}, // Z
    {{0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}}}; // space
  uint8_t symbols[3][8] = {{0, 0, 0, 0, 255, 0, 0, 0}, {0, 0, 0, 24, 24, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};// dash, dot, blank
  uint8_t heightMarks[8][8] = {{0,0,0,0,0,0,0,126}, {0,0,0,0,0,0,126,0}, {0,0,0,0,0,126,0,0}, {0,0,0,0,126,0,0,0}, 
    {0,0,0,126,0,0,0,0}, {0,0,126,0,0,0,0,0}, {0,126,0,0,0,0,0,0}, {126,0,0,0,0,0,0,0}}; // hight marks
  uint8_t numbers[10][8] = {{0, 56, 68, 68, 68, 68, 56, 0}, {0, 48, 80, 16, 16, 16, 124, 0},
    {0, 112, 68, 8, 16, 32, 124}, {0, 56, 68, 4, 24, 68, 56, 0}, {0, 8, 24, 40, 72, 124, 8, 0},
    {0, 124, 64, 56, 4, 68, 56, 0}, {0, 56, 64, 120, 68, 68, 56, 0}, {0, 124, 4, 8, 16, 32, 64, 0},
    {0, 56, 68, 56, 68, 68, 56, 0}, {0, 56, 68, 68, 60, 4, 56, 0}}; // numbers
  uint8_t letters[27][8] = {{0,56,68,68,124,68,68,0}, {0,120,68,68,120,68,120,0}, {0,56,68,64,64,68,56,0}, {0,120,68,68,68,68,120,0}, // A,B,C,D
    {0,124,64,64,120,64,124,0}, {0,124,64,64,120,64,64,0}, {0,56,68,64,92,68,56,0}, {0,68,68,68,124,68,68,0}, // E,F,G,H
    {0,124,16,16,16,16,124,0}, {0,4,4,4,4,68,56,0}, {0,68,72,80,96,72,68,0}, {0,64,64,64,64,64,124,0}, //I,J,K,L
    {0,68,108,84,68,68,68,0}, {0,68,100,84,76,68,68,0}, {0,56,68,68,68,68,56,0}, {0,120,68,68,120,64,64,0}, //M,N,O,P
    {0,56,68,68,84,76,60,0}, {0,120,68,68,120,72,68,0}, {0,56,68,32,24,68,56,0}, {0,124,16,16,16,16,16,0}, //Q,R,S,T
    {0,68,68,68,68,68,56,0}, {0,68,68,68,68,40,16,0}, {0,68,68,84,84,84,40,0}, {0,68,68,40,16,40,68,0}, //U,V,W,  
    {0,68,68,40,16,16,16,0}, {0,124,4,8,16,32,124,0}, {0,0,0,0,0,0,0,0}}; //Y,Z,space
  uint8_t lettersBar[27][8] = {{0,57,68,69,124,69,68,1}, {0,121,68,69,120,69,120,1}, {0,57,68,65,64,69,56,1}, {0,121,68,69,68,69,120,1}, // A,B,C,D
    {0,125,64,65,120,65,124,1}, {0,125,64,65,120,65,64,1}, {0,57,68,65,92,69,56,1}, {0,69,68,69,124,69,68,1}, // E,F,G,H
    {0,125,16,17,16,17,124,1}, {0,5,4,5,4,69,56,1}, {0,69,72,81,96,73,68,1}, {0,65,64,65,64,65,124,1}, //I,J,K,L
    {0,69,108,85,68,69,68,1}, {0,69,100,85,76,69,68,1}, {0,57,68,69,68,69,56,1}, {0,121,68,69,120,65,64,1}, //M,N,O,P
    {0,57,68,69,84,77,60,1}, {0,121,68,69,120,73,68,1}, {0,57,68,33,24,69,56,1}, {0,125,16,17,16,17,16,1}, //Q,R,S,T
    {0,69,68,69,68,69,56,1}, {0,69,68,69,68,41,16,1}, {0,69,68,85,84,85,40,1}, {0,69,68,41,16,41,68,1}, //U,V,W,X
    {0,69,68,41,16,17,16,1}, {0,125,4,9,16,33,124,1}, {0,1,0,1,0,1,0,1}}; //Y,Z,space
};

#endif /* U8X8TILESR3_H_*/