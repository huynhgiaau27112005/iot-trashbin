#include "devices.h"

void Led::setup() {
  pinMode(LED, OUTPUT);
}
void Led::switchLed(bool status)
{
  if(status) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);
}