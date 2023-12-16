/*********************
 *      INCLUDES
 *********************/
#include "SerialManagerController.h"

/*********************
 *      CLASS
 *********************/
SerialManager::SerialManager()
{
	Log.notice("SerialManager initializer");
}

void SerialManager::init(int *_imageSelect) {
	imageSelect = _imageSelect;

	auto processSerialCommandsTask = [](void* arg) { static_cast<SerialManager*>(arg)->processSerialCommands(); };
	xTaskCreate(processSerialCommandsTask, "processSerialCommands", 1024, this, 2, NULL);
}

// Only accept Serial commands wrapped in <>
void SerialManager::processSerialCommands()
{
	Log.info("We are inside processSerialCommands\n");
	for (;;) {
		static boolean recvInProgress = false;
		static byte ndx = 0;
		char startMarker = '<';
		char endMarker = '>';
		char rc;

		while(Serial.available())
		{
			rc = Serial.read();

			if(recvInProgress == true)
			{
				if(rc != endMarker)
				{
					receivedChars[ndx] = rc;
					ndx++;
					if(ndx >= numChars)
					{
						ndx = numChars - 1;
					}
				}
				else
				{
					receivedChars[ndx] = '\0'; // terminate the string
					recvInProgress = false;
					ndx = 0;
					runCommand();
					// newData = true;
				}
			}

			else if(rc == startMarker)
			{
				recvInProgress = true;
			}

		}
		vTaskDelay( 250 ); 
	}
}

void SerialManager::runCommand()
{
	char firstChar = receivedChars[0];
	if(firstChar == '*')
	{
		processCustomMessage();
	}
	else
	{
		Log.trace("processing: %s\n", receivedChars);
		*imageSelect = atoi(receivedChars);
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

	Log.trace("THIS IS NOT WORKING ATM\n THIS IS NOT WORKING ATM\n  THIS IS NOT WORKING ATM\n   THIS IS NOT WORKING ATM.... \n Normally it would be processing _text: %s, _x: %s, _y: %s, _size: %s, _color: %s, _wipe: %s" CR,
			  _text,
			  _x,
			  _y,
			  _size,
			  _color,
			  _wipe);

	if(_wipe == "1")
	{
		// animations.wipeScreen(true);
	}

	// animations.userDefinedText(_text, _x.toInt(), _y.toInt(), _size.toInt(), _color.toInt());
}

String SerialManager::getValueFromDelimitedString(String stringData, char separator, int index)
{
	int found = 0;
	int strIndex[] = {0, -1};
	int maxIndex = stringData.length() - 1;

	for(int i = 0; i <= maxIndex && found <= index; i++)
	{
		if(stringData.charAt(i) == separator || i == maxIndex)
		{
			found++;
			strIndex[0] = strIndex[1] + 1;
			strIndex[1] = (i == maxIndex) ? i + 1 : i;
		}
	}

	return found > index ? stringData.substring(strIndex[0], strIndex[1]) : "";
}
