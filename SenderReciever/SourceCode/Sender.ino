#include <Wire.h>
#include <MPU6050.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_now.h>

MPU6050 mpu;
typedef struct struct_message {
    float angle;
} struct_message;

struct_message Angles;
uint8_t broadcastAddress[] = {0xA8, 0x42, 0xE3, 0xCA, 0xF5, 0xB0}; 
 // Replace with your receiver's MAC address

// Callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.println("Last Packet Send Status: ");
  Serial.print(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed.");
    while (1);
  }
}

void loop() {
 int16_t ax, ay, az;

  // Read accelerometer data
  mpu.getAcceleration(&ax, &ay, &az);

  // Calculate pitch (rotation around X-axis)
  float angle = atan2(ay, az) * 180.0 / PI;
  Angles.angle = angle;

  Serial.println("Sending angle: ");
  Serial.print(Angles.angle);

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &Angles, sizeof(Angles));
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  } else {
    Serial.println("Error sending the data");
  }

  delay(1000);
}
