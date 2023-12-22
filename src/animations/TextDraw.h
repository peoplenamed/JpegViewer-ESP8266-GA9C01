#ifndef TextDraw_H
#define TextDraw_H

/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "services/DisplayService.h"

/*********************
 *      Class
 *********************/
class TextDraw
{
public:
	// Constructor declaration
	TextDraw();

	// background will wipe frame
	virtual void renderFrame(int frame, char* _text, boolean _wipe, uint16_t foreground, uint16_t background,
							bool _drawBackgroundColor) = 0;
	virtual void setCustomSettings(int _x, int _y, int _size, uint16_t _color) = 0;
	virtual int getTotalFrames() = 0;
	int frames;
    DisplayService displayService;

	// Virtual destructor declaration
	virtual ~TextDraw();
};

#endif // TextDraw_H