/*********************
 *      INCLUDES
 *********************/
#include "animations/maths/Circlewipe.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
CircleWipe::CircleWipe() { }

// Setting background color will wipe screen
void CircleWipe::renderFrame(int radius,
							boolean _wipe,
							uint16_t forecolor,
							uint16_t backgroundColor) {

	displayService.wipeScreen(_wipe, backgroundColor);

	int32_t w = _SCREEN_WIDTH;
	int32_t h = _SCREEN_HEIGHT;
	int32_t x, y;
	int32_t r2 = radius * 2;
	int32_t w1 = w + radius;
	int32_t h1 = h + radius;

	for(x = 0; x < w1; x += r2)
	{
		for(y = 0; y < h1; y += r2)
		{
			displayService.DrawCircle(x, y, radius, forecolor);
		}
	}
}