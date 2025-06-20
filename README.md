# 🏓 Arduino Ping Pong Game

A simple Pong game using an Arduino Uno, OLED display, and two potentiometers as paddles. Simulate and test it live with Wokwi!

▶️ **Try it now on Wokwi**: [Click here to open in Wokwi](https://wokwi.com/projects/434303298717606913)

---

## 🔧 Components Used

- Arduino Uno
- 0.96" I2C OLED Display (SSD1306)
- 2x Potentiometers
- Jumper Wires

---

## ⚡ Circuit Diagram

![Arduino Circuit](![PingPong_circuit_diagram](https://github.com/user-attachments/assets/cf4e061d-fb61-4b65-ae7b-6b019ca5a69f))

---

## 🧠 Controls

- **Left Paddle** → Potentiometer on A1  
- **Right Paddle** → Potentiometer on A2

---

## 📝 Features

- Real-time Pong ball animation on OLED
- Responsive analog paddle movement
- Collision detection with boundaries and paddles
- Easily testable in Wokwi simulator

---

## 🛠️ Setup Instructions

1. Clone or download this repo
2. Open `pong_game.ino` in Arduino IDE
3. Install these libraries via Library Manager:
   - `Adafruit GFX`
   - `Adafruit SSD1306`
4. Upload to Arduino Uno
5. Enjoy the game on your OLED!

---

## 📁 File Structure

```bash
/
├── pong_game.ino
├── media/
│   └── arduino-circuit.png
├── README.md
└── LICENSE
