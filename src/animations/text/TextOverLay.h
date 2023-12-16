#ifndef _TEXT_DRAW_H_
#define _TEXT_DRAW_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "animations/TextDraw.h"

/*********************
 *      Class
 *********************/
class TextOverLay : public TextDraw
{
    public:
        TextOverLay();

        int frames = 6;
        void renderFrame(int textType, char* text, boolean _wipe, uint16_t foreground, uint16_t background);

    private:

};
#endif