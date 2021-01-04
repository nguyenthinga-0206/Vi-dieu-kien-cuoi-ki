/*
 - Cam biến ánh sáng:
    + VCC vối 5V
    + Chân giữa nối GND
    + D0 nối A0
 - Đầu phát:
    + Đèn hồng ngoại nối như đèn bt
*/
#include<IRremote.h>
IRsend irsend;
int cambien=A0;
int led =13;
int value=0;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(led,OUTPUT);
  pinMode(cambien,INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  
value = analogRead(cambien);
Serial.println(value);
if(value<1000)
{
  irsend.sendRC5(0,10);
  digitalWrite(led,LOW);
}
else{
  irsend.sendRC5(1,10);
   digitalWrite(led,HIGH);
}
delay(50);

}
