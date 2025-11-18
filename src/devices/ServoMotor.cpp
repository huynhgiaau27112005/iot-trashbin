#include "devices.h"
#include <Servo.h>

const int SERVO_MIN = 0;    // Góc gập Servo
const int SERVO_MAX = 90;   // Góc mở Servo khi detect PIR

Servo servo;

void ServoMotor::setup() {
  servo.attach(SERVO);    // Gắn Servo vào chân SERVO
  servo.write(SERVO_MIN); // Khởi tạo ở vị trí gập
}