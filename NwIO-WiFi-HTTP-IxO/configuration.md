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

### Device
| Variable   | Description                                                     |
|------------|-----------------------------------------------------------------|
| deviceId   | Device identifier |

## Inputs & Outputs
### Zero-based numbering
| Variable             | Description                                              | Value                       |
|----------------------|----------------------------------------------------------|-----------------------------|
| ZeroBasedIoNumbering | Determines the identifier used for first Input/Output Id | `true` (default) or `false` |

| ZeroBasedIoNumbering | First I/O id |
|----------------------|--------------|
| `true`               | 0            |
| `false`              | 1            |

(See [io-mappings](io-mappings.md))

### Pin assignation
You can change input pins assignation by modifying ``inputConfigs``
(See [io-mappings](io-mappings.md))


