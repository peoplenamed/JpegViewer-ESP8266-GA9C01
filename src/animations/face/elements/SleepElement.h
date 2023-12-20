#ifndef _SLEEP_ELEMENT_H_
#define _SLEEP_ELEMENT_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"

/**********************
 *      TYPEDEFS
 **********************/

class SleepElement
{
	public:
		void render(int x, int y);
		void getPixels(Pixel*& pixelBuffer, int type, uint16_t foreground, uint16_t background);
	private:
		int xMax = 64;
		int yMax = 54;
};
#endif