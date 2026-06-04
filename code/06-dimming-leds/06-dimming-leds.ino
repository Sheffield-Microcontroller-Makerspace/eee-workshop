#define RED_LED 5
#define AMBER_LED 6
#define GREEN_LED 9

int red_val = 0;
int amber_val = 0;
int green_val = 0;

#define POT_PIN A3

int pot_val = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  pot_val = analogRead(POT_PIN);

  Serial.printf("Potentiometer Resistance: %d \n", pot_val);
  delay(50);

  pot_val = (pot_val * 255) / 4095;

  Serial.printf("Potentiometer Normalised Value: %d \n", pot_val);

  analogWrite(RED_LED, pot_val);
  analogWrite(AMBER_LED, pot_val);
  analogWrite(GREEN_LED, pot_val);
}