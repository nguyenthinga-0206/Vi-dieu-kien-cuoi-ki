/*
 - Công tắc trượt:
    + 2 chân ngoài 1 cái nối VCC 1 cái nối GND
    + Chân giữa nối Pin2
 */

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);

int ct= 2;
int value;
void setup()
{
  pinMode(ct, INPUT);
  BTSerial.begin(9600);
  value = digitalRead(ct);
  Serial.begin(9600);
}
void loop()
{
  int value1 = digitalRead(ct);
  if(value != value1)
  {
    //digitalWrite(13,HIGH);
    BTSerial.write('1'); 
  }
  else{
    //digitalWrite(13,LOW);
    BTSerial.write('0'); 
  }
  //delay(500); 
}
