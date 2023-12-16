#ifndef _OCTO_CAT_H_
#define _OCTO_CAT_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "animations/JPEGAnimation.h"
#include "services/DisplayService.h"

/*********************
 *      Class
 *********************/
class OctoCat : public JPEGAnimation
{
    public:
        OctoCat();

        // Frames can be used like a delay...
        int frames = 10;
        void renderFrame(int frame, int _delay=0);

    private:
        DisplayService displayService;
};
#endif