// Set up pins for Ultrasonic Sensor
const int trigPin = 9;  // TRIG pin sends the signal
const int echoPin = 10; // ECHO pin receives the signal

// Variable to store distance
long duration;  // Time it takes for the signal to go and come back
int distance;   // Distance calculated in centimeters

void setup() {
  // Begin serial communication to see results on the computer
  Serial.begin(9600);

  // Set trigPin as OUTPUT (to send the signal)
  pinMode(trigPin, OUTPUT);
  
  // Set echoPin as INPUT (to receive the signal)
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a short pulse to trigger the sensor
  digitalWrite(trigPin, LOW); // Ensure trigger pin is LOW for 2 microseconds
  delayMicroseconds(2);       // Small delay
  digitalWrite(trigPin, HIGH); // Trigger the sensor by sending a HIGH signal for 10 microseconds
  delayMicroseconds(10);       // Wait for 10 microseconds
  digitalWrite(trigPin, LOW);  // Set trigger pin LOW again

  // Measure the time it takes for the echo to come back
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the time duration
  // Use the formula: Distance = (Time x Speed of Sound) / 2
  // Speed of sound in air is 0.0343 cm/microsecond
  distance = duration * 0.0343 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait for half a second before measuring again
  delay(500);
}
