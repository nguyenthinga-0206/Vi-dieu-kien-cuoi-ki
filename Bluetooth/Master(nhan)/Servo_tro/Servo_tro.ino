/*
 - Servo:
      + Dây đỏ VCC
      + Dây nâu GND
      + Dây cam Pin9
 */
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);//TX?RX
#include <Servo.h>

Servo myservo; 

const int ServoPin = 9;
void setup() 
{
  Serial.begin(9600);
  BTSerial.begin(9600);
  myservo.attach(ServoPin);
}
int pos = 0;
void loop()
{
   if (BTSerial.available()) 
   {
    //đọc  giá trị  truyền
    char input = BTSerial.read();
    Serial.write(input);
    myservo.write(int(input));
   }                    
}
