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


void setup() {
  pinMode(inPin1, INPUT);    // declare pushbutton as input
  pinMode(inPin2, INPUT);    // declare pushbutton as input
  pinMode(inPin3, INPUT);    // declare pushbutton as input
  pinMode(inPin4, INPUT);    // declare pushbutton as input
  digitalWrite(inPin1, HIGH);  // Pull the button high
  digitalWrite(inPin2, HIGH);  // Pull the button high
  digitalWrite(inPin3, HIGH);  // Pull the button high
  digitalWrite(inPin4, HIGH);  // Pull the button high
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void loop() {
  if (Serial.available() > 0)
  {
    String myString = Serial.readStringUntil('\n');
    String dataString = myString;

    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    File dataFile = SD.open("buttons.txt", FILE_WRITE);

    // if the file is available, write to it:
    if (dataFile) {
      dataFile.println(dataString);
      dataFile.close();
    }
    // if the file isn't open, pop up an error:
    else {
      Serial.println("error opening datalog.txt");
    }


    int commaIndex = myString.indexOf(',');
    int secondCommaIndex = myString.indexOf(',', commaIndex + 1);
    int thirdCommaIndex = myString.indexOf(',', secondCommaIndex + 1);
    firstValue = myString.substring(0, commaIndex);
    secondValue = myString.substring(commaIndex + 1, secondCommaIndex);
    thirdValue = myString.substring(secondCommaIndex + 1, thirdCommaIndex);
    forthValue = myString.substring(thirdCommaIndex + 1);
    Serial.println(firstValue);
    Serial.println(secondValue);
    Serial.println(thirdValue);
    Serial.println(forthValue);
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
