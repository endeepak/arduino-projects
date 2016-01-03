
int led = 3;
int button = 2;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  int isButtonPressed = digitalRead(button) == LOW;
  int desiredLedState = isButtonPressed ? HIGH : LOW;
  digitalWrite(led, desiredLedState);
}
