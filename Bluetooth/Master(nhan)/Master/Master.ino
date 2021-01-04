/*
 - TXD nối với pin10
 - RXD nối Pin 11
 - EN nối PIN9
 */
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);//RX,TX

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Serial.begin(9600);
  Serial.println("Arduino is ready");
  Serial.println("Remember to select Both NL7 CR in the the serial monitor");
  BTSerial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available())
    Serial.write(BTSerial.read());

  if(Serial.available())
    BTSerial.write(Serial.read());

}
