#define PUSH_BUTTON 5
#define EXTERNAL_LED 6

bool useInternalLED = true;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(PUSH_BUTTON, INPUT_PULLUP);
  pinMode(EXTERNAL_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(PUSH_BUTTON) == LOW) {
    Serial.printf("Switch has been pressed \n");
    useInternalLED = !useInternalLED;
    delay(1000);
  }

  if (useInternalLED) {
    Serial.printf("Setting LED high\n");
    digitalWrite(EXTERNAL_LED, HIGH);
    delay(500);

    Serial.printf("Setting LED low\n");
    digitalWrite(EXTERNAL_LED, LOW);
    delay(500);
  }
}