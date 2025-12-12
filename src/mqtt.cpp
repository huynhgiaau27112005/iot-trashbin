#include "mqtt.h"
#include "topics.h"
#include "devices/devices.h"
#include "devices/OledMode.h"
#include <ArduinoJson.h>

const char *MQTT_BROKER = "test.mosquitto.org"; // "test.mosquitto.org"; //"broker.hivemq.com";
const int MQTT_PORT = 1883;
const char *MQTT_CLIENT_ID = "esp32_client_04";
PubSubClient mqttClient(espClient);
// --- Hàm MQTT callback khi nhận dữ liệu ---

void mqttCallback(char *topic, byte *payload, unsigned int length)
{

    String msg = "";
    msg.reserve(length);
    for (int i = 0; i < length; i++)
        msg += (char)payload[i];

    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    Serial.println(msg);

    if (String(topic) == TOPIC_SUBSCRIBE_OLED)
    {
        if (msg.equalsIgnoreCase("RESET"))
        {
            OLEDManager::resetToTrash();
            return;
        }
        OLEDManager::showMQTT(msg);
        return;
    }

    else if (String(topic) == TOPIC_SUBSCRIBE_LED)
    {

        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, msg);

        if (error)
        {
            Serial.print(F("deserializeJson() failed: "));
            Serial.println(error.f_str());
            return;
        }

        const char *mode = doc["mode"];
        const char *start = doc["start"];
        const char *end = doc["end"];

        Led::updateConfig(String(mode), String(start), String(end));
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
        String fullMessage = String(BIN_ID); // "41653/bin-full"
        fullMessage += "/";
        fullMessage += message;
        mqttClient.publish(topic, fullMessage.c_str());
    }
}