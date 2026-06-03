#define EXTERNAL_LED 6

void setup() {
  // put your setup code here, to run once:
  pinMode(EXTERNAL_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Setting the output pin for the LED to HIGH (turning it on)\n");
  digitalWrite(EXTERNAL_LED, HIGH);
  delay(500); // Pausing for 500ms

  Serial.printf("Setting the output pin for the LED to LOW (turning it off)\n");
  digitalWrite(EXTERNAL_LED, LOW);
  delay(500); // Pausing for 500ms
}