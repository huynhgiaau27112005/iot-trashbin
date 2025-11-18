#include "devices.h"
#include <Servo.h>

Servo servo;

void ServoMotor::setup() {
  servo.attach(SERVO);    // Gắn Servo vào chân SERVO
  servo.write(SERVO_MIN); // Khởi tạo ở vị trí gập
}