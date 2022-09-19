// Your Name
// Your Robotics Course Section
// Title (Name of Tutorial/Project)
// Description: Restate the purpose of the program in your own words
// Date Started - Date Completed

const int SLA = 2, SLB = 3, SLC = 4, SLD = 5, SLE = 6, SLF = 7, SLG = 8;
int timedelay = 1000;
int num1, num2;

void setup() {
  for (int pin = 2; pin < 9; pin++) {
    pinMode(pin, OUTPUT);
  }
  Serial.begin(9600);
}
void writeSevenSeg(int aVal, int bVal, int cVal, int dVal, int eVal, int fVal, int gVal) {
  digitalWrite(SLA, aVal);
  digitalWrite(SLB, bVal);
  digitalWrite(SLC, cVal);
  digitalWrite(SLD, dVal);
  digitalWrite(SLE, eVal);
  digitalWrite(SLF, fVal);
  digitalWrite(SLG, gVal);
}

void Zero() {
  writeSevenSeg(1, 1, 1, 1, 1, 1, 0);
}

void One() {
  writeSevenSeg(0, 1, 1, 0, 0, 0, 0);
}

void Two() {
  writeSevenSeg(1, 1, 0, 1, 1, 0, 1);
}

void Three() {
  writeSevenSeg(1, 1, 1, 1, 0, 0, 1);
}

void Four() {
  writeSevenSeg(0, 1, 1, 0, 0, 1, 1);
}

void Five() {
  writeSevenSeg(1, 0, 1, 1, 0, 1, 1);
}

void Six() {
  writeSevenSeg(1, 0, 1, 1, 1, 1, 1);
}

void Seven() {
  writeSevenSeg(1, 1, 1, 0, 0, 0, 0);
}

void Eight() {
  writeSevenSeg(1, 1, 1, 1, 1, 1, 1);
}

void Nine() {
  writeSevenSeg(1, 1, 1, 0, 0, 1, 1);
}

void loop() {

  Serial.print("Enter a first number: ");
  while (!Serial.available()) {}
  num1 = Serial.parseInt();
  Serial.println(num1);
  for (int i = 0; i <= num1; i++) {
    switch (i) {
        if (num1 == 0) {
        case 0:
          {
            Zero();
            delay(timedelay);
            break;
          }

          if (num1 == 1) {
          case 1:
            {
              One();
              delay(timedelay);
              break;
            }


          } if (num1 == 2) {
          case 2:
            {
              Two();
              delay(timedelay);
              break;
            }

          }

        } if (num1 == 3) {
        case 3:
          {
            Three();
            delay(timedelay);
            break;
          }

        } if (num1 == 4) {
        case 4:
          {
            Four();
            delay(timedelay);
            break;
          }

        } if (num1 == 5) {
        case 5:
          {
            Five();
            delay(timedelay);
            break;
          }

        } if (num1 == 6) {
        case 6:
          {
            Six();
            delay(timedelay);
            break;
          }

        } if (num1 == 7) {
        case 7:
          {
            Seven();
            delay(timedelay);
            break;
          }

        } if (num1 == 8) {
        case 8:
          {
            Eight();
            delay(timedelay);
            break;
          }

        } if (num1 == 9) {
        case 9:
          {
            Nine();
            delay(timedelay);
            break;
          }
        }
      default:
        {
          break;
        }


    }

  }
}
