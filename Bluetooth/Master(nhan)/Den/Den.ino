#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (BTSerial.available()) {
    char input=BTSerial.read();
    Serial.write(input);
    if (input == '1') digitalWrite(13, HIGH);
    if (input == '0') digitalWrite(13, LOW);
  }
}
