#ifndef _TRIANGLE_WIPE_H_
#define _TRIANGLE_WIPE_H_

/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/DisplayService.h"

/*********************
 *      Class
 *********************/
class TriangleWipe
{
    public:
        TriangleWipe();

        // Frames can effectively act like a non-blocking timeout for text
        int frames = 5;
        void renderFrame(boolean _wipe, uint16_t forecolor, uint16_t backgroundColor);

    private:
        DisplayService displayService;

};
#endif