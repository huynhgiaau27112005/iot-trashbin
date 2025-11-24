#ifndef _BUSINESS_H_
#define _BUSINESS_H_

#include <Arduino.h>
#include "config.h"

void test() {
  Serial.println("Message from Server: TEST");
}

void mainBusiness() {
  Oled::display(String(UltraSensor::getTrashLevel()), 3);
}

#endif