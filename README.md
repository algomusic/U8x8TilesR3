# U8x8TilesR3
OLED display library using u8x8 tiles.

A 128 x 128 pixel display is treated as a grid of 16 x 16 tiles of 8 x 8 pixels.

The library is designed to write to a 90-degree rotated display (with the top connecting pins on the right), be very lightweight in memory and data transfer, and avoid interrupts.

It utilises the u8g2lib library by Oliver Kraus 2016, which must be included and set up in the main sketch.

The library provides limited functions to draw numbers, letters, symbols, dials, and indicator bars.

Written by Andrew R. Brown 2023

Developed for use with the Arduino IDE and the SH1107 OLED display board, but may work with boards.

U8x8TilesR3.h is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
