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
  internalSet(false);
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
  _cmd = OutputCommand::setState;
  _cmdState = state;
}

void Output::on(uint16_t duration) {
  _cmd = OutputCommand::timer;
  _cmdDuration = duration;
}

void Output::handleCommand() {

  switch (_cmd)
  {
    case OutputCommand::none :
      return;

    case OutputCommand::setState :
      _timer.stop();
      internalSet(_cmdState);
      break;
  
    case OutputCommand::timer :
      internalSet(true);
      _timer.start(_cmdDuration);
      break;
  }

  _cmd = OutputCommand::none;
}

void Output::loop() {
  handleCommand();
  
  if (_timer.isStarted()) {
    if (_timer.hasElapsed()) {
      internalSet(false);
      _timer.stop();
    }
  }
}