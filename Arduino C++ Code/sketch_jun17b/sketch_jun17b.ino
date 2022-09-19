void setup()
{
  for (int i = 3; i < 11; i = i + 1) {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  digitalWrite(11, LOW);
}
