# 🌐 InternetOf-Things: Smart Control Solutions

Welcome to the **InternetOf-Things** repository! 🚀 This project empowers you to create **affordable, practical IoT solutions** using **ESP32** microcontrollers and **MPU6050 sensors**. With **ESP-NOW wireless communication**, you'll be able to control devices remotely with minimal infrastructure—no need for a complex Wi-Fi network or cloud service!

By leveraging **cheap hardware**, you can easily build a variety of innovative IoT devices for **home automation, security, robotics, and more**. Let's bring your ideas to life without breaking the bank!

---

## 🎯 Real-World Use Cases

This project is designed to help you build practical, **cost-effective IoT devices** with ESP32, and can be expanded for multiple applications such as:

### 1. **Smart Home Automation on a Budget**
   - **Control lights and appliances** with tilt sensors using ESP32 and relays.
   - **Automate curtains or fans** with simple gestures—turn on or off based on tilt angle.
   - **Voice or motion-triggered systems** with minimal cost using PIR sensors, ESP32, and cheap relay modules.

### 2. **Automated Gate Opener**
   - **Control a motorized gate** with a tilt sensor connected to ESP32.
   - Use a simple **tilt gesture to open/close** the gate or door for secure access.
   - **Affordable relay switches** and a low-cost ESP32 make this setup cheap and easy.

### 3. **Affordable Security System**
   - Turn your **MPU6050 sensor into a motion detector** for door or window security.
   - **Tilt sensors** alert you if something is tampered with or moved (ideal for low-cost security systems).
   - **Activate alarms** or lights when suspicious movement or unusual tilt is detected.

### 4. **Low-Cost Remote-Controlled Car or Robot**
   - Use the ESP32 to control **robotic vehicles** or **RC cars** based on motion or tilt data.
   - Create **simple motion controls** using tilt gestures (e.g., move left, right, forward, or backward).
   - A **super affordable way** to start learning robotics without needing expensive controllers or hardware.

### 5. **Cheap Weather Station**
   - Pair the **MPU6050 sensor** with other environmental sensors (e.g., temperature, humidity) to create a **low-cost weather station**.
   - Monitor **angles of wind sensors** or **tilt-based weather tracking**.
   - View data remotely on a simple mobile app or web dashboard.

### 6. **Home Automation with Voice Control**
   - Combine the tilt sensor with **voice-controlled modules** (like a cheap voice assistant or Alexa-compatible system) to **control appliances**.
   - Use **tilt-based gestures** to turn devices on/off with voice and motion, at a fraction of the cost of other smart home setups.

---

## 🚀 Getting Started

This project demonstrates how to wirelessly send tilt data from an **MPU6050 sensor** using **ESP32** boards and control external devices such as **relays** (or LEDs). You can take this setup and easily extend it to more powerful applications such as automation, robotics, and security.

### 📋 Prerequisites

- **Hardware**:
  - **2 x ESP32 boards** (costs about $5-$10 each)
  - **1 x MPU6050 sensor** (costs around $2)
  - **3 x Relays or LEDs** (relays cost as low as $1 each)
  - **Breadboard, jumper wires**, and **power supply**
  - **Optional**: PIR sensor for motion detection, temperature or humidity sensors for additional functionality

- **Software**:
  - **Arduino IDE** (free)
  - ESP32 board package installed in Arduino IDE
  - Libraries: **MPU6050** and **ESP-NOW**

---

## ⚙️ Hardware Setup

### Sender (ESP32 + MPU6050)
- **MPU6050** to **ESP32**:
  - `VCC` -> `3.3V`
  - `GND` -> `GND`
  - `SCL` -> `GPIO 22`
  - `SDA` -> `GPIO 21`

### Receiver (ESP32 + Relays/Devices)
- **Relays or LEDs** connected to ESP32:
  - **Left Device (Relay 1)**: `Pin 12`
  - **Middle Device (Relay 2)**: `Pin 13`
  - **Right Device (Relay 3)**: `Pin 14`
  - Each relay should have a **220Ω resistor** if using LEDs or direct connections for other devices.

---

## 📦 Library Installation

To get the code up and running, install the following libraries in Arduino IDE:

1. **Install the ESP32 Board Package**:
   - Go to **File > Preferences** in Arduino IDE.
   - Add the following URL:
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Then go to **Tools > Board > Boards Manager** and install **ESP32**.

2. **Install Libraries**:
   - **MPU6050 Library**: Search for "MPU6050" in **Sketch > Include Library > Manage Libraries**.
   - **ESP-NOW**: This is built into the ESP32 board package.

---

## 🖥️ Code Explanation

### Sender Code
The **Sender ESP32**:
- Reads accelerometer data from the **MPU6050 sensor**.
- Calculates the tilt angle and sends it wirelessly to the **Receiver ESP32** using ESP-NOW.
- This data can control relays, LEDs, or any external devices based on the tilt.

### Receiver Code
The **Receiver ESP32**:
- Receives angle data from the sender.
- **Controls relays or LEDs** based on the angle:
  - **Tilt > +60°**: Activates Relay 3 (e.g., to open a gate).
  - **Tilt < -60°**: Activates Relay 1 (e.g., to turn on a light).
  - **Tilt between -60° to +60°**: Activates Relay 2 (e.g., to control a fan or other appliance).

---

## 🛠️ Software Setup

### Step 1: Upload the Code
1. **Sender Code**:
   - Open `sender.ino` and upload it to your first ESP32 board.
   - Make sure to replace the receiver’s MAC address in the code.

2. **Receiver Code**:
   - Open `receiver.ino` and upload it to the second ESP32 board.

### Step 2: Test the Setup
- Power on both ESP32 devices.
- Open the Serial Monitor for both devices (set the baud rate to **115200**).
- Tilt the MPU6050 sensor and observe how the relays or connected devices respond.

---

## 💡 Example Applications

### **1. Budget-Friendly Home Automation**
   - **Scenario**: Control lights, fans, or appliances based on motion or tilt.
   - **Cost**: ~$15 for all components.
   - **Devices**: Use relays to control low-voltage appliances or simply trigger LEDs.

### **2. Secure Your Home with Low-Cost Sensors**
   - **Scenario**: Use a motion or tilt-based system to detect tampering with doors or windows.
   - **Cost**: ~$10 for sensors and relays.
   - **Devices**: Trigger alarms or notifications when unexpected tilt is detected.

### **3. DIY Automated Gate Control**
   - **Scenario**: Control a motorized gate with simple gestures.
   - **Cost**: ~$20 for the relay, ESP32, and other components.
   - **Devices**: Use a relay to control the gate's motor or locking mechanism.

### **4. Affordable Robotics with Tilt Control**
   - **Scenario**: Create a simple tilt-controlled robot or car.
   - **Cost**: ~$20 for the entire setup.
   - **Devices**: Use ESP32 to control movement using tilt data from the MPU6050.

---

## 🛠️ Troubleshooting

1. **ESP-NOW Initialization Error**:
   - Ensure both ESP32 boards are powered on and in range of each other.
   - Double-check the MAC address configuration in the sender's code.

2. **MPU6050 Not Detected**:
   - Check the wiring connections, and ensure that the sensor is properly powered.
   - Ensure the sensor is connected to the correct SDA and SCL pins (GPIO 21 and 22 by default).

3. **Relays/Devices Not Responding**:
   - Verify the relay connections and make sure they are receiving enough power.
   - Ensure the relay pins in the code match the hardware setup.

---

## 🤝 Contributing

Want to enhance this project? Here’s how you can contribute:

1. **Fork the repository**.
2. **Create a new branch** (`feature/your-feature`).
3. **Submit a pull request**.

---

## 🐛 Issues & Support

If you encounter any bugs or have questions, feel free to open an issue. We’re here to help! 😊

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---

Happy Building! 🛠️🚀
