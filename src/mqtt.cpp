#include "mqtt.h"
#include "topics.h"
#include "devices/devices.h"
#include "devices/OledMode.h"

const char *MQTT_BROKER = "test.mosquitto.org"; //"broker.hivemq.com";
const int MQTT_PORT = 1883;
const char *MQTT_CLIENT_ID = "esp32_client_01";
PubSubClient mqttClient(espClient);
// --- Hàm MQTT callback khi nhận dữ liệu ---

void mqttCallback(char *topic, byte *payload, unsigned int length)
{

    String msg = "";
    msg.reserve(length);
    for (int i = 0; i < length; i++)
        msg += (char)payload[i];

    Serial.println(msg);

    if (String(topic) == TOPIC_SUBSCRIBE_OLED) {
        // Nếu message = "RESET" → về chế độ TRASH
        if (msg.equalsIgnoreCase("RESET")) {
            OLEDManager::resetToTrash();
            Serial.println("[OLED] Reset to TRASH mode");
            return;
        }

        // Ngược lại → hiển thị message từ MQTT
        OLEDManager::showMQTT(msg);
        Serial.println("[OLED] Showing MQTT message");
        return;
    }
    else
    {
        Serial.println("Not Oled");
    }
}

void connectMQTT()
{
    mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
    mqttClient.setCallback(mqttCallback);

    while (!mqttClient.connected())
    {
        Serial.print("Connecting to MQTT...");
        if (mqttClient.connect(MQTT_CLIENT_ID))
        {
            Serial.println("Connected!");
            mqttClient.subscribe(TOPIC_SUBSCRIBE_OLED);
            mqttClient.subscribe(TOPIC_SUBSCRIBE_LED);
        }
        else
        {
            Serial.print("Failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println(" retrying in 2s");
            delay(2000);
        }
    }
}
void mqttPublish(const char *topic, const char *message)
{
    if (mqttClient.connected())
    {
        mqttClient.publish(topic, message);
    }
}