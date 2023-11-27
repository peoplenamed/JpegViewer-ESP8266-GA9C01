#ifndef _EYE_FRAME_H_
#define _EYE_FRAME_H_
/*********************
 *      INCLUDES
 *********************/
#include "../../config.h"

class EyeFrame
{
public:
    int x;
    int y;

    static const unsigned char eye_angry_r[] PROGMEM;
    static const unsigned char eye_angry_l[] PROGMEM;
    static const unsigned char eye_disappointed_lr[] PROGMEM;
    static const unsigned char eye_dimond_lr[] PROGMEM;
    static const unsigned char eye_closing_lr[] PROGMEM;
    static const unsigned char eye_closed_lr[] PROGMEM;
    static const unsigned char eye_open_lr[] PROGMEM;

    EyeFrame(int x, int y);

    void render(int type);
};
#endif