/**
 * NwIO-WiFi-HTTP-IxO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-IxO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#ifndef INPUT_STATE_HTTP_SENDER_HPP
#define INPUT_STATE_HTTP_SENDER_HPP

#include <Arduino.h>

class InputStateHttpSender {
public:
  InputStateHttpSender(String hostname, int port, String deviceId);
  void send(uint8_t id, bool state);

private:
  String _baseUrl;
  String _deviceId;
  String getAbsolutePath(String path);
  String getUrl(String path);
  String getPath(uint8_t id, bool state);
  String getUrl(uint8_t id, bool state);
};

#endif