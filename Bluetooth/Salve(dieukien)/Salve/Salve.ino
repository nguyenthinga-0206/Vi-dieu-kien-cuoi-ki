/*
 - TXD nối với pin10
 - RXD nối Pin 11
 - EN nối PIN9
 */
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);//TX,RX

void setup() {
  Serial.begin(9600);
  Serial.println("Enter your commands:");
  BTSerial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available())
    Serial.write(BTSerial.read());

  if(Serial.available())
    BTSerial.write(Serial.read());
}
