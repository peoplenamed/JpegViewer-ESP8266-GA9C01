#ifndef _DRAW_FRAME_SERVICE_H_
#define _DRAW_FRAME_SERVICE_H_

#include "config.h"
#include "services/ColorsService.h"


class DrawFrameService
{
public:
    DrawFrameService();
    ~DrawFrameService();
	virtual void processAnimationFrame() = 0;
    virtual void processCommand(int selected) = 0;

private:

	// FUNCTIONS
	virtual void processCustomCommand(String customJpeg) = 0;
	virtual void chooseAnimation() = 0;
	virtual void afterFrameEvents() = 0;
	virtual void updateTotalFrames() = 0;
	virtual boolean isAnimationRunning() = 0;
	virtual void incrementFrame() = 0;
	virtual void endAnimation() = 0;
};

#endif // _DRAW_FRAME_SERVICE_H_
