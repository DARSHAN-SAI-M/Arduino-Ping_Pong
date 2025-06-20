# 🕹️ Arduino OLED Ping Pong Game

This project is a simple yet fun **two-player Ping Pong game** built using an **Arduino UNO**, a **0.96" SSD1306 OLED display**, and **two analog controls** (like potentiometers or joysticks). It's a digital version of the classic Pong arcade game, rendered directly on an OLED screen.

Designed and simulated using **Wokwi**, this game features:

## 🎮 Features

- Smooth paddle movement for both players  
- Ball physics with wall and paddle collision detection  
- Real-time gameplay on a tiny OLED screen  
- Fully compatible with Adafruit GFX and SSD1306 libraries  
- Runs on Arduino Uno/Nano (minimal hardware)

## 🔧 Controls

- **Left Paddle**: Analog input A1 (Potentiometer or Joystick Y-axis)  
- **Right Paddle**: Analog input A2 (Potentiometer or Joystick Y-axis)  
- Move the paddles vertically to hit the ball and prevent it from passing your side.

## 📦 Hardware Requirements

| Component             | Description                        |
|----------------------|------------------------------------|
| Arduino UNO / Nano   | Main microcontroller               |
| OLED Display (128x64)| I2C SSD1306 OLED for display       |
| 2x Potentiometers     | Paddle controllers (or use joysticks) |
| Breadboard + Wires    | For connections                    |

## 🔌 OLED Pin Connections

| OLED Pin | Arduino Pin |
|----------|-------------|
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

## 🚀 Try It Online

🟢 **Live Simulator (Wokwi)**:  
[Click to Play the Game in Wokwi →](https://wokwi.com/projects/434303298717606913)

## 📜 License

This project is open-source and free to use. Contributions welcome!
