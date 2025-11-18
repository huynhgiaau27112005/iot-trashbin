#include "devices.h"
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(TEMP_SENSOR);
DallasTemperature tempSensor(&oneWire);

void TempSensor::setup() {
  delay(2);
  tempSensor.begin();
  delay(20);
}