
/*********************
 *      INCLUDES
 *********************/
#include "SerialManagerController.h"
#include "../animations/AngryFaceAnimation.h"
#include "../animations/SleepFaceAnimation.h"

/*********************
 *      CLASS
 *********************/
SerialManager::SerialManager()
{
    Serial.print("SerialManager initializer");
}

void SerialManager::setupDisplay()
{
    animations.setupDisplay();
}

void SerialManager::processSerialCommands()
{
    recvWithStartEndMarkers();
    showNewData();
}

// Only accept Serial commands wrapped in <>
void SerialManager::recvWithStartEndMarkers()
{
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false)
    {
        rc = Serial.read();

        if (recvInProgress == true)
        {
            if (rc != endMarker)
            {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars)
                {
                    ndx = numChars - 1;
                }
            }
            else
            {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker)
        {
            recvInProgress = true;
        }
    }
}

void SerialManager::splashScreen()
{
    Serial.println("SerialManager::splashScreen()");
    animations.splashScreen();
}

void SerialManager::showNewData()
{
    if (newData == true)
    {
        runCommand();
        newData = false;
    }
}

void SerialManager::runCommand()
{
    char firstChar = receivedChars[0];
    if (firstChar == '*')
    {
        processCustomMessage();
    }
    else if (firstChar == '-')
    {
        AngryFaceAnimation angryFaceAnimation;
        angryFaceAnimation.renderIn();
        delay(2);
        angryFaceAnimation.renderOut();
        delay(2);
        SleepFaceAnimation sleepFaceAnimation;
        sleepFaceAnimation.renderIn();
    }
    else
    {
        animations.chooseAnimation(atoi(receivedChars));
    }
}

void SerialManager::processCustomMessage()
{
    // Example Messages
    //   <*Howdy friend|0|110|3|3|1>
    //   <*75%|20|140|3|3|0>
    String charsAsString = receivedChars;
    charsAsString.remove(0, 1); // remove asterisk
    String _text = getValueFromDelimitedString(charsAsString, '|', 0);
    String _x = getValueFromDelimitedString(charsAsString, '|', 1);
    String _y = getValueFromDelimitedString(charsAsString, '|', 2);
    String _size = getValueFromDelimitedString(charsAsString, '|', 3);
    String _color = getValueFromDelimitedString(charsAsString, '|', 4);
    String _wipe = getValueFromDelimitedString(charsAsString, '|', 5);
#ifdef DEBUG
    Serial.print("  _text = ");
    Serial.println(_text);
    Serial.print("  _x = ");
    Serial.println(_x);
    Serial.print("  _y = ");
    Serial.println(_y);
    Serial.print("  _size = ");
    Serial.println(_size);
    Serial.print("  _color = ");
    Serial.println(_color);
    Serial.print("  _wipe = ");
    Serial.println(_wipe);
#endif

    if (_wipe == "1")
    {
        animations.wipeScreen(true);
    }

    animations.userDefinedText(_text, _x.toInt(), _y.toInt(), _size.toInt(), _color.toInt());
}

String SerialManager::getValueFromDelimitedString(String stringData, char separator, int index)
{
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = stringData.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++)
    {
        if (stringData.charAt(i) == separator || i == maxIndex)
        {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i + 1 : i;
        }
    }

    return found > index ? stringData.substring(strIndex[0], strIndex[1]) : "";
}
