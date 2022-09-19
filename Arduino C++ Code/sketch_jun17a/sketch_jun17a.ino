int potentPin = A3, potentRead, brightness;

void setup() {
  pinMode(potentPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //set potentRead to values inputted from potentiometer
  potentRead = analogRead(potentPin);

 //convert potentiometer reading range 0-1023 to approx. voltage 0-5V.
  brightness = map(potentRead, 0, 1023, 0, 255);

  analogWrite(9, brightness);
}
