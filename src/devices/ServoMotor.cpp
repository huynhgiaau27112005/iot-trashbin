#include "devices.h"
#include <Servo.h>

const int SERVO_MIN = 0;    // Góc gập Servo
const int SERVO_MAX = 75;   // Góc mở Servo khi detect PIR

Servo servo;

void ServoMotor::setup() {
  servo.attach(SERVO);   
  servo.write(SERVO_MIN); 
}

void ServoMotor::close() {
  servo.write(SERVO_MIN);
}

void ServoMotor::open() {
  servo.write(SERVO_MAX);
}