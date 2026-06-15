# 07 Now We're Internetworking

Until now, we've been using the USB cable to upload programs and read logs from the ESP32. Now we're going to get the ESP32 to set up its own private wifi network and host a webpage we can use to wirelessly read messages.

## Components

Same circuit as [exercise 05](../05-potentiometer-leds/05-potentiometer-leds.md) - no changes needed.

## Circuit Pictures

![An image of the completed circuit.](../05-potentiometer-leds/circuit.jpeg)
*An image of the completed circuit.*

![A breadboard diagram of the circuit.](../05-potentiometer-leds/potentiometerbb.png)
*A breadboard diagram of the circuit — note the diagram uses a different board, but the pin numbers are correct.*

<details>
<summary>New to networking? Read this first.</summary>

A network is a group of devices that can communicate with one another.

Whenever you access the internet, your laptop accesses a wireless router, whilst this normally allows you to access the internet (which is essentially a massive global network), it also allows you to communicate with other computers connected to the router (called a LAN or Local Area Network).

In this exercise, the ESP32 will act as a router. It'll create a local wifi network called an access point which your laptop can connect directly to.

The ESP32 will also run a web server. A web server waits for requests from a web browser and sends back a response (typically a webpage).

</details>

## Exercise Steps

### 1. Wire up the circuit
Keep the circuit from exercise 05 connected.

### 2. Open the sketch

Open `07-now-were-internetworking.ino` in the Arduino IDE.

At the top of the program, you should see the wifi network details:

```c++
const char* AP_NAME = "john-board";
const char* AP_PASSWORD = "johnboard";
```

Every ESP32 in the room will be creating a wifi network. If several boards use the same name, it'll be tricky to tell them apart, so change `AP_NAME` to something unique, like your name, initialis, or something fun.

Note that the password must contain at least 8 characters

### 3. Upload the Sketch

Upload the sketch to your ESP32 (you'll still need your USB cable to do this). 

### 4. Check the Serial Monitor

Open the Serial Monitor (`Tools > Serial Monitor`) and set the baud rate to **115200**. You should see a message similar to:

```
wifi access point started.
Network name: john-board
ESP32 IP address: 192.186.4.1
Web server started.
Open http://192.168.4.1
```

The IP address tells you the unique identifier of the ESP32 on the network.

You can access the webserver at the ESP32's address.

### 5. Connect to the ESP32's wifi Network

On your phone or laptop:
1. Open the wifi settings
2. Find the network name you chose
3. Connect using the password you chose

Your phone now is a client on the network created by the ESP32.

You can thn open the web browser by entering the address printed in the Serial Monitor.

If you turn the potentiometer, you should see both the led brightnesses change, and the values on the webpage updating automatically.

### 6. You're done!
You've now created a private wifi network.

## Extensions
Once you've got the basic exercises working, you can attempt to add a webpage button that sends a command back to the ESP32.