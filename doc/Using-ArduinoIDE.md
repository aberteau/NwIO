# Using Arduino IDE
The programs in this project are edited using PlatformIO.

Here is the procedure if you want to use Arduino IDE.

## How to import code in Arduino IDE
- Create a new sketch
- Copy/Paste content of file [main.cpp](src/main.cpp) to your ino file (You can remove the following line ``#include <Arduino.h>``)
- Copy other files in folder `src` to the same folder as ino file
- Install the necessary libraries listed (See "Build With" section for each program)

## How to enable the `Path variable` support for ESPAsyncWebServer
You have to create/update `platform.local.txt`:

`Windows`: %AppData%\Local\Arduino15\packages\\`{espxxxx}`\hardware\\`espxxxx`\\`{version}`\platform.local.txt

`Linux`: ~/.arduino15/packages/`{espxxxx}`/hardware/`{espxxxx}`/`{version}`/platform.local.txt

Add/Update the following line:
```
  compiler.cpp.extra_flags=-DDASYNCWEBSERVER_REGEX
```
(Source : [https://github.com/me-no-dev/ESPAsyncWebServer#path-variable](https://github.com/me-no-dev/ESPAsyncWebServer#path-variable))
