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
	#ifdef DEBUG
		Log.trace("<wipeScreen>  wipe: %b, color: %i\n", wipe, backgroundColor);
	#endif
	if (wipe)
	{
		gfx->fillScreen(backgroundColor);
	}
}

void DisplayService::setText(String text)
{
	#ifdef DEBUG
		Log.trace("<setText>  text: %s\n", text);
	#endif
	int len = text.length() + 1;
	char charArray[len];
	text.toCharArray(charArray, len);

	gfx->println(charArray);
}

void DisplayService::drawText(String _text, int _x, int _y, int _size, int _color)
{
	#ifdef DEBUG
		Log.trace("<drawText>  text: %s, x:%d, y:%d, size:%d, color:%d\n", _text, _x, _y, _size, _color);
	#endif
	gfx->setCursor(_x, _y);
	gfx->setTextColor(_color);
	gfx->setTextSize(_size);
	setText(_text);
}

int DisplayService::jpegDrawCallback(JPEGDRAW* pDraw)
{
	#ifdef DEBUG
		Log.trace("<jpegDrawCallback>  (x:%d,y:%d), (x1:%d y1:%d)\n", pDraw->x, pDraw->y, pDraw->iWidth, pDraw->iHeight);
	#endif
	gfx->draw16bitBeRGBBitmap(pDraw->x, pDraw->y, pDraw->pPixels, pDraw->iWidth, pDraw->iHeight);
	return 1;
}

void DisplayService::drawImage(char* fileName)
{
	#ifdef DEBUG
		Log.info("<drawImage> fileName: %s\n", fileName);
	#endif
	jpegFunk.jpegDraw(fileName,
					  jpegDrawCallback,
					  true /* useBigEndian */,
					  0,
					  0,
					  _SCREEN_WIDTH /* widthLimit */,
					  _SCREEN_HEIGHT /* heightLimit */);
}

void DisplayService::drawJpgAnimationFrame(String name, String fileType, int frame)
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
	#ifdef DEBUG
		Log.info("<drawJpgAnimationFrame> name: %s\n", name);
		Log.info("<drawJpgAnimationFrame> charArray: %s\n", charArray);
	#endif

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
