#ifndef _ANIMATION_H
#define _ANIMATION_H

/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/DisplayService.h"

/*********************
 *      Class
 *********************/
class Animation
{
	public:
		// Constructor declaration
		Animation();

		virtual void renderFrame(int frame, uint16_t foreground, uint16_t background) = 0;
		virtual void getPixels(Pixel *&pixels, int frame, uint16_t foreground, uint16_t background) = 0;
		virtual int getTotalFrames() = 0;

		// Virtual destructor declaration
		virtual ~Animation();

	private:
		int frames;

};

#endif // _ANIMATION_H_