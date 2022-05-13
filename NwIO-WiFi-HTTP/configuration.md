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

## Inputs & Outputs
By default, this program handles 8 inputs and 10 outputs (See [io-mappings](io-mappings.md)) but you can easily change pins usage by modifying ``inputConfigs`` and ``outputConfigs``.

For example, to use 2 inputs and 16 outputs, use the following mapping :
```
InputConfig inputConfigs[] =
{
  { 32, false, debounceDelay },
  { 33, false, debounceDelay }
};

OutputConfig outputConfigs[] =
{
  { 23, false },
  { 22, false },
  { 21, false },
  { 19, false },
  { 18, false },
  { 5, false },
  { 17, false },
  { 16, false },
  { 4, false },
  { 15, false }
  { 25, false },
  { 26, false },
  { 27, false },
  { 14, false },
  { 12, false },
  { 13, false }
};
```

