/**
 * NwIO-WiFi-HTTP-IxO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-IxO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#ifndef IO_IDENTIFIER_MAPPER_HPP
#define IO_IDENTIFIER_MAPPER_HPP

#include <Arduino.h>

class IoIdentifierMapper {
public:
  IoIdentifierMapper(bool zeroBasedNumbering);
  uint8_t arrayIndexToId(uint8_t i);
  int8_t idToArrayIndex(uint8_t id);
private:
  bool _zeroBasedNumbering;
};

#endif