# JpegViewer-ESP8266-gc9a01
This is the original tutorial I used to setup my ESP8266 NodeMCU Amica v1.0
https://thesolaruniverse.wordpress.com/2022/11/01/an-internet-synced-clock-circular-display-with-gc9a01-controller-powered-by-an-esp8266/

The display is driven by the GC9A01 controller. (I swapped them in the original title)

These are the pins I used for the ESP8266
![working pinouts for esp8266/esp32](/PINOUTS.png)

ADD these to Arduino.
Preferences -> Additional Board Managers
`https://dl.espressif.com/dl/package_esp32_index.json`
`http://arduino.esp8266.com/stable/package_esp8266com_index.json`
`https://espressif.github.io/arduino-esp32/package_esp32_index.json`
![alt text](/ADDITIONAL.png)
![esp32 wiring reference](/ref1.webp)
![esp32 pinouts](/ref2.webp)


ESP8266
Install LittleFS uploader

ESP32
Install SPIFFS uploader
https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/

Install zips to ~/Arduino/tools
