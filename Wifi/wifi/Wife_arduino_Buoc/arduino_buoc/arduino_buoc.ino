#include <SoftwareSerial.h>
//#include<Servo.h>
/*Servo myservo;
const int enA = 5; // chân digital có dấu ~
const int in3 = 3;
const int in4 = 4;*/
#include <Stepper.h>
const int stepsPerRevolution = 2048;
// Số trên là hằng số với mỗi loại Stepper Motor.

Stepper myStepper = Stepper(stepsPerRevolution, 6, 8, 7, 9); 

SoftwareSerial ss (10, 11);

void setup() {
  myStepper.setSpeed(10);
  Serial.begin(9600);
  ss.begin(9600);
}

uint8_t getPin(String pinName) {
  return pinName.substring(1).toInt();
}

void loop() {
  int pos = 0;
  int ServoPin;
  String data = "";
  while (ss.available()) {
    data += ((char)ss.read());
    if (data.endsWith("\r\n")) break;
  }
  if (data != "") {
    Serial.println(data);
    String pinName = data.substring(0, data.indexOf(' '));
    int val = data.substring(data.indexOf(' ')+1, data.indexOf("\r\n")).toInt();
    if(pinName == "D13"){
    }
    if (val == 1)
    {
      Serial.println("clockwise");
      myStepper.step(stepsPerRevolution);
      delay(1000);  
    }
    else {
      Serial.println("counterclockwise");
      myStepper.step(-stepsPerRevolution);
      delay(1000);
    }
    }
    ss.flush();
  delay(10);
}
