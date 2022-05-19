/**
 * NwIO-WiFi-HTTP-xIO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-xIO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#ifndef INPUT_HPP
#define INPUT_HPP

#include <Arduino.h>

struct InputConfig
{
  uint8_t pin;
  bool invertLogic;
  unsigned long debounceDelay;
};

class Input {
public:
  void init(uint8_t id, InputConfig config, void (*onStateChange)(Input &input));
  uint8_t getId();
  bool getState();
  void loop();

private:;
  uint8_t _id;
  InputConfig _config;
  bool _invertLogic;
  void (*_onStateChange)(Input &input);
	bool _previousSteadyState;  // the previous steady state from the input pin, used to detect pressed and released event
  bool _lastSteadyState;      // the last steady state from the input pin
  bool _lastFlickerableState; // the last flickerable state from the input pin
  unsigned long _lastDebounceTime; // the last time the output pin was toggled
  bool toBool(int state);
  bool readState();
};

#endif