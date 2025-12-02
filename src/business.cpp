#include "business.h"
void mainBusiness(){
  Oled::display(String(UltraSensor::getTrashLevel()), 3);
  PIRtoServo();

  Button::checkPress();
  if(Button::isPressed()){
    mqttPublish(TOPIC_PUBLISH_BUTTON, "Nhin cai gi ma nhin");
    
  }
}

void PIRtoServo() {
  if (Pir::isDetected()) {
    ServoMotor::open();
  } else {
    ServoMotor::close();
  }
}

void ButtonToWeb() {
  Button::checkPress();
  if (Button::isPressed()) {
    Serial.println("Pressed");
  }
}