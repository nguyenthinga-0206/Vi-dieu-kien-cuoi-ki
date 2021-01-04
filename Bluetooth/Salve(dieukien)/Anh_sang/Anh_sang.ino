#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);//TX/RX

int quang= A0;
void setup()
{
  pinMode(quang,INPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}
void loop()
{
  int value = analogRead(quang);
  Serial.println(value);
  if(value < 700)
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
