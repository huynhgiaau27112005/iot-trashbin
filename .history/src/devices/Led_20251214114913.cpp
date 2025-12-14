#include "devices.h"

String Led::_mode = "manual";
String Led::_startTime = "18:00";
String Led::_endTime = "06:00";
bool Led::_isOn = false;

int Led::timeToMinutes(String timeStr) {
    int firstColon = timeStr.indexOf(':');
    if (firstColon == -1) return 0;
    
    int h = timeStr.substring(0, firstColon).toInt();
    int m = timeStr.substring(firstColon + 1, firstColon + 3).toInt(); 
    
    return h * 60 + m;
}

void Led::setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void Led::switchLed(bool status) {
    digitalWrite(LED, status ? HIGH : LOW);
}

void Led::updateConfig(String mode, String start, String end, bool isOn) {
  _mode = mode;
  _startTime = start;
  _endTime = end;
  _isOn = isOn;
  Serial.println("[LED] Config Updated:");
  Serial.print("Mode: "); Serial.println(_mode);
  Serial.print("Start: "); Serial.println(_startTime);
  Serial.print("End: "); Serial.println(_endTime);
  Serial.print("Manual State: "); Serial.println(_isOn ? "ON" : "OFF");

  if (_mode == "manual") {
    Serial.println("[LED] Manual Control Triggered");
    switchLed(isOn);
  } else if (_mode == "auto") {
     Serial.println("[LED] Switched to Auto Mode");
  }
}

void Led::loopCheck(int currentHour, int currentMinute) {
    if (_mode == "auto") {
        int currentTotalMins = currentHour * 60 + currentMinute;
        int startTotalMins = timeToMinutes(_startTime);
        int endTotalMins = timeToMinutes(_endTime);

        bool shouldBeOn = false;

        if (startTotalMins < endTotalMins) {
            if (currentTotalMins >= startTotalMins && currentTotalMins < endTotalMins) {
                shouldBeOn = true;
            }
        } else {
            if (currentTotalMins >= startTotalMins || currentTotalMins < endTotalMins) {
                shouldBeOn = true;
            }
        }

        switchLed(shouldBeOn);
    }
    // Mode manual: User tự điều khiển (cần thêm logic MQTT nhận lệnh ON/OFF riêng nếu muốn điều khiển realtime)
}