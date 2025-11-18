#include "devices.h"

void UltraSensor::setup() {
  pinMode(ULTRA_SENSOR_TRIG, OUTPUT);
  pinMode(ULTRA_SENSOR_ECHO, INPUT);
  digitalWrite(ULTRA_SENSOR_TRIG, LOW);
  delay(100);
}

long UltraSensor::measureDistanceCM() {
  // Gửi xung 10us lên TRIG
  digitalWrite(ULTRA_SENSOR_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_SENSOR_TRIG, LOW);

  // Đọc thời gian xung trên ECHO
  long duration = pulseIn(ULTRA_SENSOR_ECHO, HIGH, 30000); // timeout 30ms (~5m)
  
  // Chuyển sang khoảng cách cm
  long distance = duration * 0.034 / 2; // Tốc độ âm thanh ~ 0.034 cm/us
  return distance;
}