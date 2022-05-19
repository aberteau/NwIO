/**
 * NwIO-WiFi-HTTP-xIO (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP-xIO is licensed under a
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

// Device
String deviceId = "";

// Inputs & Outputs
const bool ZeroBasedIoNumbering = true;

const unsigned long debounceDelay = 25;

/*
  Format : { <pin>, <invertLogic>, <debounceDelay> }
    <pin> : GPIO Pin Number
    <invertLogic> : Invert Logic
    <debounceDelay> : Debounce delay
*/
InputConfig inputConfigs[] =
{
  { 0, false, debounceDelay },
  { 1, false, debounceDelay },
  { 2, false, debounceDelay },
  { 3, false, debounceDelay },
  { 4, false, debounceDelay },
  { 5, false, debounceDelay },
  { 6, false, debounceDelay },
  { 7, false, debounceDelay },
  { 8, false, debounceDelay },
  { 9, false, debounceDelay },
  { 10, false, debounceDelay },
  { 11, false, debounceDelay },
  { 12, false, debounceDelay },
  { 13, false, debounceDelay },
  { 14, false, debounceDelay },
  { 15, false, debounceDelay }
};

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