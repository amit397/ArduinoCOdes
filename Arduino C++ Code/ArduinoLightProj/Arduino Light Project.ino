const int slidePin = A3;  
const int micPin = A2;
const float thermalAlert = 80.0;
const int temperaturePin = A0;  
const int redLEDPin = 9;    
const int greenLEDPin = 11;
const int ledPins[5] = {4, 5, 6, 7, 8};
const int nightlightBegin = 255;
int sensorValue;
int sensor = 0;
void setup()
{ 
    pinMode(slidePin, INPUT);
    pinMode(A3, INPUT);
    pinMode(A1, INPUT);
  pinMode(micPin, INPUT);
    pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
    pinMode(12, INPUT);
    pinMode(2, INPUT);
    for (int i=4; i<12; i++)
  {
      pinMode(i, OUTPUT);
    }
    Serial.begin(9600);
    Serial.print("Welcome, to start the lights for each sensor flick D2 on. To pick your prefered sensor click D12.");
}

void loop()
{ 
    if ( digitalRead(2) == LOW)
    {
      for (int i=4; i<12; i++)    //This for loop is at the beginning of every sensor to turn off all other lights
      {
          digitalWrite(i, LOW);   
        }
    }
    if (digitalRead(12) == HIGH)
    {
        sensor++;
    }
    if (sensor > 4)
    {
        sensor = 1;
    }
    if (sensor == 1)           // Temperature
    {
      Serial.print("Sensor Value: ");
      Serial.print(sensor);
        Serial.print(" the Temperature Sensor.");
        Serial.println(" Move up and down the thermometer to change the lighting");
        if ( digitalRead(2) == HIGH)
      {
          for (int i=4; i<12; i++)
      {
          digitalWrite(i, LOW);
        }
      
            long rawTemp = analogRead(temperaturePin);  //Changes the light from red to blue based on whether it is hot or cold
        float voltage = rawTemp * (5 / 1023.0);
  
  
    float celsius = (voltage - 0.5) * 100;  
  
  
    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        
  
    if (fahrenheit >= thermalAlert)
      {
        digitalWrite(redLEDPin, HIGH);
        digitalWrite(greenLEDPin, LOW);
      }
    else
      {
        digitalWrite(redLEDPin, LOW);
        digitalWrite(greenLEDPin, HIGH);
      }
        }
    }
    if (sensor == 2)         // Microphone
    {
        Serial.print("Sensor Value: ");
      Serial.print(sensor);
        Serial.print(" the Mic Sensor.");
        Serial.println(" Move the potentiometer to change the sensitivity of the mic");
        if ( digitalRead(2) == HIGH)
  {
        for (int i=4; i<12; i++)
    {
        digitalWrite(i, LOW);
        }
        
        int maximum = analogRead(slidePin); 
    int micReading = analogRead(micPin);  
  
  
    for (int i=0; i<5; i++)   // depending on the potentiometer and mic readings it changes which lights are on
    {
      if (micReading > ((maximum / 5) * (i+1)))
      { 
        digitalWrite(ledPins[i], HIGH); 
      }
      else
      { 
        digitalWrite(ledPins[i], LOW);
      }
        }
  }
    }
      if (sensor == 3)      // Light    
    {
      Serial.print("Sensor Value: ");
      Serial.print(sensor);
        Serial.print(" the Light Sensor.");
    Serial.println(" Move your cursor over A1 to change the light.");
        if ( digitalRead(2) == HIGH)
  {
        for (int i=4; i<12; i++)
    {
        digitalWrite(i, LOW);
      }
        
    int lightValue = analogRead(A1);    //changes how bright the light is based on how bright the light is
  
  
    Serial.println(lightValue);
  
  
    if (lightValue <= nightlightBegin)  
    {
      int brightness=255-lightValue;
      analogWrite(9, brightness); 
      analogWrite(10, brightness);  
    }
    else          
    {
      analogWrite(9, LOW);  
      analogWrite(10, LOW); 
      }
  
    delay(100); 
  
  }
      }
    if (sensor == 4)      // Potentiometer
    {
      Serial.print("Sensor Value: ");
      Serial.print(sensor);
        Serial.print(" the Potentiometer Sensor.");
    Serial.println(" Move the potentiometer to change the lights.");
        if ( digitalRead(2) == HIGH)
  {
        for (int i=4; i<12; i++)
    {
        digitalWrite(i, LOW);
      }
        sensorValue = analogRead(A3);
      if (sensorValue < 204)      //Depending on the value of the potentiometer it is going to change which lights are on
      {
          digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
      }

      if (sensorValue > 204 && sensorValue < 408)
      {
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          digitalWrite(6, LOW);
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
      }

      if (sensorValue > 408 && sensorValue < 612)
      {
          digitalWrite(4, LOW);
          digitalWrite(5, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
      }

      if (sensorValue > 612 && sensorValue < 816)
      {
          digitalWrite(4, LOW);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);
      }
    
      if (sensorValue > 816)
      {
          digitalWrite(4, LOW);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, LOW);
          digitalWrite(8, HIGH);
      }
      delay(100);    
    }
  
    }
   
}
