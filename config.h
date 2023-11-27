#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "pinout.h"
#include <Arduino.h>
#include <Arduino_GFX_Library.h>

// Define Globals
#define _HEIGHT 240
#define _WIDTH 240

#define _EYE_LEFT_X 56
#define _EYE_LEFT_Y 66

#define _EYE_RIGHT_X 120
#define _EYE_RIGHT_Y 66

#define _MOUTH_X 56
#define _MOUTH_Y 120

// #ifdef ESP8266
// // Include little FS on ESP8266
// #include <LittleFS.h>

// // Setup Graphics Interace
// Arduino_DataBus *bus = new Arduino_ESP8266SPI(TFT_DC /* DC */, TFT_CS /* CS */);
// Arduino_GFX *gfx = new Arduino_GC9A01(bus, TFT_RST /* RST */, 0 /* rotation */, true /* IPS */);
// #endif

// #ifdef ESP32
//  Include little FS or SPIFFS on ESP32
#include <FS.h>
#ifdef USE_LittleFS
#define SPIFFS LITTLEFS
#include <LITTLEFS.h>
#else
#include <SPIFFS.h>
#endif

extern Arduino_DataBus *graphic_bus;
extern Arduino_GFX *gfx;

#endif