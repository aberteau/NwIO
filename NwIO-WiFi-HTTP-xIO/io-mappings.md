# I/O Mapping
I/O identifiers used in HTTP Request (`{id}`) depend on :
- value of `ZeroBasedIoNumbering`
- declaration order in `inputConfigs` and `outputConfigs`

## Default configuration
(See [Configuration.hpp](src/Configuration.hpp))

### Inputs
Waveshare MCP23017 (I2C Address : `0x26`)

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
