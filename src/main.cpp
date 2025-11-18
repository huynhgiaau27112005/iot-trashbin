#include <Arduino.h>
#include "config.h"
#include "devices/devices.h"
#include "mqtt.h"
#include "business.h"

WiFiClient espClient;

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
  connectMQTT();
}

void loop() {
  mainBusiness();
}