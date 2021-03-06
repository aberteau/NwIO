# NwIO
[![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]
[![LinkedIn][linkedin-shield]][linkedin-url]

NwIO = Networked Inputs/Ouputs

This repository contains programs that allow digital I/O interactions through IP network. (HTTP, MQTT)

<!-- PROJECTS -->
## Projects
| Project                                  | Number of IO | Network | Communication |
|------------------------------------------|--------------|-------------------|---------------|
| [NwIO-WiFi-HTTP](NwIO-WiFi-HTTP)         | 18           | WiFi              | HTTP          |
| [NwIO-WiFi-HTTP-IxO](NwIO-WiFi-HTTP-IxO) | 32           | WiFi              | HTTP          |
| [NwIO-WiFi-HTTP-xIO](NwIO-WiFi-HTTP-xIO) | 32           | WiFi              | HTTP          |

### NwIO-WiFi-HTTP
This program allows to use an ESP32 to control 18 Inputs/Outputs over HTTP using WiFi Connection.

By default, it handles 8 inputs and 10 outputs but you can easily modify pins usage in configuration (For example, 2 inputs and 16 outputs).

![NwIO-WiFi-HTTP Overview](NwIO-WiFi-HTTP/Overview.png)

[More information](NwIO-WiFi-HTTP)

### NwIO-WiFi-HTTP-IxO
This program allows to use an ESP32 to control 32 Inputs/Outputs over HTTP using WiFi Connection.

- 16 inputs (ESP32 GPIO)
- 16 outputs (MCP23017 GPIO)

![NwIO-WiFi-HTTP-IxO Overview](NwIO-WiFi-HTTP-IxO/Overview.png)

[More information](NwIO-WiFi-HTTP-IxO)

### NwIO-WiFi-HTTP-xIO
This program allows to use an ESP32 to control 32 Inputs/Outputs over HTTP using WiFi Connection.

- 16 inputs (MCP23017 GPIO)
- 16 outputs (MCP23017 GPIO)

![NwIO-WiFi-HTTP-xIO Overview](NwIO-WiFi-HTTP-xIO/Overview.png)

[More information](NwIO-WiFi-HTTP-xIO)

<!-- USAGE -->
## Usage
- [Interactions with Houdini MC](doc/Houdini-MC)

<!-- ROADMAP -->
## Roadmap

- [ ] Adding MQTT communication

<!-- LICENSE -->
## License
This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

See [LICENSE](LICENSE) for more information.

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

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

