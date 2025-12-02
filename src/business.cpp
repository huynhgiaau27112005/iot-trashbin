#include "business.h"
void mainBusiness(){
  Button::checkPress();
  if (!Button::isPressed()) Oled::display(String(UltraSensor::getTrashLevel()), 3);
  PIRtoServo();

  ButtonToWeb();
}

void PIRtoServo() {
  if (Pir::isDetected()) {
    ServoMotor::open();
  } else {
    ServoMotor::close();
  }
}

bool malfunctionSent = false;
void ButtonToWeb() {
  if (Button::isPressed()){
    Oled::display(String("Fault Signal Sent!"), 1);
    if (!malfunctionSent) {
      mqttPublish(TOPIC_PUBLISH_BUTTON, "device-malfunction");
      malfunctionSent = true;
    }
  } else {
    malfunctionSent = false;
  }
}