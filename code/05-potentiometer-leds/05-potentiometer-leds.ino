#define RED_LED 5
#define AMBER_LED 6
#define GREEN_LED 9

#define POT_PIN A3

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int pot_val = analogRead(POT_PIN);

  Serial.printf("%d \n", pot_val);
  delay(200);

  if (pot_val < 1365) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(AMBER_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  } else if (pot_val < 2730) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(AMBER_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(AMBER_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }
}