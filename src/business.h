#ifndef _BUSINESS_H_
#define _BUSINESS_H_

#include <Arduino.h>
#include "config.h"

void test() {
  Serial.println("Message from Server: TEST");
}

// Luồng nâng cao: INPUT -> OUTPUT: PIR -> SERVO
void PIRtoServo() {
  if (Pir::isDetected()) {
    ServoMotor::open();
  } else {
    ServoMotor::close();
  }
}

void mainBusiness() {
  Oled::display(String(UltraSensor::getTrashLevel()), 3);
  PIRtoServo();
}

#endif