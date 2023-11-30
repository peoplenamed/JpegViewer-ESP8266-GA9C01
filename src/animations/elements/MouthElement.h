#ifndef _MOUTH_ELEMENT_H_
#define _MOUTH_ELEMENT_H_
/*********************
 *      INCLUDES
 *********************/
#include "../../../config.h"

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

	MouthElement(int x, int y);

	void render(MouthType type);
};
#endif