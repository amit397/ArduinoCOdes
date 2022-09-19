int redLED = 9, greenLED = 10, blueLED = 11;
int buttonPress;
int buttonPin = 6;
int lightVariable = 9;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  buttonPress = digitalRead(buttonPin);
  /* !!! IMPORTANT !!!
     This code is for common cathode/active high RGB LEDS!
     If you’re using common anode/active low RGB, 0 is ON/HIGH and 255 is OFF/LOW!
     To turn on JUST the red LED, the values should be (0, 255, 255)!
  */
  for (int i = 0; i < 256; i++)
  {
    if (buttonPress == HIGH)  {
      lightVariable = lightVariable + 1;
    }
    if (lightVariable > 11) {
      lightVariable = 9;
    }
    analogWrite(lightVariable, 255 - i);
    delay(100);
  }

}
