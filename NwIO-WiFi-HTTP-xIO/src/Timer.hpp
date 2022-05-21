/**
 * NwIO-WiFi-HTTP-xIO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-xIO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <Arduino.h>

class Timer {
public:
  void start(uint16_t duration);
  bool isStarted();
  bool hasElapsed();
  void stop();

private:
  uint16_t _duration;
  unsigned long _startMillis;
};

#endif