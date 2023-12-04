#ifndef PINOUT_H
#define PINOUT_H

#define GFX_BL 5 // default backlight pin

#ifdef ESP8266
#	define TFT_CS D8
#	define TFT_DC D2
#	define TFT_RST D4
#	define TFT_MISO -1 // no data coming back
#endif

#ifdef ESP32
#	define TFT_CS 22
#	define TFT_DC 16
#	define TFT_RST 4
#	define TFT_MISO -1 // no data coming back
#endif

#define _SCREEN_HEIGHT 240
#define _SCREEN_WIDTH 240

#endif