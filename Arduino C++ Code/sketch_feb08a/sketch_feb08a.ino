// Amit Howlader
// Section 41
// Tutorial 2.4
// Description: Use Void type Functions
// 2/8/21

const int LED1 = 3;
const int LED2 = 5;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  sequence1(25);
  delay(1000);
  sequence2(100);
  delay(1000);
  sequence3(100, 0);
}

void sequence1(int delay) {
  blinkLed(LED1, delay);
  blinkLed(LED1, delay + 100);
  blinkLed(LED1, delay + 200);
  blinkLed(LED2, delay + 300);
  blinkLed(LED2, delay + 400);
}

void sequence2(int delay) {
  blinkLed(LED2, delay);
  blinkLed(LED2, delay + 100);
  blinkLed(LED2, delay + 200);
  blinkLed(LED1, delay + 300);
  blinkLed(LED1, delay + 400);
}

void sequence3(int delay, int brightness) {
  blinkLed2(LED2, delay, brightness);
  blinkLed2(LED2, delay + 100, brightness + 100);
  blinkLed2(LED2, delay + 150, brightness + 100);
  blinkLed2(LED1, delay + 150, brightness - 100);
  blinkLed2(LED1, delay + 150, brightness - 100);
}

void blinkLed2(int led, int delayTime, int brightness) {
  digitalWrite(led, brightness);
  delay(delayTime);
  digitalWrite(led, brightness);
  delay(delayTime);
}

void blinkLed(int led, int delayTime) {
  digitalWrite(led, HIGH);
  delay(delayTime);
  digitalWrite(led, LOW);
  delay(delayTime);
}
