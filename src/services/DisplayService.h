#ifndef _DISPLAY_SERVICE_H_
#define _DISPLAY_SERVICE_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "JpegFunkService.h"
#include "services/ColorsService.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *      CLASS
 **********************/

class DisplayService
{
public:
	DisplayService();
	//  ~();

	void setupDisplay();
	void wipeScreen(boolean wipe, uint16_t backgroundColor=0);
	void setText(String text);
	void drawText(String _text, int _x, int _y, int _size, int _color);
	static int jpegDrawCallback(JPEGDRAW* pDraw);
	void drawImage(char* fileName);
	void DrawTriangle(int16_t peak,
					  int16_t bottom_left,
					  int16_t bottom_right,
					  int16_t idk1,
					  int16_t idk2,
					  int16_t idk3,
					  int16_t color);
	void DrawCircle(int16_t x, int16_t y, int16_t radius, int16_t color);
	void drawJpgAnimationFrame(String name, String fileType, int frame);
	// Deprecated in favor of new frame system.
	// void drawJpgAnimations(String name, String fileType, int frames, int times);

private:
	ColorsService colorsService;
	static JpegFunk jpegFunk;
};

#endif // _DISPLAY_SERVICE_H_
