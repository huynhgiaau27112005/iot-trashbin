#include "business.h"

long preTrashLevel = 100;
void mainBusiness(){
  Button::checkPress();
  if (!Button::isPressed()) Oled::display(String(UltraSensor::getTrashLevel()), 3);
  PIRtoServo();

  ButtonToWeb();
  
  long nowTrashLevel = UltraSensor::getTrashLevel();
  if( nowTrashLevel != preTrashLevel){
     char charLevel[4];
    ltoa(nowTrashLevel, charLevel, 10);
    mqttPublish(TOPIC_PUBLISH_ULTRA, charLevel);
    preTrashLevel = nowTrashLevel;
  }
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