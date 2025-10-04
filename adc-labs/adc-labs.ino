// This function is used to initialize the various hardware that will be used
// in the code. It is only called once.
void setup() {
  // Set the LED_BUILTIN as an output so we may control it. The way this pin is
  // connected to the LED, if we put a HIGH on the pin, it will turn on the LED
  // while a LOW will turn off the LED.
  pinMode(LED_BUILTIN, OUTPUT);
}

// This function is where the actual application code resides. It will run thru
// the code to the bottom and then start back over from the top forever.
void loop() {
  // Turn on the LED
  digitalWrite(LED_BUILTIN, HIGH);

  // Wait for about 500 milli-seconds
  delay(250);

  // Turn off the LED
  digitalWrite(LED_BUILTIN, LOW);

  // Wait for about 500 milli-seconds
  delay(250);
}
