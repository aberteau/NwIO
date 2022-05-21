/**
 * NwIO-WiFi-HTTP (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#include "Input.hpp"

void Input::init(uint8_t id, InputConfig config, void (*onStateChange)(Input &input)) {
   _id = id;
   _config = config;
   pinMode(_config.pin, INPUT_PULLUP);
   _onStateChange = onStateChange;

  bool state = readState();
  _previousSteadyState = state;
  _lastSteadyState = state;
  _lastFlickerableState = state;
  _lastDebounceTime = 0;
}

bool Input::toBool(int state) {
  bool bState = !_config.invertLogic ? state == HIGH : state == LOW;
  return bState;
}

bool Input::readState() {
  int state = digitalRead(_config.pin);
  bool bState = toBool(state);
  return bState;
}

uint8_t Input::getId() {
  return _id;
}

bool Input::getState() {
  return _lastSteadyState;
}

void Input::loop() {

	bool currentState = readState();

	unsigned long currentTime = millis();

	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH), and you've waited long enough
	// since the last press to ignore any noise:

	// If the switch/button changed, due to noise or pressing:
	if (currentState != _lastFlickerableState) {
		// reset the debouncing timer
		_lastDebounceTime = currentTime;
		// save the the last flickerable state
		_lastFlickerableState = currentState;
	}

	if ((currentTime - _lastDebounceTime) >= _config.debounceDelay) {
		// whatever the reading is at, it's been there for longer than the debounce
		// delay, so take it as the actual current state:

		// save the the steady state
		_previousSteadyState = _lastSteadyState;
		_lastSteadyState = currentState;

    if (_lastSteadyState != _previousSteadyState) {
      _onStateChange(*this);
    }
	}
}