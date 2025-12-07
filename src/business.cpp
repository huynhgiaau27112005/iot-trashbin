#include "business.h"

long preTrashLevel = 100;
int preTemp = 30;
void mainBusiness(){
  Button::checkPress();
  if (!Button::isPressed()) Oled::display(String(UltraSensor::getTrashLevel()), 3);
  PIRtoServo();

  ButtonToWeb();
  UltraToWeb();
  TempToWeb();
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
void UltraToWeb(){
  long nowTrashLevel = UltraSensor::getTrashLevel();
  if( nowTrashLevel != preTrashLevel){
    mqttPublish(TOPIC_PUBLISH_ULTRA, String(nowTrashLevel).c_str());
    preTrashLevel = nowTrashLevel;
    Serial.println(nowTrashLevel);
  }
}
void TempToWeb(){
  long nowTemp = TempSensor::getTemperatureC();
  if( nowTemp != preTemp){
    mqttPublish(TOPIC_PUBLISH_TEMP, String(nowTemp).c_str());
    preTemp = nowTemp;
  }
}