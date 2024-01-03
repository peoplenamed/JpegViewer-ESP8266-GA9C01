#ifndef _FRAME_SMASHER_SERVICE_H_
#define _FRAME_SMASHER_SERVICE_H_

#include "config.h"

class FrameSmasherService
{
    public:
        FrameSmasherService();
        void smashFrames(std::vector<FrameObject> frameObjects);
        uint16_t pyxels[_SCREEN_WIDTH];

    private:
        int findLowestYValue(std::vector<FrameObject> frameObjects);
        void setFramePyxels(int currentY, FrameInfo frameInfo, bool useBackgroundColor);
        void smashY(int currentY, std::vector<FrameObject> frameObjects);
};

#endif // _FRAME_SMASHER_SERVICE_H_
