#ifndef _SERIAL_MANAGER_CONTROLLER_H_
#define _SERIAL_MANAGER_CONTROLLER_H_

/*********************
 *      INCLUDES
 *********************/
#include "../../config.h"
#include "../animations/AngryFaceAnimation.h"
#include "../animations/GrumpyFaceAnimation.h"
#include "../animations/SleepFaceAnimation.h"
#include "AnimationsController.h"
#include <ArduinoLog.h>

/*********************
 *      CLASS
 *********************/
class SerialManager
{
public:
	SerialManager();

	void setupDisplay();
	void processSerialCommands();
	void splashScreen();
	void recvWithStartEndMarkers();
	void showNewData();
	void runCommand();
	void processCustomMessage();
	String getValueFromDelimitedString(String stringData, char separator, int index);

private:
	String userInput;
	const static byte numChars = 32;
	char receivedChars[numChars];
	boolean newData = false;
	Animations animations;
};

#endif // _SERIAL_MANAGER_CONTROLLER_H_
