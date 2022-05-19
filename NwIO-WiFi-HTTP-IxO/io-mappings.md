# I/O Mapping
I/O identifiers used in HTTP Request (`{id}`) depend on :
- value of `ZeroBasedIoNumbering`
- declaration order in `inputConfigs` and `outputConfigs`

## Default configuration
(See [Configuration.hpp](src/Configuration.hpp))

### Inputs
(ESP32 GPIO)

| id  | GPIO  |
|-----|-------|
| 0   | 32    |
| 1   | 33    |
| 2   | 25    |
| 3   | 26    |
| 4   | 27    |
| 5   | 14    |
| 6   | 12    |
| 7   | 13    |
| 8   | 23    |
| 9   | 19    |
| 10  | 18    |
| 11  | 5     |
| 12  | 17    |
| 13  | 16    |
| 14  | 4     |
| 15  | 15    |

### Outputs
Waveshare MCP23017 (I2C Address : `0x27`)

| id  | GPIO |
|-----|------|
| 0   | PA0  |
| 1   | PA1  |
| 2   | PA2  |
| 3   | PA3  |
| 4   | PA4  |
| 5   | PA5  |
| 6   | PA6  |
| 7   | PA7  |
| 8   | PB0  |
| 9   | PB1  |
| 10  | PB2  |
| 11  | PB3  |
| 12  | PB4  |
| 13  | PB5  |
| 14  | PB6  |
| 15  | PB7  |

## When `ZeroBasedIoNumbering = false`
### Inputs

| id  | GPIO  |
|-----|-------|
| 1   | 32    |
| 2   | 33    |
| 3   | 25    |
| 4   | 26    |
| 5   | 27    |
| 6   | 14    |
| 7   | 12    |
| 8   | 13    |
| 9   | 23    |
| 10  | 19    |
| 11  | 18    |
| 12  | 5     |
| 13  | 17    |
| 14  | 16    |
| 15  | 4     |
| 16  | 15    |

### Outputs

| id  | GPIO |
|-----|------|
| 1   | PA0  |
| 2   | PA1  |
| 3   | PA2  |
| 4   | PA3  |
| 5   | PA4  |
| 6   | PA5  |
| 7   | PA6  |
| 8   | PA7  |
| 9   | PB0  |
| 10  | PB1  |
| 11  | PB2  |
| 12  | PB3  |
| 13  | PB4  |
| 14  | PB5  |
| 15  | PB6  |
| 16  | PB7  |
