#ifndef _TRIANGLE_WIPE_H_
#define _TRIANGLE_WIPE_H_

/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/DisplayService.h"
#include "animations/MathAnimation.h"

/*********************
 *      Class
 *********************/
class TriangleWipe : public MathAnimation
{
    public:
        TriangleWipe();

        void renderFrame(int frame, boolean _wipe, uint16_t forecolor, uint16_t backgroundColor);
	    int getTotalFrames();
        void setTotalFrames(int _frames);

    private:
        DisplayService displayService;
        int frames = 120;

};
#endif