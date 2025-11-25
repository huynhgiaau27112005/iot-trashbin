#ifndef _DEVICES_H_
#define _DEVICES_H_

#include "config.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class Button {
public:
  
  static long long startTime;
  static long long endTime;
  static bool isPress;
  static bool isPressed5s;


  static void setup();
  static void checkPress();
  static bool isPressed();

};

class Led {
public:
  static void setup();
};

class Oled {
private:
  static Adafruit_SSD1306 oled;
  static String current_message;
public:
  static void setup();
  static void display(const String& message, int textSize = 2);
};

class Pir {
public:
static void setup();
static bool isDetected();
};

class ServoMotor {
public:
  static void setup();
  static void close();
  static void open();
};

class TempSensor {
private:
  static OneWire oneWire;
  static DallasTemperature tempSensor;
public:
  static void setup();
  static int getTemperatureC();
};

class UltraSensor {
private:
  static long BIN_DEPTH_CM;
  static long current_distance;
  static long current_level;
public:
  static void setup();
  static long measureDistanceCM();
  static long getTrashLevel();
};

#endif