/*********************
 *      INCLUDES
 *********************/
#include "CalvinAndHobbes.h"

/*********************
 *      DEFINES
 *********************/
// Constructor implementation
CalvinAndHobbes::CalvinAndHobbes() { }

void CalvinAndHobbes::renderFrame(int frame, int _delay) {
	if (_delay > 0) {
		frames = _delay;
	}
	displayService.drawJpgAnimation("1Ys_", ".jpg", frame);
}
