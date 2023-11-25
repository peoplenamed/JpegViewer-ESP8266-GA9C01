# JpegViewer-ESP8266-gc9a01
*Setup*
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

*Running commands over Serial*
Commands must be wrapped in <brackets>
EXAMPLES:
*Dynamic text*
`<Howdy friend|0|110|3|3|1>` Print 'Howdy friend' on screen at x:0,y:110,size:3,color:3:wipe screen:1(true)
`<75%|20|140|3|3|0>`  Print '75%' on screen at x:20,y:140,size:3,color:3:wipe screen:0(false)
*Static routines*
`<0>` octocat
`<1>` calvinAndHobbes
`<2>` grumpyFace
`<3>` winkFace
`<4>` disappointedFace
`<5>` satisfiedFace
`<6>` normalFace
`<7>`
`<8>`
`<9>`
`<10>`
`<11>`
`<12>`
`<13>`
`<14>`
`<15>`
`<16>`
`<17>`
`<18>`
`<19>`
`<20>` circleWipe no screen wipe
`<21>` circleWipe yes screen wipe
`<22>` triangleWipe no screen wipe
`<23>` triangleWipe yes screen wipe
`<24>`
`<25>`
`<26>`
`<27>`
`<28>`
`<29>`
`<30>` drawRimCircle
`<31>` Draw text by regions N,S,E,W, center
`<32>`
`<33>`
`<34>`
`<35>`
`<36>`
`<37>`
`<38>`
`<39>`
`<40>`
`<41>`
`<42>`
`<43>`
`<44>`
`<45>`
`<46>`
`<47>`
`<48>`
`<49>`
`<50>`
`<51>`
`<52>`
`<53>`
`<54>`
`<55>`
`<56>`
`<57>`
`<58>`
`<59>`
`<60>`
`<61>`
`<62>`
`<63>`
`<64>`
`<65>`
`<66>`
`<67>`
`<68>`
`<69>`
`default` calvinDuplicator
