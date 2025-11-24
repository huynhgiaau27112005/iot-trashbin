#ifndef _DEVICES_H_
#define _DEVICES_H_

#include "config.h"

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
public:
  static void setup();
};

class Pir {
public:
static void setup();
static bool isDetected();
};

class ServoMotor {
public:
  static void setup();
};

class TempSensor {
public:
  static void setup();
};

class UltraSensor {
public:
  static void setup();
  long measureDistanceCM();
};

#endif