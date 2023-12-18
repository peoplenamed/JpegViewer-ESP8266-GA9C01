#ifndef _DRAW_RIM_CIRCLE_H_
#define _DRAW_RIM_CIRCLE_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/DisplayService.h"
#include "animations/MathAnimation.h"

/*********************
 *      Class
 *********************/
class DrawRimCircle : public MathAnimation
{
    public:
        DrawRimCircle();

        // Frames can effectively act like a non-blocking timeout for text
        int frames = 5;
        void renderFrame(int radius, boolean _wipe, uint16_t forecolor, uint16_t backgroundColor);
	    int getTotalFrames();
        void setTotalFrames(int _frames);

    private:
        DisplayService displayService;

};
#endif