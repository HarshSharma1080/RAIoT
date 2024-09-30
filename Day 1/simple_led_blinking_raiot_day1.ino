//This is a very simple led blinking program in which we will blink the led using arduino uno 
//we will turn it on for 1 second and the turn off for next 1 second and this will continue in the loop
// the setup function runs once when you press reset or power the board
// the led is controlled using the pin 10 which is a digital pin in arduino uno

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(10, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
