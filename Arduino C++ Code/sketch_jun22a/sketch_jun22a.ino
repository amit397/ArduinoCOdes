void setup()
{
  for (int i = 5; i < 12; i = i + 1) {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for (int i = 5; i < 12; i = i + 1) {
    digitalWrite(i, LOW);
  }
  digitalWrite(11, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(6, HIGH);
  for (int i = 5; i < 12; i = i + 1) {
    digitalWrite(i, LOW);
  }
  digitalWrite(7, HIGH);
 for (int i = 5; i < 12; i = i + 1) {
    digitalWrite(i, LOW);
  }
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  for (int i = 5; i < 12; i = i + 1) {
    digitalWrite(i, LOW);
  }
  digitalWrite(5, HIGH);
  digitalWrite(9, HIGH);
  for (int i = 5; i < 12; i = i + 1) {
    digitalWrite(i, LOW);
  }
  digitalWrite(8, HIGH);
  for (int i = 5; i < 12; i = i + 1) {
    digitalWrite(i, LOW);
  }
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  for (int i = 5; i < 12; i = i + 1) {
    digitalWrite(i, LOW);
  }
  digitalWrite(8, HIGH);
  for (int i = 5; i < 12; i = i + 1) {
    digitalWrite(i, LOW);
  }
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(11, HIGH);
}

void reset(){
  for (int i = 5; i < 12; i = i + 1) {
    digitalWrite(i, LOW);
  }
}
