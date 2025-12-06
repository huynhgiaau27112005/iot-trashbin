#include "OledMode.h"
#include "devices/devices.h"

OLED_MODE OLEDManager::mode = MODE_TRASH;
String OLEDManager::mqttMessage = "";

void OLEDManager::showTrash(long level) {
    if (mode != MODE_TRASH) return;
    Oled::display(String(level), 3);
}

void OLEDManager::showMQTT(const String &msg) {
    mode = MODE_MQTT;
    mqttMessage = msg;
    Oled::display(msg, 1);
}

void OLEDManager::resetToTrash() {
    mode = MODE_TRASH;
}
