#ifndef _CALVIN_DUPLICATOR_H_
#define _CALVIN_DUPLICATOR_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "animations/JPEGAnimation.h"
#include "services/DisplayService.h"

/*********************
 *      Class
 *********************/
class CalvinDuplicator : public JPEGAnimation
{
    public:
        CalvinDuplicator();

        int frames = 14;
        void renderFrame(int frame);
	    int getTotalFrames();

    private:
        DisplayService displayService;

};
#endif