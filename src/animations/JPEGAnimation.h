#ifndef _JPEG_ANIMATION_H_
#define _JPEG_ANIMATION_H_

/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/JpegFunkService.h"

/*********************
 *      Class
 *********************/
class JPEGAnimation
{
	public:
		// Constructor declaration
		JPEGAnimation();

		virtual void renderFrame(int frame) = 0;
		virtual int getTotalFrames() = 0;

		// Virtual destructor declaration
		virtual ~JPEGAnimation();
	private:
		int frames = 0;

};

#endif // _JPEG_ANIMATION_H_