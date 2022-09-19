// Your Name
// Your Robotics Course Section
// Title (Name of Tutorial/Project)
// Description: Restate the purpose of the program in your own words
// Date Started - Date Completed

int num1, num2, sum, resultant1, resultant2, resultant3;
char answer;

void setup () {
  Serial.begin(9600);
}

void loop () {

  Serial.print("Enter a first number: ");
  while (!Serial.available()) {}
  // “!Serial.available” is equivalent to “Serial.available == 0”
  num1 = Serial.parseInt();
  Serial.println(num1);

  Serial.print("Enter a second number: ");
  while (!Serial.available()) {}
  num2 = Serial.parseInt();
  Serial.println(num2);

  answer = ShouldIAdd(); //call function ShouldIAdd to assign value to “answer”

  if (answer == 'Y') {
    sum = mySumFunction(num1, num2); //call mySumFunction if user wants it!
    Serial.print("Your sum is: ");
    Serial.println(sum);
  } else {
    Serial.println("Thanks for nothing!");
  }

  delay(500);

  answer = ShouldISubtract(); //call function ShouldIAdd to assign value to “answer”

  if (answer == 'Y') {
    resultant1 = mySubtractFunction(num1, num2); //call mySumFunction if user wants it!
    Serial.print("Your result is: ");
    Serial.println(resultant1);
  } else {
    Serial.println("Thanks for nothing!");
  }

  delay(500);

  answer = ShouldIMultiply(); //call function ShouldIAdd to assign value to “answer”

  if (answer == 'Y') {
    resultant2 = myMultiplyFunction(num1, num2); //call mySumFunction if user wants it!
    Serial.print("Your resultant is: ");
    Serial.println(resultant2);
  } else {
    Serial.println("Thanks for nothing!");
  }

  delay(500);

  answer = ShouldIDivide(); //call function ShouldIAdd to assign value to “answer”

  if (answer == 'Y') {
    resultant3 = myDivideFunction(num1, num2); //call mySumFunction if user wants it!
    Serial.print("Your resultant is: ");
    Serial.println(resultant3);
  } else {
    Serial.println("Thanks for nothing!");
  }
  delay(1000);
}

char ShouldIAdd() {      //a return type function with no parameters
  char yesorno;
  Serial.println("Press Y to add your numbers.");
  while (!Serial.available()) {}
  yesorno = Serial.read();

  return yesorno;        //returns a character
}

char ShouldISubtract() {      //a return type function with no parameters
  char yesorno2;
  Serial.println("Press Y to subtract your numbers.");
  while (!Serial.available()) {}
  yesorno2 = Serial.read();

  return yesorno2;        //returns a character
}

char ShouldIMultiply() {      //a return type function with no parameters
  char yesorno3;
  Serial.println("Press Y to multiply your numbers.");
  while (!Serial.available()) {}
  yesorno3 = Serial.read();

  return yesorno3;        //returns a character
}

char ShouldIDivide() {      //a return type function with no parameters
  char yesorno4;
  Serial.println("Press Y to divide your numbers.");
  while (!Serial.available()) {}
  yesorno4 = Serial.read();

  return yesorno4;        //returns a character
}

int mySumFunction(int x, int y) {    //a return type function with two parameters
  int result;
  result = x + y;
  return result;         //returns an integer
}

int mySubtractFunction(int x, int y) {    //a return type function with two parameters
  int result;
  result = x - y;
  return result;         //returns an integer
}

int myMultiplyFunction(int x, int y) {    //a return type function with two parameters
  int result;
  result = x * y;
  return result;         //returns an integer
}

int myDivideFunction(int x, int y) {    //a return type function with two parameters
  int result;
  result = x / y;
  return result;         //returns an integer
}
