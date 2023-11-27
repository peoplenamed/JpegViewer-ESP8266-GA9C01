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
    MOUTH_CLOSED
};

class MouthElement
{
public:
    int x;
    int y;

    static const unsigned char mouth_closed[] PROGMEM;

    MouthElement(int x, int y);

    void render(MouthType type);
};
#endif