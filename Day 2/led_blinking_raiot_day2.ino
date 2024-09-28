// Define the pin numbers for the LEDs
int led1 = 2;  // LED 1 connected to pin 2
int led2 = 3;  // LED 2 connected to pin 3
// int led3 = 4;  // LED 3 connected to pin 4

// Set a delay time in milliseconds
int delayTime = 500;  // 500ms = 0.5 second delay between LEDs

void setup() {
  // Set the LED pins as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // pinMode(led3, OUTPUT);
}

void loop() {
  // Turn on LED 1, then off
  digitalWrite(led1, HIGH);
  delay(delayTime);
  digitalWrite(led1, LOW);

  // Turn on LED 2, then off
  digitalWrite(led2, HIGH);
  delay(delayTime);
  digitalWrite(led2, LOW);

  // Turn on LED 3, then off
  // digitalWrite(led3, HIGH);
  // delay(delayTime);
  // digitalWrite(led3, LOW);
}