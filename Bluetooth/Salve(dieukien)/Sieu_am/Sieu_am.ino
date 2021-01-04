#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);//TX/RX

int trig = 6;
int echo = 5;
void setup()
{
  BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(trig, OUTPUT);// chân trig phát tín hiệu 
  pinMode(echo, INPUT);// chân  acho nhận  tín hiệu
}
void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  //tính toán thời gian
  int duration = pulseIn(echo,HIGH);//  biến lưu khoảng cách. Đo độ rộng xung HIGH ở chân echo.
  float distance = duration * 0.034/2;//tính khoảng cách đến vật
  if(distance < 15)
  {
    //digitalWrite(13,HIGH);
    BTSerial.write('1'); 
  }
  else{
    //digitalWrite(13,LOW);
    BTSerial.write('0'); 
  }
  Serial.println(distance);
 delay(1200);
}
