/**
 * NwIO-WiFi-HTTP-xIO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-xIO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <Arduino.h>
#include <Adafruit_MCP23X17.h>
#include "Timer.hpp"

struct OutputConfig
{
  uint8_t pin;
  bool invertLogic;
};

enum class OutputCommand {
  none,
  setState,
  timer
};

class Output {
public:
  void init(Adafruit_MCP23X17 &mcp, OutputConfig config);
  void set(bool state);
  void on(uint16_t duration);
  void loop();

private:
  Adafruit_MCP23X17 *_mcp;
  OutputConfig _config;
  Timer _timer;
  OutputCommand _cmd;
  bool _cmdState;
  uint16_t _cmdDuration;
  uint8_t getVal(bool state);
  void internalSet(bool state);
  void handleCommand();
};

#endif