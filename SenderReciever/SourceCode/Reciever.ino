#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_now.h>

typedef struct struct_message {
    float angle;
} struct_message;

struct_message RAngles;

const int ledPinL = 12;
const int ledPinM = 13;
const int ledPinR = 14;

const int angleThreshold = 60;

void OnDataRecv(const esp_now_recv_info *recvInfo, const uint8_t *incomingData, int len) {
  memcpy(&RAngles, incomingData, sizeof(RAngles));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Received angle: ");
  Serial.println(RAngles.angle);

  // Optional: Print the MAC address of the sender
  Serial.print("From MAC Address: ");
  for (int i = 0; i < 6; i++) {
    Serial.printf("%02X", recvInfo->src_addr[i]);
    if (i < 5) Serial.print(":");
  }
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  pinMode(ledPinM, OUTPUT);
  pinMode(ledPinL, OUTPUT);
  pinMode(ledPinR, OUTPUT);
}

void loop() {
  float angle = RAngles.angle;
  Serial.print("Angle: ");
  Serial.println(angle);

  if (angle > angleThreshold) {
    digitalWrite(ledPinR, HIGH);
    digitalWrite(ledPinL, LOW);
    digitalWrite(ledPinM, LOW);
  } else if (angle < -angleThreshold) {
    digitalWrite(ledPinL, HIGH);
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinM, LOW);
  } else {
    digitalWrite(ledPinM, HIGH);
    digitalWrite(ledPinL, LOW);
    digitalWrite(ledPinR, LOW);
  }

  delay(100);
}
