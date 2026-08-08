# Arduino Reaction Game

A fast-paced interactive reaction speed game built with Arduino UNO. The system randomly illuminates one of three LEDs (Green, Yellow, or Red), requiring the player to press the corresponding button as quickly as possible to turn it off.

---

## 🛠 Hardware Components

* **1x** Arduino UNO R3
* **3x** LEDs (Green, Yellow, Red)
* **3x** Pushbutton Switches
* **3x** Resistors (for LEDs)
* **1x** Breadboard
* Jumper Wires & USB Power Cable

---

## 🔌 Pin Connections

Based on `ReactionGame.ino` and the hardware setup:

| Component | Color / Role | Arduino Pin | Notes |
| :--- | :--- | :--- | :--- |
| **LED 1** | Green (`ledPin1`) | `Digital Pin 8` | Active HIGH |
| **LED 2** | Yellow (`ledPin2`) | `Digital Pin 9` | Active HIGH |
| **LED 3** | Red (`ledPin3`) | `Digital Pin 10` | Active HIGH |
| **Button 1** | Green LED Control (`buttonPin1`) | `Digital Pin 2` | `INPUT_PULLUP` |
| **Button 2** | Yellow LED Control (`buttonPin2`) | `Digital Pin 3` | `INPUT_PULLUP` |
| **Button 3** | Red LED Control (`buttonPin3`) | `Digital Pin 4` | `INPUT_PULLUP` |

---

## ⚙️ How the Code Works

1. **Random Generator Setup:** `randomSeed(analogRead(0))` initializes a unique random sequence based on floating analog noise.
2. **Random LED Trigger:** The system generates a random number from `0` to `2` to pick which LED turns `HIGH` (Green, Yellow, or Red).
3. **Player Response:**
   * Buttons use `INPUT_PULLUP` mode (`HIGH` when unpressed, `LOW` when pressed).
   * The code checks for a valid button press matching the currently lit LED (`buttonNew == 0 && buttonOld == 1`).
   * Once the correct button is pressed, the LED turns `LOW` (off) and the next round begins.

---

## 🚀 How to Run

1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/cktang59/ReactionGame.git](https://github.com/cktang59/ReactionGame.git)
