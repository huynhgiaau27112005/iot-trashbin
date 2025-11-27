#ifndef _MQTT_H_
#define _MQTT_H_

#include <Arduino.h>
#include <PubSubClient.h>
#include "config.h"
#include "business.h"
#include <sstream>
extern const char* MQTT_BROKER ;
extern const int MQTT_PORT ;
extern const char* MQTT_CLIENT_ID ;
extern PubSubClient mqttClient;

// --- Hàm MQTT callback khi nhận dữ liệu ---
void mqttCallback(char* topic, byte* payload, unsigned int length) ;
void connectMQTT();
void mqttPublish(const char* topic, const char* message) ;
#endif