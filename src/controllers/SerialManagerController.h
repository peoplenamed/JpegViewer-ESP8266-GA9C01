#ifndef _SERIAL_MANAGER_CONTROLLER_H_
#define _SERIAL_MANAGER_CONTROLLER_H_

/*********************
 *      INCLUDES
 *********************/
#include "config.h"
#include "AnimationsController.h"
#include <ArduinoLog.h>

/*********************
 *      CLASS
 *********************/
class SerialManager
{
public:
	SerialManager();

	void init(int *_imageSelect);

private:
    // static void process_wrapper(void* arg)
    // {
    //     reinterpret_cast<SerialManager*>(arg)->processSerialCommands();
    // }
	void processSerialCommands(); // Get commands
	
	int *imageSelect;
	// void setupDisplay();
	// void splashScreen();
	static void recvWithStartEndMarkers();
	// static void showNewData();
	void runCommand();
	void processCustomMessage();
	String getValueFromDelimitedString(String stringData, char separator, int index);
	String userInput;
	// boolean newData;
	const static byte numChars = 32;
	char receivedChars[numChars];
	// Animations animations;
	int vTaskDelayTimeout = 250;
};

#endif // _SERIAL_MANAGER_CONTROLLER_H_
