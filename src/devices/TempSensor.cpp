#include "devices.h"

OneWire TempSensor::oneWire = OneWire(TEMP_SENSOR);
DallasTemperature TempSensor::tempSensor = DallasTemperature(&oneWire);

void TempSensor::setup() {
  delay(2);
  tempSensor.begin();
  tempSensor.setResolution(9); // 9 bit phân giải -> sai số tối đa 0.5 độ C
  delay(20);
}

int TempSensor::getTemperatureC() {
  tempSensor.requestTemperatures();
  float temp = tempSensor.getTempCByIndex(0);
  return (temp <= 150) ? round(temp) : round(temp - 4096);
}
// -55 -> 125
// > 0: 0 1 2 3 ...
// < 0: ... 4094 4095 0