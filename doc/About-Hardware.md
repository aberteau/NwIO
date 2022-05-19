# About Hardware
## ESP32

The programs in this project work on ESP32 NodeMCU.

(I use "ESP32 NodeMCU Module WLAN WiFi Development Board with CP2102")

![ESP32 NodeMCU](Esp32DevkitC.png)

For more information :
- [AZ Delivery](https://www.az-delivery.de/en/products/esp32-developmentboard)
- [Amazon.fr](https://www.amazon.fr/gp/product/B071P98VTG/)

## MCP23017
Some programs in this project use Waveshare MCP23017 IO Expansion Board.

![Waveshare MCP23017](Waveshare-MCP23017.png)

For more information :
- [Waveshare MCP23017 IO Expansion Board](www.waveshare.com/wiki/MCP23017_IO_Expansion_Board)
- [Amazon.fr](https://www.amazon.fr/Waveshare-MCP23017-IO-Expansion-Board/dp/B07P2H1NZG)

### Connection
| MCP23017 | ESP32      |
|----------|------------|
| INTB     | -          |
| INTA     | -          |
| SCL      | SCL (IO22) |
| SDA      | SDA (IO21) |
| GND      | GND        |
| VCC      | 3.3V       |
