int ledPin = 9;       // The pin the LED is connected to
int brightness = 0;   // Brightness level (starts at 0, meaning off)
int fadeAmount = 5;   // How much to increase/decrease brightness by each step

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin to be an output so it can send signals
}

void loop() {
  // Change the brightness of the LED
  analogWrite(ledPin, brightness);  // Set the LED brightness (0 = off, 255 = fully bright)
  
  // Change the brightness for the next time the loop runs
  brightness = brightness + fadeAmount;  // Increase the brightness by 5 each time
  
  // Reverse direction when the brightness reaches the limits (0 or 255)
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;  // Reverse the direction of the fade
  }

  delay(50);  // Pause for a short time (30 milliseconds) before updating the LED again
}