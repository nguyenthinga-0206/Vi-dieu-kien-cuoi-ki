/*
 * chân 5v nối  với chân  vin
 * chân  12v nối  với chân 5v
 * chân in3 nối  chân số 6. in4 nối  với chân  số  7
 * en nối  với  chân  số   5
 * 
 */
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);
int enA =5;//chân  động  cơ
int in3=6;
int in4=7;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(enA,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void loop() 
{
  if (BTSerial.available()) {
    //đọc  giá trị  truyền
    int input=BTSerial.read();
    Serial.write(input);
    if (input == '0')
    {
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);    
    }
    else 
    {
       digitalWrite(in3,LOW);
       digitalWrite(in4,HIGH);
       //tốc  độ  động  cơ 
    analogWrite(enA,225);
    }
  }
}
