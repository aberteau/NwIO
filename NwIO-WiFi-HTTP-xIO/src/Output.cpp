/**
 * NwIO-WiFi-HTTP-xIO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-xIO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#include "Output.hpp"

void Output::init(Adafruit_MCP23X17 &mcp, OutputConfig config) {
  _mcp = &mcp;
  _config = config;
  _mcp->pinMode(_config.pin, OUTPUT);
  set(false);
}

uint8_t Output::getVal(bool state) {
  bool nState = !_config.invertLogic ? state : !state;
  return nState ? HIGH : LOW;
}

void Output::internalSet(bool state) {
  uint8_t val = getVal(state);
  _mcp->digitalWrite(_config.pin, val);
}

void Output::set(bool state) {
  _onDuration = 0;
  _startOnNextLoop = false;
  internalSet(state);
}

void Output::on(unsigned short duration) {
  _onDuration = duration;
  _startOnNextLoop = true;
}

void Output::loop() {
  if (_startOnNextLoop) {
    internalSet(true);
    _onStart = millis();
    _startOnNextLoop = false;
  }

  if (!_startOnNextLoop && (_onDuration > 0)) {
    if (millis() - _onStart >= _onDuration) {
      set(false);
    }
  }
}