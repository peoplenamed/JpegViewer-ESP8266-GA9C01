#ifndef FACEANIMATION_H
#define FACEANIMATION_H

/*********************
 *      INCLUDES
 *********************/
#include "../config.h"
#include "elements/EyeElement.h"
#include "elements/MouthElement.h"

/*********************
 *      Class
 *********************/
class FaceAnimation
{
public:
	// Constructor declaration
	FaceAnimation();

	// Pure virtual functions for the animation
	virtual void renderIn() = 0;
	virtual void renderOut() = 0;
	virtual void renderLoop() = 0;

	// Virtual destructor declaration
	virtual ~FaceAnimation();
};

#endif // FACEANIMATION_H