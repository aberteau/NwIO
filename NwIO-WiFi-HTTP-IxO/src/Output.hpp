/**
 * NwIO-WiFi-HTTP-IxO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-IxO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <Arduino.h>
#include <Adafruit_MCP23X17.h>

struct OutputConfig
{
  uint8_t pin;
  bool invertLogic;
};

class Output {
public:
  void init(Adafruit_MCP23X17 &mcp, OutputConfig config);
  void set(bool state);
  void on(unsigned short duration);
  void loop();

private:
  Adafruit_MCP23X17 *_mcp;
  OutputConfig _config;
  unsigned short _onDuration;
  unsigned long _onStart;
  bool _startOnNextLoop;
  uint8_t getVal(bool state);
  void internalSet(bool state);
};

#endif