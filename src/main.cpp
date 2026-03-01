#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <DHTesp.h>
#include <LITTLEFS.h>

#define DHTPIN 4
DHTesp dht;

const char* ssid = "xyz";
const char* password = "xyz";
const char* url = "192.168.xxx.xxx";

// put function declarations here:
void postdata() {

  HTTPClient http;
  float temp = dht.getTemperature();
  float humd = dht.getHumidity();
  String json = "{";
  json += "\"temperature:\"" + String(temp) + ",";
  json += "\"humidity:\"" + String(humd);
  json += "}";
  http.POST(json);
}

void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nConnected");

  // Initialize DHT sensor
  dht.setup(DHTPIN, DHTesp::DHT11);

  // Mount LittleFS (ensure the correct library is installed for ESP32)
  if (!LITTLEFS.begin()) {
    Serial.println("LITTLEFS mount failed");
  }

  // Initialize websocket client (set host/port/path as needed)
  // Example: webSocket.begin("192.168.1.100", 81, "/");
}

void loop() {
  // WebSocket background handling (if initialized)
}

// put function definitions here: