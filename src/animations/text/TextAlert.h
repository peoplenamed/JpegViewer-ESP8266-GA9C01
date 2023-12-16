#ifndef _TEXT_ALERT_H_
#define _TEXT_ALERT_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "animations/TextDraw.h"

/*********************
 *      Class
 *********************/
class TextAlert : public TextDraw
{
    public:
        TextAlert();

        // Frames can effectively act like a non-blocking timeout for text
        int frames = 5;
        void renderFrame(int textType, char* text, boolean _wipe, uint16_t foreground, uint16_t background);

    private:

};
#endif