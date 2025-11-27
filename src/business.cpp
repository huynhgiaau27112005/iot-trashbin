 #include "business.h"
 void mainBusiness(){
  Button::checkPress();
  if(Button::isPressed()){
    mqttPublish(TOPIC_PUBLISH_BUTTON, "Nhin cai gi ma nhin");
    
  }

}