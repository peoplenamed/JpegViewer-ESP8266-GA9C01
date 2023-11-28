#ifndef _GRUMPY_FACE_ANIMATION_H_
#define _GRUMPY_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "../../config.h";
#include "elements/EyeElement.h";
#include "elements/MouthElement.h";

/*********************
 *      Class
 *********************/
class GrumpyFaceAnimation
{
public:
    GrumpyFaceAnimation();
    void renderIn();
    void renderOut();
    void renderLoop();

private:
    EyeElement eyeLeftElement;
    EyeElement eyeRightElement;
    MouthElement mouthElement;
};
#endif