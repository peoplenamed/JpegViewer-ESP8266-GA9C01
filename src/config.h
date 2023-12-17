#ifndef _CONFIG_H_
#define _CONFIG_H_

/*********************
 *      INCLUDES
 *********************/
#include "SPIFFS.h"
#include "pinout.h"
#include <Arduino.h>
#include <ArduinoLog.h>
#include <Arduino_GFX_Library.h>
#include <SPI.h>
#include <functional>
#include <iostream>
#include <string>

//  Include little FS or SPIFFS on ESP32

// #define USE_LittleFS
// #ifdef ESP8266
// #	include <LittleFS.h>
// #endif

// #ifdef ESP32
// #define USE_LittleFS

// #include <FS.h>
// #ifdef USE_LittleFS
//   #include <LittleFS.h> 
// #else
//   #include <SPIFFS.h>
// #endif 
// #endif


/*********************
 *      DEFINES
 *********************/

#define _EYE_LEFT_X 56
#define _EYE_LEFT_Y 66

#define _EYE_RIGHT_X 120
#define _EYE_RIGHT_Y 66

#define _MOUTH_X 56
#define _MOUTH_Y 120

#define DEBUG true

// https://github.com/thijse/Arduino-Log
//  * 0 - LOG_LEVEL_SILENT     no output
//  * 1 - LOG_LEVEL_FATAL      fatal errors
//  * 2 - LOG_LEVEL_ERROR      all errors
//  * 3 - LOG_LEVEL_WARNING    errors, and warnings
//  * 4 - LOG_LEVEL_NOTICE     errors, warnings and notices
//  * 5 - LOG_LEVEL_TRACE      errors, warnings, notices & traces
//  * 6 - LOG_LEVEL_VERBOSE    all

#define LOG_LEVEL LOG_LEVEL_VERBOSE

/**********************
 *      TYPEDEFS
 **********************/
enum AnimationState
{
	RENDER_IN,
	RENDER_OUT,
	RENDER_LOOP,
};

enum AvailableAnimations
{
	ANGRY_FACE_ANIMATION,
	PUKE_FACE_ANIMATION,
};

typedef struct
{
	AvailableAnimations animationName;
	AnimationState animationState;
	String animationMarkers;
} GlobalAniumationState;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
extern Arduino_DataBus* graphic_bus;
extern Arduino_GFX* gfx;
extern GlobalAniumationState globalAniumationState;

#endif