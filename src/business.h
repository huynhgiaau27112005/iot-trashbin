#ifndef _BUSINESS_H_
#define _BUSINESS_H_

#include <Arduino.h>
#include "config.h"
#include "topics.h"
#include "mqtt.h"
#include "devices/devices.h"
#include "devices/OledMode.h"

void mainBusiness();

// Luồng nâng cao: INPUT -> OUTPUT: PIR -> SERVO 
void PIRtoServo();

// Luồng cơ bản: INPUT -> WEB: Nhấn giữ nút 5 giây -> Nhận tín hiệu hư hỏng
void ButtonToWeb();

// Luồng cơ bản: INPUT -> WEB: Đo mực rác gửi lên Web
void UltraToWeb();

// Luồng nâng cao: INPUT -> WEB: Đo nhiệt độ gửi lên Web
void TempToWeb();
#endif