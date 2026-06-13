# 06 Dimming LEDs with PWM

In the last exercise the potentiometer switched between LEDs — now we'll use it to actually dim them. The ESP32 can't output a truly variable voltage, so instead it rapidly switches the pin on and off. The ratio of on-time to off-time is called the **duty cycle**, and your eyes perceive it as brightness. This technique is called **pulse-width modulation (PWM)**.

## Components

Same circuit as [exercise 05](../05-potentiometer-leds/05-potentiometer-leds.md) — no changes needed.

## Exercise Steps

### 1. Open the sketch

Open `06-dimming-leds.ino` in the Arduino IDE.

### 2. Upload and run

Upload the sketch to your ESP32. Turn the potentiometer dial — all three LEDs should dim and brighten together as you turn it.

### 3. Check the Serial Monitor

Open the Serial Monitor (`Tools > Serial Monitor`) at **115200** baud. You'll see two values printing:

- **Potentiometer Resistance** — the raw ADC value (0–4095)
- **Potentiometer Normalised Value** — the same value scaled down to 0–255

`analogWrite` expects a value between 0 and 255, so the sketch maps the ADC range to that range with a simple multiplication. Notice how the two values track each other as you turn the dial.

### 4. You're done!

Once the LEDs dim smoothly from off to full brightness, you've completed this exercise. Nice work — you've now used both digital and analog signals to control LEDs!

> **Having trouble?** If the LEDs aren't dimming smoothly, check the Serial Monitor to confirm the potentiometer values are changing. If they're stuck at 0 or 4095, the wiper wire may not be connected to A3.
