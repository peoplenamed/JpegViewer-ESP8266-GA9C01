/*********************
 *      INCLUDES
 *********************/
#include "animations/maths/TriangleWipe.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
TriangleWipe::TriangleWipe() { }

// Setting background color will wipe screen
void TriangleWipe::renderFrame(boolean _wipe,
							uint16_t forecolor,
							uint16_t backgroundColor) {

	displayService.wipeScreen(_wipe, backgroundColor);

	int32_t i;
	int32_t cx = _SCREEN_WIDTH / 2;
	int32_t cy = _SCREEN_HEIGHT / 2;
	int32_t cx1 = cx - 1;
	int32_t cy1 = cy - 1;
	int32_t cn = min(cx1, cy1);
	// digit size

	for(i = 0; i < cn; i += 5)
	{
		displayService.DrawTriangle(cx1,
							 cy1 - i, // peak
							 cx1 - i,
							 cy1 + i, // bottom left
							 cx1 + i,
							 cy1 + i, // bottom right
							 forecolor);
	}
}