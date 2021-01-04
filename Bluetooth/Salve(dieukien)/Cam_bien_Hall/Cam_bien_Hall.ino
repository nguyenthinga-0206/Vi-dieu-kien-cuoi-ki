#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);//TX/RX

int hall= 6;
void setup()
{
  BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(hall, INPUT);
}
void loop()
{
  int value = digitalRead(hall);
  Serial.println(value);
  if(value == 1)
  {
    //digitalWrite(13,HIGH);
    BTSerial.write('1'); 
  }
  else{
    //digitalWrite(13,LOW);
    BTSerial.write('0'); 
  }
 delay(1200);
}
