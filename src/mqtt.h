#ifndef _MQTT_H_
#define _MQTT_H_

#include <Arduino.h>
#include <PubSubClient.h>
#include "config.h"
#include "business.h"

const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;
const char* MQTT_CLIENT_ID = "esp32_client_01";
const char* TOPIC_PUBLISH = "044153414/smartbin/device";
const char* TOPIC_SUBSCRIBE = "044153414/smartbin/web";

PubSubClient mqttClient(espClient);

// --- Hàm MQTT callback khi nhận dữ liệu ---
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String msg = "";
  for (int i = 0; i < length; i++) msg += (char)payload[i];

  if (String(topic) == TOPIC_SUBSCRIBE) {
    if (msg == "TEST") test();
    if (msg == "TEST") test();
    if (msg == "TEST") test();
    if (msg == "TEST") test();
    if (msg == "TEST") test();
    if (msg == "TEST") test();
  }
}

void connectMQTT() {
  mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
  mqttClient.setCallback(mqttCallback);

  while (!mqttClient.connected()) {
    Serial.print("Connecting to MQTT...");
    if (mqttClient.connect(MQTT_CLIENT_ID)) {
      Serial.println("Connected!");
      mqttClient.subscribe(TOPIC_SUBSCRIBE);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" retrying in 2s");
      delay(2000);
    }
  }
}

#endif