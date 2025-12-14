#include <Arduino.h>
#include "config.h"
#include "devices/devices.h"
#include <NTPClient.h> 
#include <WiFiUdp.h>
#include "mqtt.h"
#include "business.h"
#include <stdlib.h>
using namespace std;
WiFiClient espClient;

// --- CẤU HÌNH NTP  ---
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 25200, 60000);

void connectWiFi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");
}

void setup() {
  Serial.begin(115200);
  Pir::setup();
  ServoMotor::setup();
  Oled::setup();
  Led::setup();
  UltraSensor::setup();
  TempSensor::setup();
  Button::setup();

  connectWiFi();
  timeClient.begin();
  connectMQTT();
}
void loop() {
  if (!mqttClient.connected()) {
    connectMQTT();
  }
  timeClient.update();
  Led::loopCheck(timeClient.getHours(), timeClient.getMinutes());
  mqttClient.loop();
  mainBusiness();
}