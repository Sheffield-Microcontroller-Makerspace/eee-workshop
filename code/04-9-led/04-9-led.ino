#define SERIAL_BAUD 115200

int ledPins[] = {
  5,
  6,
  9,
  10,
  11,
  12,
  13,
  18,
  17,
};

int numPins = 9;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(SERIAL_BAUD);

  for(int i = 0; i < numPins; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  delay(300);
}

// the loop function runs over and over again forever
void loop() {
  for(int i = 0; i < numPins; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }

  for(int i = 0; i < numPins; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(100);
  }
}