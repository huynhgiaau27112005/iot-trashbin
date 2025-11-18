#ifndef _DEVICES_H_
#define _DEVICES_H_

#include "config.h"

class Button {
public:
  static void setup();
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