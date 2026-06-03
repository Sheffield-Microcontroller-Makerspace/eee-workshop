#define PUSH_BUTTON 5
#define RED_LED 6
#define AMBER_LED 9
#define GREEN_LED 10

bool useInternalLED = true;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(PUSH_BUTTON, INPUT_PULLUP);

  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(PUSH_BUTTON) == LOW) {
    Serial.printf("Switch has been pressed \n");
    useInternalLED = !useInternalLED;
    delay(1000);
  }

  if (useInternalLED) {
    Serial.printf("Setting red LED high\n");
    digitalWrite(RED_LED, HIGH);
    delay(1000);

    Serial.printf("Setting amber LED high\n");
    digitalWrite(AMBER_LED, HIGH);
    delay(2000);

    Serial.printf("Setting red LED low\n");
    digitalWrite(RED_LED, LOW);

    Serial.printf("Setting amber LED low\n");
    digitalWrite(AMBER_LED, LOW);

    Serial.printf("Setting green LED high\n");
    digitalWrite(GREEN_LED, HIGH);
    delay(2000);

    Serial.printf("Setting green LED low\n");
    digitalWrite(GREEN_LED, LOW);
    delay(500);

    useInternalLED = ! useInternalLED;
  }
}