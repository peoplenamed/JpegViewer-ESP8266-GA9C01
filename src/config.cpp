#include "config.h"

Arduino_DataBus* graphic_bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS);
Arduino_GFX* gfx = new Arduino_GC9A01(graphic_bus, TFT_RST, 0, true);

GlobalAniumationState globalAniumationState = {
	.animationName = ANGRY_FACE_ANIMATION, .animationState = RENDER_IN, .animationMarkers = "0"};

#ifdef ESP8266
	LittleFS.begin();
#endif

// #ifdef ESP32
// 	SPIFFS.begin();
// #endif
