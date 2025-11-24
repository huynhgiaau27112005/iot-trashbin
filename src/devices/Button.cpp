#include "devices.h"
bool Button::isPressed5s = false;
bool Button::isPress = false;
long long Button::startTime = millis();
long long Button::endTime = millis();
void Button::setup() {
  pinMode(BUTTON, INPUT);
  
}

void Button::checkPress(){
    if(!Button::isPressed5s){
      if(digitalRead(BUTTON) == HIGH && !Button::isPress){
        startTime = millis();
        Button::isPress = true;
      }else if(digitalRead(BUTTON) == HIGH ){
        Button::endTime = millis();
        if(Button::endTime - Button::startTime >= 5000){
          Button::isPressed5s = true;
        }
      }else{
        Button::isPress = false;
      }
    }
}
bool Button::isPressed(){
  if(Button::isPressed5s){
    Button::isPressed5s = false;
    return true;
  }else{
    return false;
  }
}
