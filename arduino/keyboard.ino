String a;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    String myString = Serial.readStringUntil('\n');
    int commaIndex = myString.indexOf(',');
    int secondCommaIndex = myString.indexOf(',', commaIndex + 1);
    int thirdCommaIndex = myString.indexOf(',', secondCommaIndex + 1);
    String firstValue = myString.substring(0, commaIndex);
    String secondValue = myString.substring(commaIndex + 1, secondCommaIndex);
    String thirdValue = myString.substring(secondCommaIndex + 1, thirdCommaIndex);
    String forthValue = myString.substring(thirdCommaIndex + 1);
    Serial.println(firstValue);
    Serial.println(secondValue);
    Serial.println(thirdValue);
    Serial.println(forthValue);
  }
}
