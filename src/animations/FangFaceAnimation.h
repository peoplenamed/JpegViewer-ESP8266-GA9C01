#ifndef _FANG_FACE_ANIMATION_H_
#define _FANG_FACE_ANIMATION_H_
/*********************
 *      INCLUDES
 *********************/
#include "../../config.h";
#include "elements/EyeElement.h";
#include "elements/MouthElement.h";

/*********************
 *      Class
 *********************/
class FangFaceAnimation
{
public:
    FangFaceAnimation();
    void renderIn();
    void renderOut();
    void renderLoop();

private:
    EyeElement eyeLeftElement;
    EyeElement eyeRightElement;
    MouthElement mouthElement;
};
#endif