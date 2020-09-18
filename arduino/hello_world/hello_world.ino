#include <Keyboard.h>

int inPin = 7;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status

void setup() {
  pinMode(inPin, INPUT);    // declare pushbutton as input
    digitalWrite(inPin, HIGH);  // Pull the button high

  Serial.begin(9600);

}

void loop() {
  val = digitalRead(inPin);  // read input value
  Serial.println(val);
  if (digitalRead(inPin) == 0)  // if the button goes low
  {
    Keyboard.print("Hello world!");  // send a 'z' to the computer via Keyboard HID
    delay(500);  // delay so there aren't a kajillion z's
  }
}
