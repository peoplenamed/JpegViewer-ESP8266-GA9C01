#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "pinout.h"
#include <ArduinoLog.h>
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

// https://github.com/thijse/Arduino-Log
//  * 0 - LOG_LEVEL_SILENT     no output
//  * 1 - LOG_LEVEL_FATAL      fatal errors
//  * 2 - LOG_LEVEL_ERROR      all errors
//  * 3 - LOG_LEVEL_WARNING    errors, and warnings
//  * 4 - LOG_LEVEL_NOTICE     errors, warnings and notices
//  * 5 - LOG_LEVEL_TRACE      errors, warnings, notices & traces
//  * 6 - LOG_LEVEL_VERBOSE    all

#define LOG_LEVEL LOG_LEVEL_VERBOSE

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

extern int current_animation;
#endif