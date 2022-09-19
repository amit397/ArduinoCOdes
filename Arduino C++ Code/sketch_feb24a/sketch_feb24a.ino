// Amit Howlader
// Sec 41
// Tutorial 2.7
// Description: Restate the purpose of the program in your own words
// Date Started - Date Completed

//these variables identify the frequency of each note in a c major scale
int c = 262, d = 294, e = 330, f = 349;
int g = 392, a = 440, b = 494, C = 523;

//assigning the buzzer to PWM pin 9
const int passBuzzer = 9;

//array to hold the notes we want the buzzer to play
//notice that the array type is int, because each variable is holding an integer
int melody1[] = {c, c, g, g, a, a, a, a, g, f, f, e, e, d, d, c, g, g, g, f, f, e, e, e, d, c, g, g, g, f, f, f, f, e, e, e, d, c, c, g, g, a, a, a, a, g, f, f, e, e, d, d, c};
int melody[] = {c, c, g, g, a, a, g, 0, f, f, e, e, d, d, c};

void setup() {
  pinMode(passBuzzer, OUTPUT);  //designates the active buzzer pin as output
}

void loop() {
  buzzer(15, 600, 300);                  //delay before the song restarts
  buzzer2(53, 600, 300);
}

void buzzer(int frequency, int delay1, int delay2) {
  for (int i = 0; i < frequency; i++) { //15 will be how many notes total in the melody
    tone(passBuzzer, melody[i]);
    delay(delay1);                   //this is the tone "ON" time
    noTone(passBuzzer);
    delay(delay2);                   //this is the time between tones
  }
  delay(3000);
}
void buzzer2(int frequency, int delay1, int delay2) {
  for (int i = 0; i < frequency; i++) { //15 will be how many notes total in the melody
    tone(passBuzzer, melody1[i]);
    delay(delay1);                   //this is the tone "ON" time
    noTone(passBuzzer);
    delay(delay2);                   //this is the time between tones
  }
  delay(3000);
}
