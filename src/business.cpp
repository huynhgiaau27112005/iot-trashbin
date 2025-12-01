#include "business.h"

long preTrashLevel = 100;
void mainBusiness(){
  Oled::display(String(UltraSensor::getTrashLevel()), 3);
  PIRtoServo();

  Button::checkPress();
  if(Button::isPressed()){
    mqttPublish(TOPIC_PUBLISH_BUTTON, "Nhin cai gi ma nhin");
    
  }
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