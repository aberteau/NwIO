/**
 * NwIO-WiFi-HTTP (c) by Amael BERTEAU
 * 
 * NwIO-WiFi-HTTP is licensed under a
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * 
 * You should have received a copy of the license along with this
 * work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
 */

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "Output.hpp"
#include "Input.hpp"
#include "InputStateHttpSender.hpp"
#include "IoIdentifierMapper.hpp"
#include "Configuration.hpp"

AsyncWebServer webServer(80);
WiFiClient client;

const uint8_t inputCount = sizeof(inputConfigs) / sizeof(inputConfigs[0]);
Input inputs[inputCount];

InputStateHttpSender inputStateHttpSender(server.toString(), serverPort, deviceId);

const uint8_t outputCount = sizeof(outputConfigs) / sizeof(outputConfigs[0]);
Output outputs[outputCount];

IoIdentifierMapper ioIdentifierMapper(ZeroBasedIoNumbering);

void setupWiFi(){
  // init the WiFi connection
  // Configures static IP address
  if (!WiFi.config(ip, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }

  Serial.print("INFO: Connecting to ");
  Serial.println(WIFI_SSID);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("INFO: WiFi connected");
  Serial.println("INFO: IP address: ");
  Serial.println(WiFi.localIP());
}

void handleInputStateChange(Input &input) {
  uint8_t id = input.getId();
  bool state = input.getState();
  inputStateHttpSender.send(id, state);
}

void setupInputs() {

  for (uint8_t i = 0; i < inputCount; i++) {
    InputConfig config = inputConfigs[i];
    uint8_t id = ioIdentifierMapper.arrayIndexToId(i);
    inputs[i].init(id, config, handleInputStateChange);
  }
}

void setupOutputs() {

  for (uint8_t i = 0; i < outputCount; i++) {
    OutputConfig config = outputConfigs[i];
    outputs[i].init(config);
  }
}

bool getState(String stateStr) {

  if (stateStr == "on") {
    return true;
  }

  return false;
}

void handleOutputRequest(AsyncWebServerRequest *request) {

  String idArg = request->pathArg(0);
  long id = idArg.toInt();
  int8_t i = ioIdentifierMapper.idToArrayIndex(id);

  if ((i < 0) || (i > outputCount - 1)) {
    request->send(400, "text/plain", "input not defined");
    return;
  }

  String stateArg = request->pathArg(1);
  String durationArg = request->pathArg(2);

  if (stateArg == "on" && durationArg != "") {
    long duration = durationArg.toInt();

    if ((duration == 0) || (duration > USHRT_MAX)) {
      String errorMessage = "Duration must be between 1 and " + String(USHRT_MAX);
      request->send(400, "text/plain", errorMessage);
      return;
    }

    outputs[i].on(duration);
  } else {
    bool state = getState(stateArg);
    outputs[i].set(state);
  }

  request->send(200);
}

void handleNotFoundRequest(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void setupWebServer() {
  webServer.on("^\\/output\\/(\\d+)\\/(on|off)(?:\\/(\\d+))?$", HTTP_GET, handleOutputRequest);

  webServer.onNotFound(handleNotFoundRequest);
  
  // start server
  webServer.begin();
}

void inputsLoop() {
  for (uint8_t i = 0; i < inputCount; i++) {
    inputs[i].loop();
  }
}

void outputsLoop() {
  for (uint8_t i = 0; i < outputCount; i++) {
    outputs[i].loop();
  }
}

void setup() {
  Serial.begin(9600);
  setupInputs();
  setupOutputs();

  setupWiFi();
  setupWebServer();

  delay(2000);
  Serial.println("Ready");
}

void loop() {
  inputsLoop();
  outputsLoop();
}