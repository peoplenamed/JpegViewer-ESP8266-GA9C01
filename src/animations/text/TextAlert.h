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
	    int getTotalFrames();
        void renderFrame(int textType, char* text, boolean _wipe, uint16_t foreground, uint16_t background,
							bool _drawBackgroundColor);
        void setCustomSettings(int _x, int _y, int _size, uint16_t _color);

    private:
        int frames = 5;
        bool drawBackgroundColor = false;
        uint16_t _errorColor = RED;
        uint16_t _successColor = GREEN;
        const int _x = 0;
        const int _y = 105;
        const int _size = 4;
        int x;
        int y;
        int size;
        uint16_t color;
};
#endif