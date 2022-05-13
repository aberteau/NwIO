/**
 * NwIO-WiFi-HTTP (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#include "InputStateHttpSender.hpp"
#include <HTTPClient.h>

InputStateHttpSender::InputStateHttpSender(String hostname, int port) {
    _baseUrl = "http://" + hostname + ":" + port;
}

InputStateHttpSender::InputStateHttpSender(String hostname)
  : InputStateHttpSender(hostname, 80) {
}

String InputStateHttpSender::getAbsolutePath(String path) {
  if (path.indexOf("/") == 0) {
    return path;
  }

  return "/" + path;
}

String InputStateHttpSender::getUrl(String path) {
  String absolutePath = getAbsolutePath(path);
  String url = _baseUrl + absolutePath;
  return url;
}

String InputStateHttpSender::getPath(uint8_t id, bool state) {
  String path = "input/" + String(id) + "/" +  String(state);
  return path;
}

String InputStateHttpSender::getUrl(uint8_t id, bool state) {
  String statePath = getPath(id, state);
  String url = getUrl(statePath);
  return url;
}

void InputStateHttpSender::send(uint8_t id, bool state) {
  String url = getUrl(id, state);

  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();
  
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}
