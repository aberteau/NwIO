# Configuration

All settings are defined in [Configuration.hpp](src/Configuration.hpp)

## General
### WiFi
|Variable| Description |
|------|-------------|
|WIFI_SSID| Identifier  |
|WIFI_PASSWORD| Password    |

### Network settings
|Variable| Description      |
|------|------------------|
|ip| ESP32 IP Address |
|gateway| Gateway          |
|subnet| Subnet           |

### HTTP Server
|Variable| Description            |
|------|------------------------|
|server| HTTP Server IP Address |
|serverPort| HTTP Server Port       |

### General
| Variable   | Description                                                     |
|------------|-----------------------------------------------------------------|
| deviceId   | Device identifier |

## Inputs & Outputs
This program handles :
- 16 inputs (ESP32 GPIO)
- 16 outputs (Waveshare MCP23017 GPIO)

You can change input pins assignation by modifying ``inputConfigs``
(See [io-mappings](io-mappings.md))
