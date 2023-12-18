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
void DrawRimCircle::renderFrame(int frame,
							boolean _wipe,
							uint16_t forecolor,
							uint16_t backgroundColor) {
	if (frame == 1) {
		displayService.wipeScreen(_wipe, backgroundColor);
	}
	int32_t _x = 120; // radius/2
	int32_t _y = 120; // radius/2

	displayService.DrawCircle(_x, _y, 120 - frame, forecolor);
}

void DrawRimCircle::setTotalFrames(int _frames) {
	frames = _frames;
}

int DrawRimCircle::getTotalFrames() {
	return frames;
}