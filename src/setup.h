#pragma once
#include "config.h"

void setupPIR() {
  pinMode(PIR, INPUT); // ok
}

void setupServo() {
  servo.attach(SERVO);        // Gắn Servo vào chân SERVO // ok
  servo.write(SERVO_MIN);     // Khởi tạo ở vị trí gập
}

void setupOLED() {
  // Khởi tạo I2C với chân custom
  Wire.begin(OLED_SDA, OLED_SCL);  // SDA, SCL từ config.h // ok

  // Khởi tạo OLED
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C là địa chỉ phổ biến
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Dừng nếu không tìm thấy OLED
  }

  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 10);
  oled.println("Hello OLED!");
  oled.display();
}

void setupLED() {
  pinMode(LED, OUTPUT); // ok
}

void setupUltraSensor() {
  pinMode(ULTRA_SENSOR_TRIG, OUTPUT); // ok
  pinMode(ULTRA_SENSOR_ECHO, INPUT);
  digitalWrite(ULTRA_SENSOR_TRIG, LOW);
  delay(100); // Cho cảm biến ổn định
}

void setupTempSensor() {
  delay(2);
  tempSensor.begin(); // Khởi tạo cảm biến nhiệt độ DS18B20
  delay(20);
}

void setupButton() {
  pinMode(BUTTON, INPUT); // ok
}