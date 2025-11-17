#include <Arduino.h>
#include "config.h"
#include "setup.h"

const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;
const char* MQTT_CLIENT_ID = "esp32_client_01";
const char* TOPIC_PUBLISH = "044153414/smartbin/device";
const char* TOPIC_SUBSCRIBE = "044153414/smartbin/web";

WiFiClient espClient;
PubSubClient mqttClient(espClient);
Servo servo;
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
OneWire oneWire(TEMP_SENSOR);
DallasTemperature tempSensor(&oneWire);

void connectWiFi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");
}

// --- Hàm MQTT callback khi nhận dữ liệu ---
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String msg = "";
  for (int i = 0; i < length; i++) msg += (char)payload[i];

  if (String(topic) == TOPIC_SUBSCRIBE) {
    if (msg == "TEST") Serial.println("Message from Server: TEST");
  }
}

void connectMQTT() {
  mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
  mqttClient.setCallback(mqttCallback);

  while (!mqttClient.connected()) {
    Serial.print("Connecting to MQTT...");
    if (mqttClient.connect(MQTT_CLIENT_ID)) {
      Serial.println("Connected!");
      mqttClient.subscribe(TOPIC_SUBSCRIBE);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" retrying in 2s");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setupPIR();
  setupServo();
  setupOLED();
  setupLED();
  setupUltraSensor();
  setupTempSensor();
  setupButton();

  connectWiFi();
  connectMQTT();
}

void loop() {
  tempSensor.requestTemperatures(); 
  float tempC = tempSensor.getTempCByIndex(0); // Lấy nhiệt độ sensor đầu tiên
  Serial.print("Temperature: ");
  Serial.println(tempC);
  delay(1000);
}