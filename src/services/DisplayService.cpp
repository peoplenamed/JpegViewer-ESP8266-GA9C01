/*********************
 *      INCLUDES
 *********************/
#include "DisplayService.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

JpegFunk Display::jpegFunk;

/**********************
 *      MACROS
 **********************/

/**********************
 *      CLASS
 **********************/

Display::Display() {}

void Display::setupDisplay()
{
    // #ifdef ESP8826
    // #include <LittleFS.h>
    // #define TFT_CS D8
    // #define TFT_DC D2
    // #define TFT_RST D4
    // #define TFT_MISO -1 // no data coming back
    //     Arduino_DataBus *bus = new Arduino_ESP8266SPI(TFT_DC /* DC */, TFT_CS /* CS */);
    //     Arduino_GFX *gfx = new Arduino_GC9A01(bus, TFT_RST /* RST */, 0 /* rotation */, true /* IPS */);
    // #endif

    // #ifdef ESP32
    // #include <FS.h>
    // #ifdef USE_LittleFS
    // #define SPIFFS LITTLEFS
    // #include <LITTLEFS.h>
    // #else
    // #include <SPIFFS.h>
    // #endif

    // #define TFT_CS 22
    // #define TFT_DC 16
    // #define TFT_RST 4
    // #define TFT_MISO -1 // no data coming back

    //     bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS);
    //     gfx = new Arduino_GC9A01(bus, TFT_RST, 0 /* rotation */, true /* IPS */);
    // #endif
    Serial.print("Display initializer");
    // Init Display
    if (!gfx->begin())
    {
        Serial.println("gfx->begin() failed!");
    }
    else
    {
#ifdef DEBUG
        Serial.println("gfx->begin() initialized.");
#endif
        wipeScreen(true);
    }
}

void Display::wipeScreen(boolean wipe)
{
    if (wipe)
    {
        gfx->fillScreen(0x0000);
        // gfx->fillScreen(hexColors.black);
    }
}

void Display::setText(String text)
{
    int len = text.length() + 1;
    char charArray[len];
    text.toCharArray(charArray, len);

    gfx->println(charArray);
}

void Display::drawText(String _text, int _x, int _y, int _size, int _color)
{
    gfx->setCursor(_x, _y);
    gfx->setTextColor(0x0000);
    // gfx->setTextColor(hexColors.getHexColor(_color));
    gfx->setTextSize(_size);
    setText(_text);
}

int Display::jpegDrawCallback(JPEGDRAW *pDraw)
{
#ifdef DEBUG
    Serial.printf("Draw pos = %d,%d. size = %d x %d\n", pDraw->x, pDraw->y, pDraw->iWidth, pDraw->iHeight);
#endif
    gfx->draw16bitBeRGBBitmap(pDraw->x, pDraw->y, pDraw->pPixels, pDraw->iWidth, pDraw->iHeight);
    return 1;
}

void Display::drawImage(char *fileName)
{
#ifdef DEBUG
    Serial.print("Drawing ");
    Serial.println(fileName);
#endif
    int _width = 240;
    int _height = 240;

    jpegFunk.jpegDraw(fileName, jpegDrawCallback, true /* useBigEndian */, 0, 0, _width /* widthLimit */, _height /* heightLimit */);
}

void Display::drawJpgAnimation(String name, String fileType, int frames, int times)
{
    for (int x = 1; x <= times; x++)
    {
        for (int i = 0; i <= frames - 1; i++)
        {
            String filename;
            filename.concat(name);

            if (i < 10)
            {
                filename.concat("00");
            }
            else
            {
                filename.concat("0");
            }
            filename.concat(i);
            filename.concat(fileType);

            int len = filename.length() + 1;
            char charArray[len];
            filename.toCharArray(charArray, len);

            drawImage(charArray);
        }
    }
}

void Display::DrawCircle(int32_t x, int32_t y, int32_t radius, int32_t color)
{
    gfx->drawCircle(x, y, radius, color);
}

void Display::DrawTriangle(int32_t peak, int32_t bottom_left, int32_t bottom_right, int32_t idk1, int32_t idk2, int32_t idk3, int32_t color)
{
    gfx->drawTriangle(peak, bottom_left, bottom_right, idk1, idk2, idk3, color);
}
