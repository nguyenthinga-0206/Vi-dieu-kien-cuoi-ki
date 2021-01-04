#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);//TX/RX

int do_line= 6;//Chân OUT của Do line
void setup()
{
  pinMode(do_line,INPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}
void loop()
{
  int value = digitalRead(do_line);
  Serial.println(value);
  if(value==0)
  {
    //digitalWrite(13,HIGH);
    BTSerial.write('1'); 
  }
  else{
    //digitalWrite(13,LOW);
    BTSerial.write('0'); 
  }
 delay(1000);
}
