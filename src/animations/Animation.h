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

		virtual void renderFrame(int frame, uint16_t foreground, uint16_t background, bool drawBackgroundColor) = 0;
		virtual FrameObject getFrameObject(int frame, uint16_t foreground,
			uint16_t background, bool _drawBackgroundColor) = 0;
		virtual std::vector<FrameInfo> getFrameInfos(int frame, uint16_t foreground, uint16_t background, bool _drawBackgroundColor) = 0;
		virtual int getTotalFrames() = 0;
		int frames;

		// Virtual destructor declaration
		virtual ~Animation();

	private:

};

#endif // _ANIMATION_H_