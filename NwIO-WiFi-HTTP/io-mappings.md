# I/O Mapping
I/O identifiers used in HTTP Request (`{id}`) depend on :
- value of `ZeroBasedIoNumbering`
- declaration order in `inputConfigs` and `outputConfigs`

## Default configuration
(See [Configuration.hpp](src/Configuration.hpp))

### Inputs

| id  | GPIO |
|-----|------|
| 0   | 32   |
| 1   | 33   |
| 2   | 25   |
| 3   | 26   |
| 4   | 27   |
| 5   | 14   |
| 6   | 12   |
| 7   | 13   |

### Outputs

| id  | GPIO |
|-----|------|
| 0   | 23   |
| 1   | 22   |
| 2   | 21   |
| 3   | 19   |
| 4   | 18   |
| 5   | 5    |
| 6   | 17   |
| 7   | 16   |
| 8   | 4    |
| 9   | 15   |

## When `ZeroBasedIoNumbering = false`
### Inputs

| id  | GPIO |
|-----|------|
| 1   | 32   |
| 2   | 33   |
| 3   | 25   |
| 4   | 26   |
| 5   | 27   |
| 6   | 14   |
| 7   | 12   |
| 8   | 13   |

### Outputs

| id  | GPIO |
|-----|------|
| 1   | 23   |
| 2   | 22   |
| 3   | 21   |
| 4   | 19   |
| 5   | 18   |
| 6   | 5    |
| 7   | 17   |
| 8   | 16   |
| 9   | 4    |
| 10  | 15   |
