#ifndef _EYE_VIEW_H_
#define _EYE_VIEW_H_
/*********************
 *      INCLUDES
 *********************/

class EyeView
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

    EyeView(int x, int y);

    void render(int type);
};
#endif