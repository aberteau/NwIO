/**
 * NwIO-WiFi-HTTP-IxO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-IxO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#include "Timer.hpp"

void Timer::start(uint16_t duration) {
  _duration = duration;
  _startMillis = millis();
}

void Timer::stop() {
  _duration = 0;
}

bool Timer::isStarted() {
  return _duration != 0;
}

bool Timer::hasElapsed() {
  return millis() - _startMillis >= _duration;
}
