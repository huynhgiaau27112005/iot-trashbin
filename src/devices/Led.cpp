#include "devices.h"

String Led::_mode = "manual";
String Led::_startTime = "18:00";
String Led::_endTime = "06:00";

void Led::setup() {
  pinMode(LED, OUTPUT);
}

void Led::switchLed(bool status) {
  if(status) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);
}

void Led::updateConfig(String mode, String start, String end) {
  _mode = mode;
  _startTime = start;
  _endTime = end;

  Serial.println("[LED] Config Updated:");
  Serial.print("Mode: "); Serial.println(_mode);
  Serial.print("Start: "); Serial.println(_startTime);
  Serial.print("End: "); Serial.println(_endTime);

  if (_mode == "manual") {
  } else if (_mode == "auto") {
     Serial.println("[LED] Switched to Auto Mode");
  }
}

void Led::loopCheck() {
  if (_mode == "auto") {
    // TODO: So sánh thời gian hiện tại (Real Time) với _startTime và _endTime
    // Nếu nằm trong khoảng -> switchLed(true), ngược lại false.
    // Lưu ý: Cần có module lấy giờ (NTP Client) mới chạy được chức năng này.
  }
}