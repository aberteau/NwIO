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
  { 13, false, debounceDelay }
};

// Outputs
/*
  Format : { <pin>, <invertLogic> }
    <pin> : GPIO Pin Number
    <invertLogic> : Invert Logic
*/
OutputConfig outputConfigs[] =
{
  { 23, false },
  { 22, false },
  { 21, false },
  { 19, false },
  { 18, false },
  { 5, false },
  { 17, false },
  { 16, false },
  { 4, false },
  { 15, false }
};