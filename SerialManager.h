#include "Animations.h"
//#define DEBUG

#ifndef _SerialManager_H_
  #define _SerialManager_H_
  
  //#define DEBUG
  
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

#endif // _SerialManager_H_
