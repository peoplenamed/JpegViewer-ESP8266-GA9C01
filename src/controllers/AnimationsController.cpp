#include "AnimationsController.h"

Animations::Animations()
{
    Log.info("Animations initializer" CR);
}

void Animations::setupDisplay()
{
    display.setupDisplay();
}

void Animations::chooseAnimation(int imageSelect)
{
    Log.trace("Switch imageSelect: %d" CR, imageSelect);
    switch (imageSelect)
    {
    case 0:
        popEye();
        break;
    case 1:
        fangs();
        break;
    case 2:
        grumpyFace();
        break;
    case 3:
        winkFace();
        break;
    case 4:
        disappointedFace();
        break;
    case 5:
        satisfiedFace();
        break;
    case 6:
        normalFace();
        break;
    case 7:
        diamondEyes();
        break;
    case 11:
    {
        Log.trace("AngryFaceAnimation" CR);
        AngryFaceAnimation angryFaceAnimation;
        angryFaceAnimation.renderIn();
        delay(600);
        angryFaceAnimation.renderOut();
        current_animation = 12;
        break;
    }
    case 12:
    {
        Log.trace("SleepFaceAnimation" CR);
        SleepFaceAnimation sleepFaceAnimation;
        sleepFaceAnimation.renderIn();
        delay(2000);
        sleepFaceAnimation.renderLoop();
        delay(2000);
        sleepFaceAnimation.renderOut();
        delay(2000);
        break;
    }
    case 13:
    {
        Log.trace("GrumpyFaceAnimation" CR);
        GrumpyFaceAnimation grumpyFaceAnimation;
        grumpyFaceAnimation.renderIn();
        delay(2000);
        grumpyFaceAnimation.renderLoop();
        delay(2000);
        grumpyFaceAnimation.renderOut();
        break;
    }
    case 14:
    {
        Log.trace("WinkFaceAnimation" CR);
        WinkFaceAnimation winkFaceAnimation;
        winkFaceAnimation.renderIn();
        delay(2000);
        winkFaceAnimation.renderOut();
        break;
    }
    case 15:
    {
        Log.trace("SatisfiedFaceAnimation" CR);
        SatisfiedFaceAnimation satisfiedFaceAnimation;
        satisfiedFaceAnimation.renderIn();
        delay(2000);
        satisfiedFaceAnimation.renderOut();
        break;
    }
    case 16:
    {
        Log.trace("PopEyeFaceAnimation" CR);
        PopEyeFaceAnimation popEyeFaceAnimation;
        popEyeFaceAnimation.renderIn();
        delay(2000);
        popEyeFaceAnimation.renderLoop();
        delay(2000);
        popEyeFaceAnimation.renderOut();
        break;
    }
    case 17:
    {
        Log.trace("FangFaceAnimation" CR);
        FangFaceAnimation fangFaceAnimation;
        fangFaceAnimation.renderIn();
        delay(2000);
        fangFaceAnimation.renderLoop();
        delay(2000);
        fangFaceAnimation.renderOut();
        break;
    }
    case 20:
        circleWipe(10, false);
        break;
    case 21:
        circleWipe(10, true);
        break;
    case 22:
        triangleWipe(false);
        break;
    case 23:
        triangleWipe(true);
        break;
    case 30:
        drawRimCircle(120, false, 10);
        break;
    case 31:
        this->northText("North");
        this->southText("South");
        this->eastText("East");
        this->westText("West");
        this->centerText("100%");
        break;
    case 50:
        octocat();
        break;
    case 51:
        calvinAndHobbes();
        break;
    default:
        calvinDuplicator();
        break;
    }
}

/** STATIC IMAGES **/
void Animations::calvinAndHobbes() { display.drawImage("/download.jpeg"); }
void Animations::octocat() { display.drawImage("/octocat.jpg"); }

/** ANIMATIONS **/
void Animations::calvinDuplicator() { display.drawJpgAnimation("1Ys_", ".jpg", 19, 3); }

/** FACES **/
void Animations::grumpyFace()
{
    Log.info("Animations::grumpyFace()" CR);

    normalFace();
    display.drawJpgAnimation("/grumpy_face_0", ".jpg", 4, 5);
    normalFace();
}
void Animations::winkFace() { display.drawJpgAnimation("/wink_face_", ".jpg", 5, 1); }
void Animations::disappointedFace()
{
    normalFace();
    delay(600);
    display.drawJpgAnimation("/disappointed_face_", ".jpg", 5, 1);
    delay(600);
    normalFace();
}
void Animations::normalFace() { display.drawImage("/normal_face.jpg"); }
void Animations::satisfiedFace()
{
    normalFace();
    delay(400);
    display.drawImage("/satisfied_face.jpg");
    delay(400);
    normalFace();
}

void Animations::popEye()
{
    normalFace();
    delay(100);
    display.drawImage("/PopEye_0001.jpg");
    delay(100);
    display.drawImage("/PopEye_0002.jpg");
    delay(100);
    display.drawImage("/PopEye_0001.jpg");
    delay(100);
    normalFace();
}

void Animations::fangs()
{
    normalFace();
    delay(400);
    display.drawImage("/fangs_0001.jpg");
    delay(600);
    display.drawImage("/fangs_0002.jpg");
    delay(1500);
    display.drawImage("/fangs_0001.jpg");
    delay(300);
    display.drawImage("/fangs_0001.jpg");
    delay(200);
    normalFace();
}

void Animations::diamondEyes()
{
    normalFace();
    delay(400);
    display.drawImage("/diamondEyes_0001.jpg");
    delay(200);
    display.drawImage("/diamondEyes_0002.jpg");
    delay(200);
    display.drawImage("/diamondEyes_0003.jpg");
    delay(200);
    display.drawImage("/diamondEyes_0002.jpg");
    delay(200);
    display.drawImage("/diamondEyes_0001.jpg");
    delay(200);
    display.drawImage("/diamondEyes_0003.jpg");
    delay(200);
    display.drawImage("/diamondEyes_0002.jpg");
    delay(200);
    display.drawImage("/diamondEyes_0003.jpg");
    delay(200);
    display.drawImage("/diamondEyes_0001.jpg");
    delay(200);
    normalFace();
}

void Animations::splashScreen()
{
    Log.info("Animations::splashScreen()" CR);
    grumpyFace();
    delay(500);
    satisfiedFace();
}

void Animations::northText(String _text)
{
    display.drawText(_text, 85, 10, 3, compassTextColor);
}

void Animations::southText(String _text)
{
    display.drawText(_text, 85, 200, 3, compassTextColor);
}

void Animations::eastText(String _text)
{
    display.drawText(_text, 0, 110, 3, compassTextColor);
}

void Animations::westText(String _text)
{
    display.drawText(_text, 185, 110, 3, compassTextColor);
}

void Animations::centerText(String _text)
{
    display.drawText(_text, 85, 110, 3, compassTextColor);
}

void Animations::errorText(String _text)
{
    display.drawText(_text, 0, 105, 4, 3);
}

void Animations::successText(String _text)
{
    display.drawText(_text, 0, 105, 5, 4);
}

void Animations::userDefinedText(String _text, int _x, int _y, int _size, int _color)
{
    display.drawText(_text, _x, _y, _size, _color);
}

void Animations::wipeScreen(boolean wipe)
{
    display.wipeScreen(wipe);
}

void Animations::drawRimCircle(int32_t radius, boolean wipe, int maxWipe)
{
    display.wipeScreen(wipe);

    int32_t _x = 120; // radius/2
    int32_t _y = 120; // radius/2

    for (int y = 0; y < maxWipe; y++)
    {
        display.DrawCircle(_x, _y, radius - y, hexColors.getRandomColor());
    }
}

void Animations::circleWipe(int radius, boolean wipe)
{
    display.wipeScreen(wipe);
    int32_t w = _width;
    int32_t h = _height;
    // uint32_t start;
    int32_t x, y;
    int32_t r2 = radius * 2;
    int32_t w1 = w + radius;
    int32_t h1 = h + radius;

    for (x = 0; x < w1; x += r2)
    {
        for (y = 0; y < h1; y += r2)
        {
            display.DrawCircle(x, y, radius, hexColors.getRandomColor());
        }
    }
}

void Animations::triangleWipe(boolean wipe)
{
    display.wipeScreen(wipe);
    int32_t i;
    int32_t cx = _width / 2;
    int32_t cy = _height / 2;
    int32_t cx1 = cx - 1;
    int32_t cy1 = cy - 1;
    int32_t cn = min(cx1, cy1);
    // digit size

    for (i = 0; i < cn; i += 5)
    {
        display.DrawTriangle(
            cx1, cy1 - i,     // peak
            cx1 - i, cy1 + i, // bottom left
            cx1 + i, cy1 + i, // bottom right
            hexColors.getRandomColor());
    }
}
