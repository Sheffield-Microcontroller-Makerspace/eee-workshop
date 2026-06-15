#include <WiFi.h>
#include <WebServer.h>

#define RED_LED    11
#define AMBER_LED 12
#define GREEN_LED 13

int pot_val = 0;
int red_val = 0;
int amber_val = 0;

#define POT_PIN    A0

int green_val = 0;

// Give your board a unique name
const char* AP_NAME = "john-board";
const char* AP_PASSWORD = "johnboard";

WebServer server(80);

void updateOutputs() {
  pot_val = analogRead(POT_PIN);

  float angle = map(pot_val, 0, 4095, 0, 180) * (PI / 180.0);

  red_val = 255 * cos(angle/2);
  amber_val = 255 * sin(angle);
  green_val = 255 * (1 - cos(angle/2));

  analogWrite(RED_LED, red_val);
  analogWrite(AMBER_LED, amber_val);
  analogWrite(GREEN_LED, green_val);
}

void sendWebPage() {
  const char page[] = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta
    name="viewport"
    content="width=device-width, initial-scale=1"
  >
  <title>ESP32 Status</title>
</head>

<body>
  <h1>ESP32 Traffic Light</h1>

  <p>Potentiometer ADC value:</p>
  <p id="pot" class="value">Loading...</p>

  <table>
    <tr>
      <th>Channel</th>
      <th>Brightness</th>
    </tr>
    <tr>
      <td>Red</td>
      <td id="red">-</td>
    </tr>
    <tr>
      <td>Amber</td>
      <td id="amber">-</td>
    </tr>
    <tr>
      <td>Green</td>
      <td id="green">-</td>
    </tr>
  </table>

  <script>
    async function updateValues() {
      try {
        const response = await fetch("/values");
        const values = await response.json();

        document.getElementById("pot").textContent = values.pot;
        document.getElementById("red").textContent = values.red;
        document.getElementById("amber").textContent = values.amber;
        document.getElementById("green").textContent = values.green;
      } catch (error) {
        document.getElementById("pot").textContent =
          "Connection lost";
      }
    }

    setInterval(updateValues, 250);
    updateValues();
  </script>
</body>
</html>
)HTML";

  server.send(200, "text/html", page);
}

void sendValues() {
  String json = "{";

  json += "\"pot\":";
  json += pot_val;

  json += ",\"red\":";
  json += red_val;

  json += ",\"amber\":";
  json += amber_val;

  json += ",\"green\":";
  json += green_val;

  json += "}";

  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);

  delay(1000);

  Serial.println("Starting");

  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(POT_PIN, INPUT);

  // Create the private Wi-Fi network.
  bool accessPointStarted = WiFi.softAP(
    AP_NAME,
    AP_PASSWORD
  );

  if (!accessPointStarted) {
    Serial.println("Failed to start Wi-Fi access point.");
    return;
  }

  Serial.println();
  Serial.println("wifi access point started.");
  Serial.print("Network name: ");
  Serial.println(AP_NAME);

  Serial.print("ESP32 IP address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", sendWebPage);
  server.on("/values", sendValues);

  server.begin();

  Serial.println("Web server started.");
  Serial.print("Open ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  updateOutputs();
  server.handleClient();

  delay(5);
}