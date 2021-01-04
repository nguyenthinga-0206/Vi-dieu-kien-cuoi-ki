
/* Đongị cơ ĐC : 
 *    + in 3 nối với pin 8
 *    + in4 nối với pin9
 *    + enB nối với pin 5
 *  WIFE:
 *    + D1 nối với pin 11
 *    + D2 nối với pin 10
 *    + GND nối với  âm trong bo mạch
 * 
 */
#include <SoftwareSerial.h>
int enB =5;
int in3= 8; 
int in4 =9;
SoftwareSerial ss (10, 11);
void setup() {
  Serial.begin(9600);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
 
  ss.begin(9600);
}

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
    int val = data.substring(data.indexOf(' '), data.indexOf("\r\n")).toInt();
    
    pinMode(getPin(pinName), OUTPUT); // set pin ở OUTPUT trước khi viết
    if (val == 1) {
     digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);
     digitalWrite(enB, 5);
     delay (1000);
    }
    else {
     digitalWrite(in3, HIGH);
     digitalWrite(in4, HIGH);
     digitalWrite(enB, 5);
    }
    ss.flush();
  }
 
}
