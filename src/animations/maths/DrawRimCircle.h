#ifndef _DRAW_RIM_CIRCLE_H_
#define _DRAW_RIM_CIRCLE_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/DisplayService.h"

/*********************
 *      Class
 *********************/
class DrawRimCircle
{
    public:
        DrawRimCircle();

        // Frames can effectively act like a non-blocking timeout for text
        int frames = 5;
        void renderFrame(int radius, boolean _wipe, uint16_t forecolor, uint16_t backgroundColor);
        DisplayService displayService;

    private:

};
#endif