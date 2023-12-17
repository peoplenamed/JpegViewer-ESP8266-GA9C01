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

JpegFunk DisplayService::jpegFunk;

/**********************
 *      MACROS
 **********************/

/**********************
 *      CLASS
 **********************/

DisplayService::DisplayService() { }

void DisplayService::setupDisplay()
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
	Log.info("Display initializer\n");
	// Init Display
	if(!gfx->begin())
	{
		Log.fatal("gfx->begin() failed!\n");
	}
	else
	{
		Log.trace("gfx->begin() initialized.\n");
		wipeScreen(true);
	}
}

void DisplayService::wipeScreen(boolean wipe, uint16_t backgroundColor)
{
	if (wipe)
	{
		gfx->fillScreen(backgroundColor);
	}
}

void DisplayService::setText(String text)
{
	int len = text.length() + 1;
	char charArray[len];
	text.toCharArray(charArray, len);

	gfx->println(charArray);
}

void DisplayService::drawText(String _text, int _x, int _y, int _size, int _color)
{
	gfx->setCursor(_x, _y);
	gfx->setTextColor(_color);
	gfx->setTextSize(_size);
	setText(_text);
}

int DisplayService::jpegDrawCallback(JPEGDRAW* pDraw)
{
	Log.trace(
		"Draw pos = %d,%d. size = %d x %d\n", pDraw->x, pDraw->y, pDraw->iWidth, pDraw->iHeight);
	gfx->draw16bitBeRGBBitmap(pDraw->x, pDraw->y, pDraw->pPixels, pDraw->iWidth, pDraw->iHeight);
	return 1;
}

void DisplayService::drawImage(char* fileName)
{
	int _width = 240;
	int _height = 240;

	jpegFunk.jpegDraw(fileName,
					  jpegDrawCallback,
					  true /* useBigEndian */,
					  0,
					  0,
					  _width /* widthLimit */,
					  _height /* heightLimit */);
}

void DisplayService::drawJpgAnimation(String name, String fileType, int frame)
{
	String filename;
	filename.concat(name);

	if(frame < 10)
	{
		filename.concat("00");
	}
	else
	{
		filename.concat("0");
	}
	filename.concat(frame);
	filename.concat(fileType);

	int len = filename.length() + 1;
	char charArray[len];
	filename.toCharArray(charArray, len);

	drawImage(charArray);
}

// void DisplayService::drawJpgAnimations(String name, String fileType, int frames, int times)
// {
// 	for(int x = 1; x <= times; x++)
// 	{
// 		for(int i = 0; i <= frames - 1; i++)
// 		{
// 			String filename;
// 			filename.concat(name);

// 			if(i < 10)
// 			{
// 				filename.concat("00");
// 			}
// 			else
// 			{
// 				filename.concat("0");
// 			}
// 			filename.concat(i);
// 			filename.concat(fileType);

// 			int len = filename.length() + 1;
// 			char charArray[len];
// 			filename.toCharArray(charArray, len);

// 			drawImage(charArray);
// 		}
// 	}
// }

void DisplayService::DrawCircle(int16_t x, int16_t y, int16_t radius, int16_t color)
{
	gfx->drawCircle(x, y, radius, color);
}

void DisplayService::DrawTriangle(int16_t peak,
						   int16_t bottom_left,
						   int16_t bottom_right,
						   int16_t idk1,
						   int16_t idk2,
						   int16_t idk3,
						   int16_t color)
{
	gfx->drawTriangle(peak, bottom_left, bottom_right, idk1, idk2, idk3, color);
}
