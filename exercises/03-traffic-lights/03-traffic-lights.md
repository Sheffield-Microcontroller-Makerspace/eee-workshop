# 03 Traffic Lights

Now that your button blinks, lets wire it up to a button to turn that blinking on and off.

## Components
| Component     | Quantity |
|---------------|----------|
| Mounted ESP32 | 1        |
| LED           | 3        |
| 120Ω Resistor | 3        |
| Jumper Wires  | 12       |
| Button        | 1        |

## Circuit Pictures
![An image of the completed circuit.](finalbreadboard.png)
*An image of the completed circuit.*

## Circuit

Wire the circuit as follows:
- Place the button in between the two halves of the breadboard as follows and attach one of the points to the ground. Attach the other point to one of the pins on the ESP32. Make sure that you have connected the ground pin of the ESP32 to the negative side of the breadboard.
![An image of the circuit with the button and wires connected.](initialbreadboard.png)
- Place all the LEDS in the same row (Ex: Row A)
![An image of the circuit with the leds attached.](ledbreadboard.png)
- Place the resistors on seperate columns (Resistor 1 in Col 3 and 10, Resistor 2 in Col 4 and 11). Connect the right side of the resistor to the pin on the ESP32. 
- Connect the cathode (shorter side) to the ground for each led and attach the anode (longer side) to the same column (Ex: Col 3) as the left side of the resistor.
![An image of the circuit with resistors, leds all wired up](finalbreadboard.png)

<details>
<summary>New to breadboards or LEDs? Read this first.</summary>

**Breadboards** let you build circuits without soldering. Components and wires plug into holes that are connected internally — the rows of holes (A–E and F–J) are connected horizontally, and the power rails running along the edges are connected vertically.

**LEDs** (Light Emitting Diodes) only allow current to flow in one direction — this is why the leg length matters. The long leg (anode) connects toward the positive voltage, and the short leg (cathode) connects to ground.

**Resistors** are needed to limit the current through the LED. Without one, too much current flows and the LED will burn out. For a 3.3V board like the ESP32 with a typical LED, a 120Ω resistor is appropriate.

</details>

## Exercise Steps

### 1. Wire up the circuit
Follow the instructions above. 

### 2. Upload the Blink sketch and Change the Variables
You should download/copy-paste the code file into your IDE. Change the PUSH_BUTTON variable to the pin that you connected the left side of your button with. Change the variable pins for the leds to the corresponding ones on your ESP32. 

### 3. Check the result
Your LEDS should now be blinking in succession of one another. [move on to the next exercise!](../04-9-led/04-9-led.md)

> **Having trouble?** Check that the LED is the right way round — the long leg should be on the resistor side. If it's still not working, try a different LED from the kit. If your code doens't run hold the Boot button before plugging in your USB. Once it is plugged in, run your code and unplug and replug into your laptop. It should work as intended once you have done that. If not please ask a representative to assist you.
