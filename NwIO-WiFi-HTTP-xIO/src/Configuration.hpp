/**
 * NwIO-WiFi-HTTP-IxO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-IxO is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#include <Arduino.h>
#include "Input.hpp"
#include "Output.hpp"

// WiFi
const char* WIFI_SSID = "REPLACE_WITH_YOUR_SSID";
const char* WIFI_PASSWORD = "REPLACE_WITH_YOUR_PASSWORD";

// Network settings
IPAddress ip(192, 168, 0, 11);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

// HTTP Server
IPAddress server(192, 168, 0, 39);
int serverPort = 14999;

// DeviceId
String deviceId = "";

// Inputs
const unsigned long debounceDelay = 25;

/*
  Format : { <pin>, <invertLogic>, <debounceDelay> }
    <pin> : GPIO Pin Number
    <invertLogic> : Invert Logic
    <debounceDelay> : Debounce delay
*/
InputConfig inputConfigs[] =
{
  { 32, false, debounceDelay },
  { 33, false, debounceDelay },
  { 25, false, debounceDelay },
  { 26, false, debounceDelay },
  { 27, false, debounceDelay },
  { 14, false, debounceDelay },
  { 12, false, debounceDelay },
  { 13, false, debounceDelay },
  { 23, false, debounceDelay },
  { 19, false, debounceDelay },
  { 18, false, debounceDelay },
  { 5, false, debounceDelay },
  { 17, false, debounceDelay },
  { 16, false, debounceDelay },
  { 4, false, debounceDelay },
  { 15, false, debounceDelay }
};

// Outputs
/*
  Format : { <pin>, <invertLogic> }
    <pin> : GPIO Pin Number
    <invertLogic> : Invert Logic
*/
OutputConfig outputConfigs[] =
{
  { 0, false },
  { 1, false },
  { 2, false },
  { 3, false },
  { 4, false },
  { 5, false },
  { 6, false },
  { 7, false },
  { 8, false },
  { 9, false },
  { 10, false },
  { 11, false },
  { 12, false },
  { 13, false },
  { 14, false },
  { 15, false }
};