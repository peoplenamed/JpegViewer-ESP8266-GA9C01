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
void TriangleWipe::renderFrame(int frame, boolean _wipe, uint16_t forecolor, uint16_t backgroundColor) {

	if (frame == 1) {
		displayService.wipeScreen(_wipe, backgroundColor);
	}
	int32_t i;
	int32_t cx = 120; //_SCREEN_WIDTH / 2;
	int32_t cy = 120; //_SCREEN_HEIGHT / 2;
	int32_t cx1 = 119; //cx - 1;
	int32_t cy1 = 119; //cy - 1;
	int32_t orbit = frame * 5;
	#ifdef DEBUG
		Log.trace("[TriangleWipe]<renderFrame>  frame: %i, orbit: %i, wipe: %b\n", frame, orbit, _wipe);
	#endif
	// int32_t cn = 119;
	// digit size

	displayService.DrawTriangle(cx1,
								cy1 - orbit, // peak
								cx1 - orbit,
								cy1 + orbit, // bottom left
								cx1 + orbit,
								cy1 + orbit, // bottom right
								forecolor);

	// for(i = 0; i < cn; i += 5)
	// {
		// displayService.DrawTriangle(cx1,
		// 					 cy1 - i, // peak
		// 					 cx1 - i,
		// 					 cy1 + i, // bottom left
		// 					 cx1 + i,
		// 					 cy1 + i, // bottom right
		// 					 forecolor);
	// }
}

int TriangleWipe::getTotalFrames() {
	return frames;
}

void TriangleWipe::setTotalFrames(int _frames) {
	frames = _frames;
}