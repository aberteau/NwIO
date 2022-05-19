/**
 * NwIO-WiFi-HTTP-IxO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-IxO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#include "IoIdentifierMapper.hpp"
#include <Arduino.h>

IoIdentifierMapper::IoIdentifierMapper(bool zeroBasedNumbering) {
  _zeroBasedNumbering = zeroBasedNumbering;
}

uint8_t IoIdentifierMapper::arrayIndexToId(uint8_t i) {
  return _zeroBasedNumbering ? i : i + 1;
}

int8_t IoIdentifierMapper::idToArrayIndex(uint8_t id) {
  return _zeroBasedNumbering ? id : id - 1;
}