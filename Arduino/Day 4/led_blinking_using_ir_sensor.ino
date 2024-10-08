int ledPin = 13;  // LED connected to pin 13
int irSensorPin = 2;  // IR sensor output connected to pin 2
int sensorValue = 0;  // Variable to store the sensor's value

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED as output
  pinMode(irSensorPin, INPUT);  // Set IR sensor as input
  Serial.begin(9600);  // Start serial communication for debugging
}

void loop() {
  sensorValue = digitalRead(irSensorPin);  // Read IR sensor value
  Serial.println(sensorValue);  // Print the sensor value for debugging
  
  if (sensorValue == HIGH) {  // If the sensor detects an object
    digitalWrite(ledPin, LOW);  // Turn the LED on  // Keep it off for 500 ms
  } else {
    digitalWrite(ledPin, HIGH);  // If no object, LED remains off
  }
}
