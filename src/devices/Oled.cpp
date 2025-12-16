#include "devices.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <sstream>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 Oled::oled(128, 64, &Wire);

String Oled::current_message = "Connecting...";

void Oled::setup()
{
    // Khởi tạo I2C với chân custom
    Wire.begin(OLED_SDA, OLED_SCL); // SDA, SCL từ config.h

    // Khởi tạo OLED
    if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
        while(true); // Dừng nếu không tìm thấy OLED
    }

    oled.clearDisplay();
    oled.setTextSize(2);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0, 10);
    oled.println(Oled::current_message);
    oled.display();
}

void Oled::display(const String &message, int textSize)
{
    if (message == Oled::current_message)
        return;

    oled.clearDisplay();
    oled.setTextSize(textSize);

    // Căn giữa chiều cao và chiều ngang của văn bản (không chứa kí tự xuống dòng nhé)
    // Tính chiều rộng ký tự (mặc định font 6x8)
    int charWidth = 6 * textSize;
    int charHeight = 8 * textSize;
    int maxCharactersInLine = oled.width() / charWidth;

    int textLines = ceil(1.0 * message.length() / maxCharactersInLine);
    int textHeight = textLines * charHeight;
    int y = (oled.height() - textHeight) / 2;

    
    for (size_t i = 0; i < message.length(); i += maxCharactersInLine) {
        String lineMessage = message.substring(i, i + maxCharactersInLine);
        
        int textWidth = lineMessage.length() * charWidth;
        int x = (oled.width() - textWidth) / 2; // căn giữa
        
        oled.setCursor(x, y);
        oled.print(lineMessage);
        
        y += charHeight;
    }

    oled.display();
    Oled::current_message = message;
}