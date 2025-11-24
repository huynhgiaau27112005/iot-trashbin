#include "devices.h"

OneWire TempSensor::oneWire = OneWire(TEMP_SENSOR);
DallasTemperature TempSensor::tempSensor = DallasTemperature(&oneWire);

void TempSensor::setup() {
  delay(2);
  tempSensor.begin();
  delay(20);
}

int TempSensor::getTemperatureC() {
  tempSensor.requestTemperatures();
  return (int)round(tempSensor.getTempCByIndex(0));
}