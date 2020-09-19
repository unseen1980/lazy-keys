#include <Keyboard.h>
#include <SPI.h>
#include <SD.h>

const int chipSelect = 2;
int inPin1 = 4;
int inPin2 = 7;
int inPin3 = 8;
int inPin4 = 9;
String firstValue = "Hello from first button";
String secondValue = "Hello from second button";
String thirdValue = "Hello from third button";
String forthValue = "Hello from forth button";
String myString;

void valueSeparation(String val) {
  int commaIndex = val.indexOf(',');
  int secondCommaIndex = val.indexOf(',', commaIndex + 1);
  int thirdCommaIndex = val.indexOf(',', secondCommaIndex + 1);
  firstValue = val.substring(0, commaIndex);
  secondValue = val.substring(commaIndex + 1, secondCommaIndex);
  thirdValue = val.substring(secondCommaIndex + 1, thirdCommaIndex);
  forthValue = val.substring(thirdCommaIndex + 1);
  Serial.println(firstValue);
  Serial.println(secondValue);
  Serial.println(thirdValue);
  Serial.println(forthValue);
}

void writeToSD(String dataString) {
  if (SD.exists("buttons.txt")) {
    SD.remove("buttons.txt");
  }
  File dataFile = SD.open("buttons.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
  }
  else {
    Serial.println("error opening datalog.txt");
  }
}

void setup() {
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);
  pinMode(inPin4, INPUT);
  digitalWrite(inPin1, HIGH);
  digitalWrite(inPin2, HIGH);
  digitalWrite(inPin3, HIGH);
  digitalWrite(inPin4, HIGH);
  Serial.begin(9600);
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    while (1);
  }
  Serial.println("card initialized.");

  File myFile;
  myFile = SD.open("buttons.txt");
  if (myFile) {
     // read from the file until there's nothing else in it:
    while (myFile.available()) {
      char ltr = myFile.read();
      myString += ltr;
      Serial.println("SDCard:" + myString);
      valueSeparation(myString);
    }
    myFile.close();
  }
}

void loop() {
  if (Serial.available() > 0)
  {
    myString = Serial.readStringUntil('\n');
    valueSeparation(myString);
    writeToSD(myString);
  }
  if (digitalRead(inPin1) == 0)
  {
    Keyboard.print(firstValue);
    delay(500);
  }
  if (digitalRead(inPin2) == 0)
  {
    Keyboard.print(secondValue);
    delay(500);
  }
  if (digitalRead(inPin3) == 0)
  {
    Keyboard.print(thirdValue);
    delay(500);
  }
  if (digitalRead(inPin4) == 0)
  {
    Keyboard.print(forthValue);
    delay(500);
  }
}
