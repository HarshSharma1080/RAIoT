//in this program we will decrease the brightness of the led slowly and then increase slowly that is fade in and fade out
//we will be using the pin 9 , which is a analog pin, to control the led
/* first the brightness of the led will be zero as defined in the beginning then the fadeamount will be added to the brightness
and the led will glow with the updated brightness, untill the brightness limits reach like 0 and 255, if the limit reaches the sign of the
fademount will be reversed and will be added to the brightness so that it can increase now if it was decreasing before or 
it can decrease now if it was increasing before, in this way it will continue forever untill we make it stop */

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
