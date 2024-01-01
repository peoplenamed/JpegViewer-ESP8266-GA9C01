#include "FrameSmasherService.h"

FrameSmasherService::FrameSmasherService() {
    // Constructor definition
    // Initialize your class members here
}




// 1. Draw each line one-by-one.
// 2. Compare every frame to determine which pixel to draw.
//   a. If there is no overlap, draw the pixel.
//   b. If there is overlap of currentFrames pixels, draw the pixel from the currentFrame with the lowest precedence.
//   c. If there is overlap of previousFrames pixels, draw the pixel from the previousFrame with the lowest precedence.
//   d. Always choose currentFrame pixel over previousFrame pixel.
// y = height
// x = width
void FrameSmasherService::smashFrames(std::vector<FrameObject> frameObjects) {
    // Clear the pyxels
    // std::fill_n(pyxels, _SCREEN_WIDTH, 0);

    Log.info("[FrameSmasherService]<smashFrames>  \n");
    
    int currentY = findLowestYValue(frameObjects);
    
    while (currentY <= _SCREEN_HEIGHT) {
        Log.info("[FrameSmasherService]<smashFrames>  currentY: %i \n", currentY);
        smashY(currentY, frameObjects);
        currentY++;
    }



    // for (int i=0; i < frameObjects.size(); i++) {
    //     if (frameObjects[i].previousFrames.size() > 1) {
    //     }
    //     if (frameObjects[i].currentFrames.size() > 1) {
    //     }
    // }
}

void FrameSmasherService::smashY(int currentY, std::vector<FrameObject> frameObjects) {
    // 1. Find all current frames with x in range of currentY
    // 2. Find all previous frames with x == currentY
    // 3. Choose the first x on the currentFrames stack (if there is one)
    // 4. Choose the first x on the previousFrames stack (if there is one) & currentFrames did not previously set it.
    // 5. Draw the pixels.

    for (int frameObjectsIterator=0; frameObjectsIterator < frameObjects.size(); frameObjectsIterator++) {
        for (int currentFramesIterator=0; currentFramesIterator < frameObjects[frameObjectsIterator].currentFrames.size(); currentFramesIterator++) {
            setFramePyxels(currentY, frameObjects[frameObjectsIterator].currentFrames[currentFramesIterator], false);
        }
    }


    for (int frameObjectsIterator=0; frameObjectsIterator < frameObjects.size(); frameObjectsIterator++) {
        for (int previousFramesIterator=0; previousFramesIterator < frameObjects[frameObjectsIterator].previousFrames.size(); previousFramesIterator++) {
            setFramePyxels(currentY, frameObjects[frameObjectsIterator].previousFrames[previousFramesIterator], true);
        }
    }
    // Log.info("[FrameSmasherService]<smashY>  pyxels[]: %d \n", pyxels);

    // for (int i=0; i < _SCREEN_WIDTH; i++) {

    //     if (pyxels[i] != 0) {
    //         Log.info("[FrameSmasherService]<smashY>  pyxels[%i]: %i \n", i, pyxels[i]);
    //         gfx->drawPixel(i, currentY, pyxels[i]);
    //     }
    // }
}

void FrameSmasherService::setFramePyxels(int currentY, FrameInfo frameInfo, bool useBackgroundColor) {
    // if (currentY >= frameInfo.y && currentY <= frameInfo.h) {
        // currentY is between frameInfo.y and frameInfo.h
        if (currentY < 0 || currentY > _SCREEN_HEIGHT) {
            return;
        }
        int currentIndex = (currentY - frameInfo.y);
        // int maxX = frameInfo.w + currentY;
        int maxX = currentIndex + frameInfo.w;
        Log.info("[FrameSmasherService]<setFramePyxels>  currentIndex:%i, currentY:%i, frameInfo.y:%i, frameInfo.w:%i, maxX:%i \n", currentIndex, currentY, frameInfo.y, frameInfo.w, maxX);



        int16_t byteWidth = (frameInfo.w + 7) / 8; // Bitmap scanline pad = whole byte
        uint8_t byte = 0;

        for (int16_t i = 0; i < frameInfo.w; i++)
        {
            if (i & 7)
            {
                byte <<= 1;
            }
            else
            {
                byte = pgm_read_byte(&frameInfo.bitmap[currentIndex * byteWidth + i / 8]);
            }
            if (byte & 0x80) {
                // if (!pyxels[currentIndex + i]) {
                    // pyxels[currentIndex + i] = useBackgroundColor ? frameInfo.backgroundColor : frameInfo.color;
                    gfx->drawPixel(frameInfo.x + i, currentY, useBackgroundColor ? frameInfo.backgroundColor : frameInfo.color);
                // }
            }
        }


}


int FrameSmasherService::findLowestYValue(std::vector<FrameObject> frameObjects) {
    int lowestYValue = _SCREEN_HEIGHT;
    Log.info("[FrameSmasherService]<findLowestYValue>  frameObjects.size(): %i \n", frameObjects.size());
    for (int i=0; i < frameObjects.size(); i++) {
        for (int j=0; j < frameObjects[i].currentFrames.size(); j++) {
            Log.info("[FrameSmasherService]<findLowestYValue>  frameObjects[%i].currentFrames[%i].y: %i < %i \n", i, j, frameObjects[i].currentFrames[j].y, lowestYValue);
            if (frameObjects[i].currentFrames[j].y < lowestYValue) {
                lowestYValue = frameObjects[i].currentFrames[j].y;
            }
        }
        for (int j=0; j < frameObjects[i].previousFrames.size(); j++) {
            if (frameObjects[i].previousFrames[j].y < lowestYValue) {
                lowestYValue = frameObjects[i].previousFrames[j].y;
            }
        }
    }
    Log.info("[FrameSmasherService]<findLowestYValue>  lowestYValue: %i \n", lowestYValue);
    return lowestYValue;
}
