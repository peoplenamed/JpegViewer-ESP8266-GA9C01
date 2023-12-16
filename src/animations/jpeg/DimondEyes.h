#ifndef _DIMOND_EYES_H_
#define _DIMOND_EYES_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "animations/JPEGAnimation.h"
#include "services/DisplayService.h"


/*********************
 *      Class
 *********************/
class DimondEyes : public JPEGAnimation
{
    public:
        DimondEyes();

        // Frames can be used like a delay...
        int frames = 10;
        void renderFrame(int frame, int _delay=0);

    private:
        DisplayService displayService;
};
#endif