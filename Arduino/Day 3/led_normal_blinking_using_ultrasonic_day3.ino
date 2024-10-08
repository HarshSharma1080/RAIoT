#define TRIG_PIN 9    // TRIG connected to digital pin 9
#define ECHO_PIN 10   // ECHO connected to digital pin 10
#define LED_PIN 7     // LED connected to digital pin 6 (PWM pin)

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set TRIG_PIN as output, ECHO_PIN as input, and LED_PIN as output
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Clear the TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by setting the TRIG_PIN high for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the duration of the pulse from ECHO_PIN
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance (in cm)
  float distance = duration * 0.0343 / 2;

  // Map the distance to the brightness value (0-255)
  // Assuming the max range we care about is 100 cm (adjust as needed)
  int brightness = map(distance, 0, 100, 255, 0); // closer = brighter

  // Limit the brightness to the 0-255 range
  brightness = constrain(brightness, 0, 255);

  // Set LED brightness
  analogWrite(LED_PIN, brightness);

  // Print the distance and brightness value to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Brightness: ");
  Serial.println(brightness);

  // Small delay before the next reading
  delay(100);
}
