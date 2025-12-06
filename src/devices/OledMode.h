#pragma once
#include <Arduino.h>

enum OLED_MODE { MODE_TRASH, MODE_MQTT };

class OLEDManager {
public:
    static OLED_MODE mode;
    static String mqttMessage;

    static void showTrash(long level);
    static void showMQTT(const String &msg);
    static void resetToTrash();
};
