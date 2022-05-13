# NwIO-WiFi-HTTP
[![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

## About The Project
This program allows to use an ESP32 to control 18 Inputs/Outputs over HTTP using WiFi Connection.

### Features
- send the state of an input to an HTTP server
- set the state of an output by HTTP calls

![Overview](NwIO-WiFi-HTTP%20Overview.png)

<!-- GETTING STARTED -->
## Getting Started
### Hardware
ESP32 NodeMCU

I used "ESP32 NodeMCU Module WLAN WiFi Development Board with CP2102"

![ESP32 NodeMCU](Esp32DevkitC.png)

For more information :
- [AZ Delivery](https://www.az-delivery.de/en/products/esp32-developmentboard)
- [Amazon.fr](https://www.amazon.fr/gp/product/B071P98VTG/)

### Software
### If you use PlatformIO
Open this project in PlatformIO

### If you use Arduino IDE
- Copy/Paste content of file [main.cpp](src/main.cpp) to your ino file
- Copy other files in folder `src` to the same folder as ino file
- Install libraries listed in [Build With](#built-with) section
- Edit include directives. remove the following line
``#include <Arduino.h>``
- Enable the `Path variable` support for ESPAsyncWebServer

#### How to enable the `Path variable` support for ESPAsyncWebServer ?
(Instructions copied from [https://github.com/me-no-dev/ESPAsyncWebServer#path-variable](https://github.com/me-no-dev/ESPAsyncWebServer#path-variable))

You have to create/update `platform.local.txt`:

`Windows`: %AppData%\Local\Arduino15\packages\\`{espxxxx}`\hardware\\`espxxxx`\\`{version}`\platform.local.txt

`Linux`: ~/.arduino15/packages/`{espxxxx}`/hardware/`{espxxxx}`/`{version}`/platform.local.txt

Add/Update the following line:
```
  compiler.cpp.extra_flags=-DDASYNCWEBSERVER_REGEX
```

### Configuration
Before uploading program to your ESP32, you must configure settings (IP Address, ...).

[Configuration](configuration.md)

By default, this program handles 8 inputs and 10 outputs but you can easily modify pins usage (For example, 2 inputs and 16 outputs) in configuration.

<!-- USAGE EXAMPLES -->
## Usage
### Send input state to HTTP Server
Each change of state triggers an HTTP request to following URL ``http://{server}:{serverPort}/input/{id}/{state}``

| Parameter | Description | Values                            |
|-----------|-------------|-----------------------------------|
| id        | Input id    | See [io-mappings](io-mappings.md) |
| state     | Input state | 0 or 1                            |

#### Examples
Given the following configuration :
```
IPAddress server(192, 168, 0, 1);
int serverPort = 1234;
```
| When                 | HTTP request is sent on                         |
|----------------------|---------------------------------------|
| Input 0 changes to 0 | ``http://192.168.0.1:1234/input/0/0``   |
| Input 0 changes to 1 | ``http://192.168.0.1:1234/input/0/1``    |

### Set output state with HTTP calls
To set output state, call following URL ``http://{ip}/output/{id}/{state}/{duration}``

| Parameter | Description                                                      | Values                            |
|-----------|------------------------------------------------------------------|-----------------------------------|
| id        | Output id                                                        | See [io-mappings](io-mappings.md) |
| state     | Output state                                                     | off or on                         |
| duration  | Duration (ms) Only available for "on" | 0 to 65535                        |

#### Examples
Given the following configuration :
```
IPAddress ip(192, 168, 0, 11);
```

| Usage                          | URL to call                           |
|--------------------------------|---------------------------------------|
| Enable output 0                | ``http://192.168.0.11/output/0/on``   |
| Disable output 0               | ``http://192.168.0.11/output/0/off``     |
| Enable output 0 during 2000 ms | ``http://192.168.0.11/output/0/on/2000`` |

<!-- ROADMAP -->
## Roadmap

- [ ] Use of 32 I/O (using 2 x MCP23017)
- [ ] Adding identifier to identify emitter of HTTP Request (``http://{server}:{serverPort}/{deviceId}/input/{id}/{state}``)

<!-- LICENSE -->
## License
This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

See [LICENSE](../LICENSE) for more information.

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

## Built With
- me-no-dev/AsyncTCP [Repository](https://github.com/me-no-dev/AsyncTCP)
- me-no-dev/ESPAsyncWebServer [Repository](https://github.com/me-no-dev/ESPAsyncWebServer)

## Authors
* **Amael BERTEAU**

<!-- CONTACT -->
## Contact
- [Project page (Personal Website)](https://amaelberteau.com/projects/nwio) (French)
- [Facebook Page "Le Lab d'Amael"](https://www.facebook.com/amael.lab) (French)

<!-- MARKDOWN LINKS & IMAGES -->
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/amael-berteau
[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
