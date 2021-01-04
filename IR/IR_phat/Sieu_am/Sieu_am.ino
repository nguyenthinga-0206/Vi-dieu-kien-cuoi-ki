#include<IRremote.h>
IRsend irsend;
int echo =6;//chân cảm biến siêu âm
int trig= 5;// chân cảm biến 

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);// chân trig phát tín hiệu 
  pinMode(echo,INPUT);// chân  acho nhận  tín hiệu
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  //tính toán thời gian
  int duration = pulseIn(echo,HIGH);//  biến lưu khoảng cách//​// Đo độ rộng xung HIGH ở chân echo.
  float distance = duration * 0.034/2;//tính khoảng cách đến vật
  if(distance>15){
    irsend.sendRC5(0,8);
  }
  else
  {
    irsend.sendRC5(1,8);
  }
  Serial.println(distance);
  delay(100);
  
  
}
