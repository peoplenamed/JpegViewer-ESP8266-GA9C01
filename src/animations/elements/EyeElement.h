#ifndef _EYE_ELEMENT_H_
#define _EYE_ELEMENT_H_
/*********************
 *      INCLUDES
 *********************/
#include "../../../config.h"

/**********************
 *      TYPEDEFS
 **********************/
enum EyeType
{
    EYE_OPEN_LR,
    EYE_ANGRY_R,
    EYE_ANGRY_L,
    EYE_DISAPPOINTED_LR,
    EYE_SATISFIED_LR,
    EYE_DIAMOND_LR,
    EYE_CLOSING_LR,
    EYE_CLOSED_LR
};

/**********************
 *      CLASS
 **********************/
class EyeElement
{
public:
    int x;
    int y;

    static const unsigned char eye_angry_r[] PROGMEM;
    static const unsigned char eye_angry_l[] PROGMEM;
    static const unsigned char eye_disappointed_lr[] PROGMEM;
    static const unsigned char eye_satisfied_lr[] PROGMEM;
    static const unsigned char eye_dimond_lr[] PROGMEM;
    static const unsigned char eye_closing_lr[] PROGMEM;
    static const unsigned char eye_closed_lr[] PROGMEM;
    static const unsigned char eye_open_lr[] PROGMEM;

    EyeElement(int x, int y);

    void render(EyeType type);
};
#endif