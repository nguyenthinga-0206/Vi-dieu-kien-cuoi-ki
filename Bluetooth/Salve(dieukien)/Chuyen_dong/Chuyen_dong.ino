#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);//TX/RX

int chuyendong= 6;
void setup()
{
  pinMode(chuyendong,INPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}
void loop()
{
  int value = digitalRead(chuyendong);
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
