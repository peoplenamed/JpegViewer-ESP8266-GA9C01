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
	virtual void renderFrame(int frame, char* _text, boolean _wipe, uint16_t foreground, uint16_t background=NULL) = 0;
	int frames = 0;
    DisplayService displayService;

	// Virtual destructor declaration
	virtual ~TextDraw();
};

#endif // TextDraw_H