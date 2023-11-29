#include "config.h"

Arduino_DataBus *graphic_bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS);
Arduino_GFX *gfx = new Arduino_GC9A01(graphic_bus, TFT_RST, 0, true);

int current_animation = 0;