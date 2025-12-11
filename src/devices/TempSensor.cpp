#include "devices.h"

OneWire TempSensor::oneWire = OneWire(TEMP_SENSOR);
DallasTemperature TempSensor::tempSensor = DallasTemperature(&oneWire);

void TempSensor::setup() {
  delay(2);
  tempSensor.begin();
  tempSensor.setResolution(12);
  delay(20);
}

int TempSensor::getTemperatureC() {
  tempSensor.requestTemperatures();
  float temp = tempSensor.getTempCByIndex(0);
  return (temp <= 2048) ? round(temp) : round(temp - 4096);
}