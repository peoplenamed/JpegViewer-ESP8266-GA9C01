#ifndef _MOUTH_ELEMENT_H_
#define _MOUTH_ELEMENT_H_
/*********************
 *      INCLUDES
 *********************/
#include "config.h"

/**********************
 *      TYPEDEFS
 **********************/
enum MouthType
{
	MOUTH_CLOSED,
	MOUTH_GRUMPY_ONE,
	MOUTH_GRUMPY_TWO,
	MOUTH_FANGS_ONE,
	MOUTH_FANGS_TWO,
	MOUTH_SMILE_ONE,
	MOUTH_SMILE_TWO,
	MOUTH_SMILE_FILLED,
};

class MouthElement
{
public:
	int x;
	int y;

	static const unsigned char mouth_closed[] PROGMEM;
	static const unsigned char mouth_grumpy_one[] PROGMEM;
	static const unsigned char mouth_grumpy_two[] PROGMEM;
	static const unsigned char mouth_fangs_one[] PROGMEM;
	static const unsigned char mouth_fangs_two[] PROGMEM;
	static const unsigned char mouth_smile_filled[] PROGMEM;
	static const unsigned char mouth_smile_two[] PROGMEM;
	static const unsigned char mouth_smile_one[] PROGMEM;

	MouthElement(int x, int y);

	void render(MouthType type, uint16_t foreground, uint16_t background);
};
#endif