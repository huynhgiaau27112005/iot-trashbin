#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <WiFi.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASS ""
extern WiFiClient espClient;

const int PIR = 19;
const int SERVO = 18;
const int OLED_SCL = 21; 
const int OLED_SDA = 22;
const int LED = 5;
const int ULTRA_SENSOR_TRIG = 17;
const int ULTRA_SENSOR_ECHO = 16;
const int TEMP_SENSOR = 32;
const int BUTTON = 14;

#endif