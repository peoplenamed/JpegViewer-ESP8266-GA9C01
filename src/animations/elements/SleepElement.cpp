/*********************
 *      INCLUDES
 *********************/
#include "SleepElement.h"

/*********************
 *      DEFINES
 *********************/
void SleepElement::render(int x, int y)
{
	// gfx->fillRect(x, y, 10, 10, BLACK);
	gfx->setCursor(x, y);
	gfx->setTextSize(2);
	gfx->setTextColor(WHITE);
	gfx->println(F("z"));
}