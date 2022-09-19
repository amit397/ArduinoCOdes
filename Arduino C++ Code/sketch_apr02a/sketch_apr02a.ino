// Amit Howlader
// Sec 41
// Tutorial 2.7
// Description: Restate the purpose of the program in your own words
// Date Started - Date Completed

String color;
int color2;
int blinks;
int buttonPin = 2;
int buttonPress;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonPress = digitalRead(buttonPin);
  if (buttonPress == HIGH) {
    Serial.println("What color do you want?");
    while (Serial.available() == 0) { };
    color = Serial.readString();      //readString function collects user’s name

    Serial.println("How many times do you want it to blink?");
    while (Serial.available() == 0) { };
    blinks = Serial.parseInt();             //parseInt function collects user’s age

    if (color == "red" || color == "green" || color == "blue") {
      if (color == "red") {
        color2 = 9;
        for (int i = 0; i < blinks; i++) {
          analogWrite(color2, 255);
          delay(250);
          digitalWrite(color2, LOW);
          delay(250);
        }
      }

      if (color == "green") {
        color2 = 10;
        for (int i = 0; i < blinks; i++) {
          analogWrite(color2, 255);
          delay(250);
          digitalWrite(color2, LOW);
          delay(250);
        }
      }

      if (color == "blue") {
        color2 = 11;
        for (int i = 0; i < blinks; i++) {
          analogWrite(color2, 255);
          delay(250);
          digitalWrite(color2, LOW);
          delay(250);
        }
      } else {
        Serial.println("We only have red green and blue");
      }

    }
  }
}
