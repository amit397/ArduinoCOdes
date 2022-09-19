String questions[3] = {"How many inches are in a foot?", "What is the tallest building in the world?", "Where was Kanye?"};
String answers[3] = {"6", "Burj Khalifa", "Paris"};       // Two arrays for the questions and answers
String answer;
const int Buzzer = 5;
int pause = 10;
int c = 262, d = 294, e = 330, f = 349;        // Setup for the jingle
int g = 392, a = 440, b = 494, C = 523;
int z = 150, y = 100;
int rightmelody[] = {d, d, a};
int wrongmelody[] = {z, z, y};
int score = 0;                                  // Variable to keep track of questions answered right
int redLED = 9, greenLED = 10, blueLED = 11;     // setup for the diff components on the breadboard
int buttonPress;
int buttonPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  buttonPress = digitalRead(buttonPin);
  if (buttonPress == HIGH) {
    for (int i = 0; i < 3; i++) {                     // Loop for asking and checking the questions
      Serial.println(questions[i]);
      while (Serial.available() == 0) { };
      answer = Serial.readString();
      if (answer == answers[i]) {            //checks answer
        analogWrite(greenLED, 255);
        rightBuzzer(100);                  // part that deals with what to do if answer is right
        delay(500);
        analogWrite(greenLED, 0);
        Serial.println("Correct!");
        score = score + 1;
        Serial.println("Score: " + String(score));
        delay(150);
      } else {
        analogWrite(redLED, 255);          // what to do if answer is wrong
        wrongBuzzer(100);
        delay(500);
        analogWrite(redLED, 0);
        Serial.println("Wrong answer!");
        delay(1000);
      }
    }
    if (score == 3) {                                    // if everything is right this happens
      analogWrite(blueLED, 255);
      Serial.println("You got everything right! Press the button if you want to keep playing");
      score = 0;
      delay(5000);
      analogWrite(blueLED, 0);
    } else {                                    // if everything is right this happens
      analogWrite(blueLED, 255);
      analogWrite(redLED, 255);
      Serial.println("You got " + String(score) + " right, try again for a 100 :^)");
      score = 0;
      delay(5000);
      analogWrite(blueLED, 0);
      analogWrite(redLED, 0);
    }
  }
}
void rightBuzzer(int delay1) {
  for (int i = 0; i < 3; i++) {             // jingle for when answer is right
    tone(Buzzer, rightmelody[i]);
    delay(125);
    noTone(Buzzer);
    delay(delay1);
  }
}
void wrongBuzzer(int delay1) {
  for (int i = 0; i < 3; i++) {           // jingle for when answer is wrong
    tone(Buzzer, wrongmelody[i]);
    delay(125);
    noTone(Buzzer);
    delay(delay1);
  }
}
