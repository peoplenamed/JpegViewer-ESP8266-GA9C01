#ifndef _CIRCLE_WIPE_H_
#define _CIRCLE_WIPE_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/DisplayService.h"
#include "animations/MathAnimation.h"

/*********************
 *      Class
 *********************/
class CircleWipe : public MathAnimation
{
    public:
        CircleWipe();

        // Frames can effectively act like a non-blocking timeout for text
        void renderFrame(int frame, boolean _wipe, uint16_t forecolor, uint16_t backgroundColor);
	    int getTotalFrames();
        void setTotalFrames(int _frames);
    private:
        DisplayService displayService;
        int frames = 5;

};
#endif