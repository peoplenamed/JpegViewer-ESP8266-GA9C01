#ifndef _CALVIN_AND_HOBBES_H_
#define _CALVIN_AND_HOBBES_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "animations/JPEGAnimation.h"
#include "services/DisplayService.h"

/*********************
 *      Class
 *********************/
class CalvinAndHobbes : public JPEGAnimation
{
    public:
        CalvinAndHobbes();

        // Frames can be used like a delay...
        int frames = 6;
        void renderFrame(int frame, int _delay=0);

    private:
        DisplayService displayService;

};
#endif