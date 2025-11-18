#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <WiFi.h>

#define WIFI_SSID "Wokwi-GUEST" // ae đổi lại thành tên và mật khẩu wifi cho đúng với nhà ae nhá
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

const int SERVO_MIN = 0;    // Góc gập Servo
const int SERVO_MAX = 90;   // Góc mở Servo khi detect PIR

// OLED display width/height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#endif