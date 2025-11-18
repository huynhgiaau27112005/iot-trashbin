#include "devices.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled;

void Oled::setup() {
  // Khởi tạo I2C với chân custom
  Wire.begin(OLED_SDA, OLED_SCL); // SDA, SCL từ config.h

  // Khởi tạo OLED
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // 0x3C là địa chỉ phổ biến
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Dừng nếu không tìm thấy OLED
  }

  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 10);
  oled.println("Hello OLED!");
  oled.display();
}