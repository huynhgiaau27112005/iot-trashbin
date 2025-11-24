#include "devices.h"

long UltraSensor::BIN_DEPTH_CM = 123;  //sqrt(100^2 + 73^2) = 123.8 cm
long UltraSensor::current_distance = 0;
long UltraSensor::current_level = 0;
double SOUND_SPEED = 0.034;  // Tốc độ âm thanh ~ 0.034 cm/us

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
  long distance = duration * SOUND_SPEED / 2;
  return distance;
}

long UltraSensor::getTrashLevel() {
  long distance = measureDistanceCM();
  if (abs(distance - current_distance) <= 1) return current_level;

  long level = floor(100.0 * distance / BIN_DEPTH_CM);
  long scaledLevel = constrain(level, 0, 100);

  current_distance = distance;
  current_level = scaledLevel;
  return scaledLevel;
}