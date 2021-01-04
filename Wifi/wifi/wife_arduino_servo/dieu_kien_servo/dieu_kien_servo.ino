#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo; 

const int ServoPin = 9;
SoftwareSerial ss (10, 11);

void setup() {
  Serial.begin(9600);
  ss.begin(9600);
  myservo.attach(ServoPin);
}
int pos = 0;

uint8_t getPin(String pinName) {
  return pinName.substring(1).toInt();
}

void loop() {
  String data = "";
  while (ss.available()) {
    data += ((char)ss.read());
    if (data.endsWith("\r\n")) break;
  }
  if (data != "") {
    Serial.println(data);
    String pinName = data.substring(0, data.indexOf(' '));
    int val = data.substring(data.indexOf(' ')+1, data.indexOf("\r\n")).toInt();
    
    pinMode(getPin(pinName), OUTPUT); // set pin ở OUTPUT trước khi viết
    if (val ==  1) {
      for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);              
    delay(15);}
    }
    else {
       }
    ss.flush();
  }
  delay(10);
}
