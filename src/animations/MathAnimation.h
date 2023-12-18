#ifndef _MATH_ANIMATION_H_
#define _MATH_ANIMATION_H_

/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/DisplayService.h"

/*********************
 *      Class
 *********************/
class MathAnimation
{
	public:
		// Constructor declaration
		MathAnimation();

		virtual void renderFrame(int frame, boolean wipe, uint16_t foreground, uint16_t background) = 0;
		virtual int getTotalFrames() = 0;
		virtual void setTotalFrames(int _frames) = 0;

		// Virtual destructor declaration
		virtual ~MathAnimation();

	private:
		int frames;

};

#endif // _ANIMATION_H_