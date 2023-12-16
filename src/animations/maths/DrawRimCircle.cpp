/*********************
 *      INCLUDES
 *********************/
#include "animations/maths/DrawRimCircle.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
DrawRimCircle::DrawRimCircle() { }

// Setting background color will wipe screen
void DrawRimCircle::renderFrame(int maxWipe,
							boolean _wipe,
							uint16_t forecolor,
							uint16_t backgroundColor) {
	displayService.wipeScreen(_wipe, backgroundColor);

	int32_t _x = 120; // radius/2
	int32_t _y = 120; // radius/2

	for(int y = 0; y < maxWipe; y++)
	{
		displayService.DrawCircle(_x, _y, 240 - y, forecolor);
		// displayService.DrawCircle(_x, _y, 120 - y, forecolor);
	}
}