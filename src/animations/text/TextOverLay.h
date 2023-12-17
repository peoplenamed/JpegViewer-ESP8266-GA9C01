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

	    int getTotalFrames();
        void renderFrame(int textType, char* text, boolean _wipe, uint16_t foreground, uint16_t background);
        void setCustomSettings(int _x, int _y, int _size, uint16_t _color);

    private:
        int frames = 6;
        int x;
        int y;
        int size;
        uint16_t color;
};
#endif