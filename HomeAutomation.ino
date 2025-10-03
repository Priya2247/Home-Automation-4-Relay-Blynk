#define BLYNK_TEMPLATE_ID   "YourTemplateID"  // From Blynk.Cloud
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN    "YourAuthToken"   // From Blynk App

#include <WiFi.h>            // For ESP32 (use <ESP8266WiFi.h> if NodeMCU ESP8266)
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h> // Or BlynkSimpleEsp8266.h depending on your board

// Your WiFi credentials
char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";

// Relay Pin Definitions
#define RELAY1  D1
#define RELAY2  D2
#define RELAY3  D3
#define RELAY4  D4

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Connect to WiFi & Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Set relay pins as output
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  // Initially OFF (Active LOW Relay)
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
}

// V1 -> Relay 1
BLYNK_WRITE(V1) {
  int value = param.asInt(); // 0 or 1
  digitalWrite(RELAY1, value ? LOW : HIGH); // Active LOW
}

// V2 -> Relay 2
BLYNK_WRITE(V2) {
  int value = param.asInt();
  digitalWrite(RELAY2, value ? LOW : HIGH);
}

// V3 -> Relay 3
BLYNK_WRITE(V3) {
  int value = param.asInt();
  digitalWrite(RELAY3, value ? LOW : HIGH);
}

// V4 -> Relay 4
BLYNK_WRITE(V4) {
  int value = param.asInt();
  digitalWrite(RELAY4, value ? LOW : HIGH);
}

void loop()
{
  Blynk.run();
}
