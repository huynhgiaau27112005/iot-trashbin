#include "devices.h"

void Pir::setup() {
  pinMode(PIR, INPUT);
}
bool Pir::isDetected(){
  if(digitalRead(PIR) == HIGH) return true;
  else return false;
}